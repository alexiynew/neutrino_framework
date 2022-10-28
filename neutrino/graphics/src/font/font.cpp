#include <algorithm>
#include <array>
#include <cstdint>
#include <exception>
#include <fstream>
#include <functional>
#include <numeric>
#include <set>
#include <unordered_map>
#include <vector>

#include <common/exceptions.hpp>
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
using math::Polygon;

#pragma region TableRecord

struct TableRecord
{
    static TableRecord read(std::istream& in);

    bool is_valid() const;

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

bool TableRecord::is_valid() const
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

    bool is_valid() const;

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

bool TableDirectory::is_valid() const
{
    const int max_pow2 = max_power_of_2(num_tables);

    const int check_search_range   = static_cast<int>(std::pow(2, max_pow2) * 16);
    const int check_entry_selector = max_pow2;
    const int check_range_shift    = std::max(0, num_tables * 16 - search_range);

    const bool is_valid_version    = sfnt_version == TableDirectory::true_type_tag;
    const bool is_valid_num_tables = num_tables > 0 && num_tables <= 4096;

    const bool records_valid = std::all_of(table_records.begin(), table_records.end(), [](const TableRecord& record) {
        return record.is_valid();
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
    bool is_valid() const;

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

bool Table::is_valid() const
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
    std::vector<Mesh::SubMesh> submeshes;
    float advance_step = 1.0;
};

Polygon generate_polygon(const GlyphData::ContourType& contour, Font::QualityType quality)
{
    Polygon polygon;

    for (size_t i = 0; i < contour.size(); ++i) {
        const auto& point = contour[i];

        if (point.is_on_curve) {
            polygon.push_back(point.position);
        } else {
            // genqrate points
            const math::Vector2f p1 = (i == 0 ? contour.back().position : contour[i - 1].position);
            const math::Vector2f p2 = (i == contour.size() - 1 ? contour.front().position : contour[i + 1].position);
            const float q_step      = 1.0f / (quality + 1.0f);

            for (Font::QualityType q = 0; q < quality; ++q) {
                polygon.push_back(quadratic_bezier(p1, point.position, p2, (q + 1) * q_step));
            }
        }
    }

    return polygon;
}

std::vector<Polygon> convert_polygons_with_holes_to_holeless_polygons(const std::vector<Polygon>& filled,
                                                                      const std::vector<Polygon>& holes)
{
    std::vector<Polygon> holeless;
    holeless.reserve(filled.size());

    for (const auto& polygon : filled) {
        std::vector<size_t> holes_in_polygon;
        size_t holes_points_count = 0;
        for (size_t i = 0; i < holes.size(); ++i) {
            if (is_point_in_polygon(holes[i].front(), polygon)) {
                holes_in_polygon.push_back(i);
                holes_points_count += holes[i].size();
            }
        }

        Polygon combine = polygon;
        combine.reserve(polygon.size() + holes_points_count + holes_in_polygon.size() * 2);

        for (const auto& hole_index : holes_in_polygon) {
            const auto& hole              = holes[hole_index];
            const math::Vector2f hole_top = hole.front();

            // Find closest point in filled contour that higher than hole
            auto closest_point_it = combine.begin();
            for (auto it = std::next(combine.begin()); it != combine.end(); ++it) {
                if (it->y < hole_top.y) {
                    continue;
                }

                const float dist_prev = squared_distance(hole_top, *closest_point_it);
                const float dist_curr = squared_distance(hole_top, *it);
                if (dist_prev > dist_curr) {
                    closest_point_it = it;
                }
            }

            auto it = combine.insert(next(closest_point_it), *closest_point_it);
            it      = combine.insert(it, hole.front());
            combine.insert(it, hole.begin(), hole.end());
        }

        holeless.emplace_back(std::move(combine));
    }

    return holeless;
}

std::vector<Polygon> generate_glyph_polygons(const GlyphData::Contours& contours, Font::QualityType quality)
{
    std::vector<Polygon> filled;
    std::vector<Polygon> holes;

    for (const auto& contour : contours) {
        Polygon polygon = generate_polygon(contour, quality);
        if (polygon_area(polygon) > 0.0f) {
            filled.emplace_back(std::move(polygon));
        } else {
            holes.emplace_back(std::move(polygon));
        }
    }

    // Rearange points in hole so the top poiint go first
    for (auto& hole : holes) {
        auto it = std::max_element(hole.begin(), hole.end(), [](const auto& a, const auto& b) { return a.y < b.y; });
        std::rotate(hole.begin(), it, hole.end());
    }

    // Sort holes by top points
    std::sort(holes.begin(), holes.end(), [](const auto& a, const auto& b) { return a[0].y > b[0].y; });

    return convert_polygons_with_holes_to_holeless_polygons(filled, holes);
}

GlyphMeshData create_glyph_mesh(const GlyphData::Contours& contours,
                                std::uint16_t units_per_em,
                                Font::QualityType quality)
{
    using graphics::Color;

    const std::vector<Polygon> polygons = generate_glyph_polygons(contours, quality);

    // Generate result
    GlyphMeshData res;
    res.submeshes.push_back({{}, Mesh::PrimitiveType::triangles});

    for (const auto& polygon : polygons) {
        const auto& indices = generate_ear_cut_triangulation(polygon);

        const auto indices_offset = static_cast<Mesh::IndicesData::value_type>(res.vertices.size());
        std::transform(polygon.begin(),
                       polygon.end(),
                       std::back_inserter(res.vertices),
                       [upm = units_per_em](const auto& v) { return math::Vector3f(v / upm); });

        std::transform(indices.begin(),
                       indices.end(),
                       std::back_inserter(res.submeshes[0].indices),
                       [offset = indices_offset](const auto& i) { return i + offset; });
    }

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

        m_glyphs.emplace(glyph_id, create_glyph_mesh(m_glyf.at(glyph_id), units_per_em(), m_quality));

        m_glyphs[glyph_id].advance_step = (advance_width(glyph_id) / static_cast<float>(units_per_em()));
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
        throw std::runtime_error("Font data is not loaded. See Font::load.");
    }

    precache(text);

    std::vector<std::reference_wrapper<const GlyphMeshData>> glyphs;
    glyphs.reserve(text.size());

    // Collect glyphs
    for (const auto& cp : utf::to_codepoints(text)) {
        const GlyphId glyph_id = m_data->glyph_index(cp);

        const auto it = m_data->glyphs().find(glyph_id);
        if (it == m_data->glyphs().end()) {
            throw std::runtime_error("Can't find glyph to create mesh.");
        }

        glyphs.push_back(it->second);
    }

    const size_t vertices_count = std::accumulate(glyphs.begin(),
                                                  glyphs.end(),
                                                  size_t(0),
                                                  [](size_t sum, const auto& glyph) {
                                                      return sum + glyph.get().vertices.size();
                                                  });

    // for new line
    // see OS2 sTypoAscender, sTypoDescender and sTypoLineGap for linespacing

    Mesh mesh;

    Mesh::VertexData vertices;
    vertices.reserve(vertices_count);

    math::Vector3f vetricies_offset;

    for (const auto& glyph_ref : glyphs) {
        const GlyphMeshData& glyph = glyph_ref.get();

        const IndicesDataType indices_offset = static_cast<IndicesDataType>(vertices.size());

        for (const auto& v : glyph.vertices) {
            vertices.push_back(v + vetricies_offset);
        }

        vetricies_offset += math::Vector3f{glyph.advance_step, 0, 0};

        for (const auto& submesh : glyph.submeshes) {
            Mesh::IndicesData indices;
            indices.reserve(submesh.indices.size());
            for (const auto& i : submesh.indices) {
                indices.push_back(i + indices_offset);
            }
            mesh.add_submesh(std::move(indices), submesh.primitive_type);
        }
    }

    mesh.set_vertices(std::move(vertices));

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

    if (!file || !table_directory.is_valid()) {
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
        return it.second.is_valid();
    });

    if (!tables_valid) {
        return LoadResult::FileStructureError;
    }

    const MaximumProfile maxp(tables.at(Tag::Maxp).data);
    if (!maxp.is_valid()) {
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
    if (!head.is_valid()) {
        return LoadResult::TableParsingError;
    }

    const CharacterToGlyphIndexMapping cmap(tables.at(Tag::Cmap).data);
    if (!cmap.is_valid()) {
        return LoadResult::TableParsingError;
    }

    const HorizontalHeader hhea(tables.at(Tag::Hhea).data);
    if (!hhea.is_valid()) {
        return LoadResult::TableParsingError;
    }

    const HorizontalMetrics hmtx(hhea.number_of_h_metrics(), maxp.num_glyphs(), tables.at(Tag::Hmtx).data);
    if (!hmtx.is_valid()) {
        return LoadResult::TableParsingError;
    }

    const Naming naming(tables.at(Tag::Name).data);
    if (!naming.is_valid()) {
        return LoadResult::TableParsingError;
    }

    const Os2 os2(tables.at(Tag::Os2).data);
    if (!os2.is_valid()) {
        return LoadResult::TableParsingError;
    }

    // No need to read Tag::Post table

    if (table_directory.sfnt_version != TableDirectory::true_type_tag) {
        return LoadResult::Unsupported;
    }

    const IndexToLocation loca(head.index_to_loc_format(), maxp.num_glyphs(), tables.at(Tag::Loca).data);
    if (!loca.is_valid()) {
        return LoadResult::TableParsingError;
    }

    if ((maxp.num_glyphs() + 1u) != loca.offsets().size()) {
        return LoadResult::TableParsingError;
    }

    if (loca.offsets().back() != tables.at(Tag::Glyf).data.size()) {
        return LoadResult::TableParsingError;
    }

    const GlyphData glyf(maxp.num_glyphs(), loca.offsets(), tables.at(Tag::Glyf).data);
    if (!glyf.is_valid()) {
        return LoadResult::TableParsingError;
    }

    m_data = std::make_unique<Font::FontData>(std::move(head),
                                              std::move(hmtx),
                                              std::move(cmap),
                                              std::move(os2),
                                              std::move(glyf),
                                              m_quality);

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
