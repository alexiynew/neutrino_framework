#include <algorithm>
#include <array>
#include <cstdint>
#include <exception>
#include <fstream>
#include <functional>
#include <set>
#include <unordered_map>
#include <vector>

#include <common/utils.hpp>
#include <graphics/color.hpp>
#include <graphics/font.hpp>
#include <graphics/mesh.hpp>
#include <log/log.hpp>
#include <math/math.hpp>

#include <graphics/src/font/tables/character_to_glyph_index_mapping.hpp>
#include <graphics/src/font/tables/font_header.hpp>
#include <graphics/src/font/tables/glyph_data.hpp>
#include <graphics/src/font/tables/horizontal_header.hpp>
#include <graphics/src/font/tables/horizontal_metrics.hpp>
#include <graphics/src/font/tables/index_to_location.hpp>
#include <graphics/src/font/tables/maximum_profile.hpp>
#include <graphics/src/font/tables/naming.hpp>
#include <graphics/src/font/tables/os2.hpp>

namespace
{
using namespace framework;
using namespace framework::graphics;
using namespace framework::graphics::details::font;

using graphics::Font;
using graphics::Mesh;

#pragma region TableRecord

struct TableRecord
{
    static TableRecord read(std::istream& in);

    bool valid() const;

    Tag tag                = Tag::Invalid;
    std::uint32_t checksum = 0;
    std::uint32_t offset   = 0;
    std::uint32_t length   = 0;
};

TableRecord TableRecord::read(std::istream& in)
{
    constexpr size_t size = 16;

    std::array<char, size> buffer = {0};
    in.read(buffer.data(), size);

    TableRecord table;
    table.tag      = utils::big_endian_value<Tag>(buffer.begin());
    table.checksum = utils::big_endian_value<std::uint32_t>(buffer.begin() + 4);
    table.offset   = utils::big_endian_value<std::uint32_t>(buffer.begin() + 8);
    table.length   = utils::big_endian_value<std::uint32_t>(buffer.begin() + 12);

    return table;
}

bool is_ascii_tag(Tag tag)
{
    std::uint32_t value = static_cast<std::uint32_t>(tag);
    for (size_t i = 0; i < sizeof(Tag); ++i) {
        const std::uint8_t b = value & 0xff;
        if (b < 32 || b > 126) {
            return false;
        }
        value >>= 8;
    }

    return true;
}

bool TableRecord::valid() const
{
    const bool is_valid_tag    = is_ascii_tag(tag);
    const bool is_valid_offset = (offset & 3) == 0;                      // tables must be 4-byte aligned
    const bool is_valid_length = (length > 0) && (length < 1024 * 1024); // 0 < length < 1MB

    return is_valid_tag && is_valid_offset && is_valid_length;
}

#pragma endregion

#pragma region TableDirectory

struct TableDirectory
{
    inline static constexpr std::uint32_t true_type_tag       = 0x00010000;
    inline static constexpr std::uint32_t open_type_tag       = make_tag('O', 'T', 'T', 'O');
    inline static constexpr std::uint32_t font_collection_tag = make_tag('t', 't', 'c', 'f');

    static TableDirectory read(std::istream& in);

    bool valid() const;

    std::uint32_t sfnt_version   = 0;
    std::uint16_t num_tables     = 0;
    std::uint16_t search_range   = 0; // obsolete, don't use it
    std::uint16_t entry_selector = 0; // obsolete, don't use it
    std::uint16_t range_shift    = 0; // obsolete, don't use it

    std::vector<TableRecord> table_records;
};

TableDirectory TableDirectory::read(std::istream& in)
{
    constexpr size_t size = 12;

    std::array<char, size> buffer = {0};

    in.read(buffer.data(), size);

    TableDirectory table_directory;
    table_directory.sfnt_version   = utils::big_endian_value<std::uint32_t>(buffer.begin());
    table_directory.num_tables     = utils::big_endian_value<std::uint16_t>(buffer.begin() + 4);
    table_directory.search_range   = utils::big_endian_value<std::uint16_t>(buffer.begin() + 6);
    table_directory.entry_selector = utils::big_endian_value<std::uint16_t>(buffer.begin() + 8);
    table_directory.range_shift    = utils::big_endian_value<std::uint16_t>(buffer.begin() + 10);

    table_directory.table_records.reserve(table_directory.num_tables);

    for (std::size_t i = 0; in && i < table_directory.num_tables; i++) {
        table_directory.table_records.push_back(TableRecord::read(in));
    }

    return table_directory;
}

int max_power_of_2(int n)
{
    int max_pow2 = 0;

    while (n != 0) {
        n = n >> 1;
        max_pow2++;
    }

    return std::max(max_pow2 - 1, 0);
}

bool TableDirectory::valid() const
{
    const int max_pow2 = max_power_of_2(num_tables);

    const int check_search_range   = static_cast<int>(std::pow(2, max_pow2) * 16);
    const int check_entry_selector = max_pow2;
    const int check_range_shift    = std::max(0, num_tables * 16 - search_range);

    const bool is_valid_version    = sfnt_version == TableDirectory::true_type_tag;
    const bool is_valid_num_tables = num_tables > 0 && num_tables <= 4096;

    const bool records_valid = std::all_of(table_records.begin(), table_records.end(), [](const TableRecord& record) {
        return record.valid();
    });

    return is_valid_version && is_valid_num_tables && records_valid && search_range == check_search_range &&
           entry_selector == check_entry_selector && range_shift == check_range_shift &&
           table_records.size() == num_tables;
}

#pragma endregion

#pragma region Table

struct Table
{
    bool read_data(std::ifstream& in);
    bool valid() const;

    TableRecord record;
    BytesData data;
};

bool Table::read_data(std::ifstream& in)
{
    in.seekg(record.offset, in.beg);

    data.resize(record.length);
    in.read(reinterpret_cast<char*>(data.data()), record.length);

    return in.good();
}

std::uint32_t table_checksum(const BytesData& data)
{
    std::uint32_t sum = 0;

    const size_t count = ((data.size() + 3) / 4) * 4;
    for (size_t i = 0; i < count; i += 4) {
        std::uint32_t value = 0;
        value += static_cast<std::uint32_t>((i + 0 < data.size() ? data[i + 0] : 0) << 24);
        value += static_cast<std::uint32_t>((i + 1 < data.size() ? data[i + 1] : 0) << 16);
        value += static_cast<std::uint32_t>((i + 2 < data.size() ? data[i + 2] : 0) << 8);
        value += static_cast<std::uint32_t>((i + 3 < data.size() ? data[i + 3] : 0) << 0);

        sum += value;
    }

    return sum;
}

bool Table::valid() const
{
    auto get_checksum = [this](const auto& container) {
        std::uint32_t data_checksum = table_checksum(data);

        if (record.tag == Tag::Head) {
            data_checksum -= utils::big_endian_value<std::uint32_t>(container.data() + 8);
        }

        return data_checksum;
    };

    const std::uint32_t data_checksum = get_checksum(data);
    return data_checksum == record.checksum;
}

#pragma endregion

#pragma region Helper Functions

bool has_required_tables(const TableDirectory& table_directory)
{
    constexpr std::array<Tag, 8> required_tags =
    {Tag::Cmap, Tag::Head, Tag::Hhea, Tag::Hmtx, Tag::Maxp, Tag::Name, Tag::Os2, Tag::Post};

    auto has_record = [&records = table_directory.table_records](Tag tag) {
        return std::find_if(records.begin(), records.end(), [tag](const TableRecord& record) {
                   return record.tag == tag;
               }) != records.end();
    };

    for (const Tag tag : required_tags) {
        if (!has_record(tag)) {
            return false;
        }
    }

    // Specific tables to ttf
    if (table_directory.sfnt_version == TableDirectory::true_type_tag) {
        if (!has_record(Tag::Glyf) || !has_record(Tag::Loca)) {
            return false;
        }
    }

    return true;
}

std::unordered_map<Tag, Table> read_all_tables(std::ifstream& in, const std::vector<TableRecord>& table_records)
{
    std::unordered_map<Tag, Table> tables;

    for (const auto& record : table_records) {
        tables[record.tag].record = record;

        if (!tables[record.tag].read_data(in)) {
            break;
        }
    }

    return tables;
}

#pragma endregion

#pragma region Glyph Vertices Generation

struct GlyphMeshData
{
    Mesh::VertexData vertices;
    Mesh::ColorData colors;
    std::vector<Mesh::SubMesh> sub_meshes;
};

GlyphMeshData create_glyph_outline(const GlyphData::Contours& glyph,
                                   std::uint16_t units_per_em,
                                   Font::QualityType quality)
{
    // INFO: Beakouse of we scale all points positions in virtual space of range 0 to 1.
    //       There is no need in calculatoint relative to text size, screen resolution and pixels per em.
    //       It means pixels per em is equal to units per em.

    using graphics::Color;
    using math::quadratic_bezier;
    using math::Vector2f;
    using math::Vector3f;

    GlyphMeshData result;

    for (const auto& contour : glyph) {
        Mesh::IndicesData contour_sub_mesh;

        for (size_t i = 0; i < contour.size(); ++i) {
            const auto& point = contour[i];
            if (point.is_on_curve) {
                result.vertices.push_back(Vector3f(point.position / units_per_em));
                result.colors.push_back(Color(0x22FFEEFFu));
                contour_sub_mesh.push_back(static_cast<std::uint16_t>(result.vertices.size() - 1));
            } else {
                Vector2f p1;
                Vector2f p2;
                if (i == 0) {
                    p1 = contour.back().position;
                    p2 = contour[i + 1].position;
                } else if (i == contour.size() - 1) {
                    p1 = contour[i - 1].position;
                    p2 = contour.front().position;
                } else {
                    p1 = contour[i - 1].position;
                    p2 = contour[i + 1].position;
                }

                // genqrate points
                const float q_step = 1.0f / (quality + 1.0f);
                for (Font::QualityType q = 0; q < quality; ++q) {
                    const Vector2f pos = quadratic_bezier(p1, point.position, p2, (q + 1) * q_step);

                    result.vertices.push_back(Vector3f(pos / units_per_em));
                    result.colors.push_back(Color(0x22FFEEFFu));
                    contour_sub_mesh.push_back(static_cast<std::uint16_t>(result.vertices.size() - 1));
                }
            }
        }

        result.sub_meshes.push_back({contour_sub_mesh, Mesh::PrimitiveType::line_loop});
    }

    return result;
}

float polygon_area(const GlyphData::ContourType& contour)
{
    auto curr = contour.begin();
    auto next = std::next(contour.begin());

    float sum = 0;
    while (next != contour.end()) {
        sum += (next->position.x - curr->position.x) * (next->position.y + curr->position.y);
        next++;
        curr++;
    }
    next = contour.begin();
    sum += (next->position.x - curr->position.x) * (next->position.y + curr->position.y);

    return sum;
}

bool is_point_in_triangle(math::Vector2f pt, math::Vector2f v1, math::Vector2f v2, math::Vector2f v3)
{
    const bool b1 = cross(pt - v2, v1 - v2) < 0.0f;
    const bool b2 = cross(pt - v3, v2 - v3) < 0.0f;
    const bool b3 = cross(pt - v1, v3 - v1) < 0.0f;
    return ((b1 == b2) && (b2 == b3));
}

std::pair<std::vector<math::Vector2f>, Mesh::IndicesData> create_contour_mesh(const GlyphData::ContourType& contour,
                                                                              Font::QualityType quality)
{
    using math::quadratic_bezier;
    using math::Vector2f;
    using math::Vector3f;

    std::vector<Vector2f> vertices;
    Mesh::IndicesData indices;

    for (size_t i = 0; i < contour.size(); ++i) {
        const auto& point = contour[i];

        if (point.is_on_curve) {
            vertices.push_back(point.position);
            indices.push_back(static_cast<Mesh::IndicesData::value_type>(vertices.size() - 1));
        } else {
            // genqrate points
            const Vector2f p1  = (i == 0 ? contour.back().position : contour[i - 1].position);
            const Vector2f p2  = (i == contour.size() - 1 ? contour.front().position : contour[i + 1].position);
            const float q_step = 1.0f / (quality + 1.0f);

            for (Font::QualityType q = 0; q < quality; ++q) {
                vertices.push_back(quadratic_bezier(p1, point.position, p2, (q + 1) * q_step));
                indices.push_back(static_cast<Mesh::IndicesData::value_type>(vertices.size() - 1));
            }
        }
    }

    Mesh::IndicesData indices_to_check(indices.begin(), indices.end());
    Mesh::IndicesData triangles;

    while (indices.size() > 3) {
        Mesh::IndicesData ears;

        for (size_t i = 0; i < indices.size(); ++i) {
            const Mesh::IndicesData::value_type index_prev = i == 0 ? indices.back() : indices[i - 1];
            const Mesh::IndicesData::value_type index_curr = indices[i];
            const Mesh::IndicesData::value_type index_next = i == indices.size() - 1 ? indices.front() : indices[i + 1];

            const Vector2f prev = vertices[index_prev];
            const Vector2f curr = vertices[index_curr];
            const Vector2f next = vertices[index_next];

            bool is_ear = true;
            for (const size_t index : indices_to_check) {
                if (index == index_prev || index == index_curr || index == index_next) {
                    continue;
                }

                if (cross(prev - curr, next - curr) <= 0.0f) {
                    is_ear = false;
                    break;
                }

                const Vector2f p = vertices[index];
                if (is_point_in_triangle(p, prev, next, curr)) {
                    is_ear = false;
                    break;
                }
            }

            if (is_ear) {
                ears.push_back(index_curr);
            }
        }

        if (ears.empty()) {
            throw std::runtime_error("Ears are empty. It's bug in triangulation algorithm.");
        }

        size_t min_angle_index = ears[0];
        float max_dot          = -9999.0f;

        for (auto ear_index : ears) {
            auto it  = std::find(indices.begin(), indices.end(), ear_index);
            size_t i = std::distance(indices.begin(), it);

            const Mesh::IndicesData::value_type index_prev = i == 0 ? indices.back() : indices[i - 1];
            const Mesh::IndicesData::value_type index_curr = indices[i];
            const Mesh::IndicesData::value_type index_next = i == indices.size() - 1 ? indices.front() : indices[i + 1];

            const Vector2f prev = vertices[index_prev];
            const Vector2f curr = vertices[index_curr];
            const Vector2f next = vertices[index_next];

            auto d = dot(normalize(prev - curr), normalize(next - curr));
            if (d > max_dot) {
                max_dot         = d;
                min_angle_index = ear_index;
            }
        }

        {
            auto it  = std::find(indices.begin(), indices.end(), min_angle_index);
            size_t i = std::distance(indices.begin(), it);

            const Mesh::IndicesData::value_type index_prev = i == 0 ? indices.back() : indices[i - 1];
            const Mesh::IndicesData::value_type index_curr = indices[i];
            const Mesh::IndicesData::value_type index_next = i == indices.size() - 1 ? indices.front() : indices[i + 1];
            triangles.push_back(index_curr);
            triangles.push_back(index_prev);
            triangles.push_back(index_next);
            indices.erase(it);
        }
    }

    // Add last triangle
    triangles.push_back(indices[0]);
    triangles.push_back(indices[2]);
    triangles.push_back(indices[1]);

    return std::make_pair(std::move(vertices), std::move(triangles));
}

GlyphMeshData create_glyph_mesh(const GlyphData::Contours& contours,
                                std::uint16_t units_per_em,
                                Font::QualityType quality)
{
    using graphics::Color;

    std::vector<std::reference_wrapper<const GlyphData::ContourType>> filled;
    std::vector<std::reference_wrapper<const GlyphData::ContourType>> holes;

    for (const auto& contour : contours) {
        if (polygon_area(contour) > 0.0f) {
            filled.push_back(contour);
        } else {
            holes.push_back(contour);
        }
    }

    // Generate result
    GlyphMeshData res;
    res.sub_meshes.push_back({{}, Mesh::PrimitiveType::triangles});

    // generate all points in contour
    for (const auto& contour : filled) {
        const auto& [vertices, indices] = create_contour_mesh(contour, quality);

        const auto indices_offset = static_cast<Mesh::IndicesData::value_type>(res.vertices.size());
        std::transform(vertices.begin(),
                       vertices.end(),
                       std::back_inserter(res.vertices),
                       [upm = units_per_em](const auto& v) { return math::Vector3f(v / upm); });

        std::transform(indices.begin(),
                       indices.end(),
                       std::back_inserter(res.sub_meshes[0].indices),
                       [offset = indices_offset](const auto& i) { return i + offset; });
    }

    // Add colors
    res.colors.insert(res.colors.end(), res.vertices.size(), Color(0xFF88DDFFu));

    return res;
}

#pragma endregion

} // namespace

namespace framework::graphics
{

#pragma region class FontData
class Font::FontData
{
public:
    using GlyphIdToMeshMap = std::unordered_map<GlyphId, GlyphMeshData>;

    FontData(FontHeader head,
             HorizontalMetrics hmtx,
             CharacterToGlyphIndexMapping cmap,
             Os2 os2,
             GlyphData glyf,
             Font::QualityType quality);

    FontData(const FontData& other);
    FontData(FontData&& other) noexcept = default;

    FontData& operator=(const FontData& other);
    FontData& operator=(FontData&& other) noexcept = default;

    ~FontData() = default;

    void add_glyph(GlyphId id);

    GlyphId glyph_index(CodePoint codepoint) const;
    std::uint16_t advance_width(GlyphId id) const;
    std::int16_t left_sidebearing(GlyphId id) const;
    std::uint16_t units_per_em() const;

    bool baseline_at_y_zero() const;
    bool left_sidebearing_at_x_zero() const;

    const GlyphIdToMeshMap& glyphs() const;

private:
    GlyphIdToMeshMap m_glyphs;
    FontHeader m_head;
    HorizontalMetrics m_hmtx;
    CharacterToGlyphIndexMapping m_cmap;
    Os2 m_os2;
    GlyphData m_glyf;
    Font::QualityType m_quality = 1;
};

Font::FontData::FontData(FontHeader head,
                         HorizontalMetrics hmtx,
                         CharacterToGlyphIndexMapping cmap,
                         Os2 os2,
                         GlyphData glyf,
                         Font::QualityType quality)
    : m_head(std::move(head))
    , m_hmtx(std::move(hmtx))
    , m_cmap(std::move(cmap))
    , m_os2(std::move(os2))
    , m_glyf(std::move(glyf))
    , m_quality(std::move(quality))
{}

Font::FontData::FontData(const Font::FontData& other)
    : m_head(other.m_head)
    , m_hmtx(other.m_hmtx)
    , m_cmap(other.m_cmap)
    , m_os2(other.m_os2)
    , m_glyf(other.m_glyf)
    , m_quality(other.m_quality)
{}

Font::FontData& Font::FontData::operator=(const Font::FontData& other)
{
    using std::swap;

    FontData tmp(other);
    swap(tmp.m_glyphs, m_glyphs);
    swap(tmp.m_head, m_head);
    swap(tmp.m_hmtx, m_hmtx);
    swap(tmp.m_cmap, m_cmap);
    swap(tmp.m_os2, m_os2);
    swap(tmp.m_glyf, m_glyf);
    swap(tmp.m_quality, m_quality);

    return *this;
}

void Font::FontData::add_glyph(GlyphId glyph_id)
{
    if (m_glyphs.count(glyph_id) == 0) {

        if (!m_glyf.has(glyph_id)) {
            throw std::runtime_error(
            "Trying to load glyph that is not in font. Cmap table must return missing_glyph_id in this case.");
        }

        // m_glyphs.emplace(glyph_id, create_glyph_outline(m_glyf.at(glyph_id), units_per_em(), m_quality));
        m_glyphs.emplace(glyph_id, create_glyph_mesh(m_glyf.at(glyph_id), units_per_em(), m_quality));
    }
}

GlyphId Font::FontData::glyph_index(CodePoint codepoint) const
{
    GlyphId id = m_cmap.glyph_index(codepoint);

    if (id == missig_glyph_id) {
        auto codepoints = utf::to_codepoints(std::u16string(1u, static_cast<char16_t>(m_os2.default_char())));
        if (!codepoints.empty()) {
            id = m_cmap.glyph_index(codepoint);
        }
    }

    return id;
}

std::uint16_t Font::FontData::advance_width(GlyphId id) const
{
    return m_hmtx.advance_width(id);
}

std::int16_t Font::FontData::left_sidebearing(GlyphId id) const
{
    return m_hmtx.left_sidebearing(id);
}

std::uint16_t Font::FontData::units_per_em() const
{
    return m_head.units_per_em();
}

bool Font::FontData::baseline_at_y_zero() const
{
    return m_head.baseline_at_y_zero();
}

bool Font::FontData::left_sidebearing_at_x_zero() const
{
    return m_head.left_sidebearing_at_x_zero();
}

const Font::FontData::GlyphIdToMeshMap& Font::FontData::glyphs() const
{
    return m_glyphs;
}

#pragma endregion

Font::Font(Font::QualityType quality)
{
    static constexpr QualityType max_quality = 32;

    m_quality = std::min(quality, max_quality);
}

Font::Font(const Font& other)
    : m_data(std::make_unique<FontData>(*other.m_data))
{}

Font::Font(Font&& other) noexcept
{
    swap(*this, other);
}

Font::~Font() = default;

Font& Font::operator=(const Font& other)
{
    using std::swap;

    Font tmp(other);
    swap(*this, tmp);
    return *this;
}

Font& Font::operator=(Font&& other) noexcept
{
    swap(*this, other);
    return *this;
}

Font::LoadResult Font::load(const std::filesystem::path& file)
{
    if (!std::filesystem::exists(file)) {
        return LoadResult::FileNotExists;
    }

    try {
        return parse(file);
    } catch (UnsupportedError& e) {
        log::error("Exception:") << e.what();
        return LoadResult::Unsupported;
    } catch (NotImplementedError& e) {
        log::error("Exception:") << e.what();
        return LoadResult::Unsupported;
    } catch (ParsingError& e) {
        log::error("Exception:") << e.what();
        return LoadResult::TableParsingError;
    } catch (std::exception& e) {
        log::error("Exception:") << e.what();
        return LoadResult::UnknownError;
    }
}

Mesh Font::create_text_mesh(const std::string& text)
{
    using IndicesDataType = Mesh::IndicesData::value_type;

    if (m_data == nullptr) {
        throw std::runtime_error("Font data is not loaded. See Font::load and Font::precache.");
    }

    precache(text);

    // for new line
    // see OS2 sTypoAscender, sTypoDescender and sTypoLineGap for linespacing

    Mesh mesh;

    Mesh::VertexData vertices;
    Mesh::ColorData colors;

    math::Vector3f vetricies_offset;

    for (const auto& cp : utf::to_codepoints(text)) {
        const GlyphId glyph_id = m_data->glyph_index(cp);

        const auto it = m_data->glyphs().find(glyph_id);
        if (it == m_data->glyphs().end()) {
            throw std::runtime_error("Can't find glyph to create mesh.");
        }

        const IndicesDataType indices_offset = static_cast<IndicesDataType>(vertices.size());

        for (const auto& v : it->second.vertices) {
            vertices.push_back(v + vetricies_offset);
        }

        for (const auto& c : it->second.colors) {
            colors.push_back(c);
        }

        // devision by point_size is for clamp points in range from 0 to 1.
        const float advance_step = (m_data->advance_width(glyph_id) / static_cast<float>(m_data->units_per_em()));
        vetricies_offset += math::Vector3f{advance_step, 0, 0};

        for (const auto& sub_mesh : it->second.sub_meshes) {
            Mesh::IndicesData indices;
            for (const auto& i : sub_mesh.indices) {
                indices.push_back(i + indices_offset);
            }
            mesh.add_sub_mesh(indices, sub_mesh.primitive_type);
        }
    }

    mesh.set_vertices(vertices);
    mesh.set_colors(colors);

    return mesh;
}

Font::LoadResult Font::parse(const std::filesystem::path& filepath)
{
    std::ifstream file(filepath, std::ios::in | std::ios::binary);
    if (!file) {
        return LoadResult::OpenFileError;
    }

    TableDirectory table_directory = TableDirectory::read(file);
    if (table_directory.sfnt_version == TableDirectory::open_type_tag) {
        return LoadResult::Unsupported;
    }

    if (table_directory.sfnt_version == TableDirectory::font_collection_tag) {
        return LoadResult::Unsupported;
    }

    if (!file || !table_directory.valid()) {
        return LoadResult::InvalidOffsetTable;
    }

    const bool has_tables = has_required_tables(table_directory);
    if (!file || !has_tables) {
        return LoadResult::FileStructureError;
    }

    const auto tables = read_all_tables(file, table_directory.table_records);
    if (!file || tables.size() != table_directory.table_records.size()) {
        return LoadResult::FileStructureError;
    }

    file.close();

    const bool tables_valid = std::all_of(tables.begin(), tables.end(), [](const auto& it) {
        return it.second.valid();
    });

    if (!tables_valid) {
        return LoadResult::FileStructureError;
    }

    const MaximumProfile maxp(tables.at(Tag::Maxp).data);
    if (!maxp.valid()) {
        return LoadResult::TableParsingError;
    }

    if (table_directory.sfnt_version == TableDirectory::true_type_tag &&
        maxp.version() != MaximumProfile::true_type_version) {
        return LoadResult::FileStructureError;
    }

    if (table_directory.sfnt_version == TableDirectory::open_type_tag &&
        maxp.version() != MaximumProfile::open_type_vetsion) {
        return LoadResult::FileStructureError;
    }

    const FontHeader head(tables.at(Tag::Head).data);
    if (!head.valid()) {
        return LoadResult::TableParsingError;
    }

    const CharacterToGlyphIndexMapping cmap(tables.at(Tag::Cmap).data);
    if (!cmap.valid()) {
        return LoadResult::TableParsingError;
    }

    const HorizontalHeader hhea(tables.at(Tag::Hhea).data);
    if (!hhea.valid()) {
        return LoadResult::TableParsingError;
    }

    const HorizontalMetrics hmtx(hhea.number_of_h_metrics(), maxp.num_glyphs(), tables.at(Tag::Hmtx).data);
    if (!hmtx.valid()) {
        return LoadResult::TableParsingError;
    }

    const Naming naming(tables.at(Tag::Name).data);
    if (!naming.valid()) {
        return LoadResult::TableParsingError;
    }

    const Os2 os2(tables.at(Tag::Os2).data);
    if (!os2.valid()) {
        return LoadResult::TableParsingError;
    }

    // No need to read Tag::Post table

    if (table_directory.sfnt_version != TableDirectory::true_type_tag) {
        return LoadResult::Unsupported;
    }

    const IndexToLocation loca(head.index_to_loc_format(), maxp.num_glyphs(), tables.at(Tag::Loca).data);
    if (!loca.valid()) {
        return LoadResult::TableParsingError;
    }

    if ((maxp.num_glyphs() + 1u) != loca.offsets().size()) {
        return LoadResult::TableParsingError;
    }

    if (loca.offsets().back() != tables.at(Tag::Glyf).data.size()) {
        return LoadResult::TableParsingError;
    }

    const GlyphData glyf(maxp.num_glyphs(), loca.offsets(), tables.at(Tag::Glyf).data);
    if (!glyf.valid()) {
        return LoadResult::TableParsingError;
    }

    m_data = std::make_unique<Font::FontData>(std::move(head),
                                              std::move(hmtx),
                                              std::move(cmap),
                                              std::move(os2),
                                              std::move(glyf),
                                              m_quality);

    if (m_data->left_sidebearing_at_x_zero()) {
        throw UnsupportedError("Figureout what to do if left sideberint is not equal minx position of glyph");
    }

    return LoadResult::Success;
}

void Font::precache(const std::string& chars)
{
    for (const auto& cp : utf::to_codepoints(chars)) {
        m_data->add_glyph(m_data->glyph_index(cp));
    }
}

void swap(Font& lhs, Font& rhs) noexcept
{
    using std::swap;
    swap(lhs.m_data, rhs.m_data);
}

} // namespace framework::graphics
