#include <algorithm>
#include <array>
#include <cstdint>
#include <exception>
#include <fstream>
#include <set>
#include <unordered_map>
#include <vector>

#include <common/utils.hpp>
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

using namespace framework;
using namespace framework::graphics::details::font;

using framework::graphics::Mesh;

namespace
{

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
    std::vector<Mesh::SubMesh> sub_meshes;
};

GlyphMeshData create_glyph_vericies(const GlyphData::Glyph& glyph, std::uint16_t units_per_em)
{
    // pointSize * resolution / ( 72 points_per_inch * units_per_em )
    // pointSize  - some point size;
    // resolution - screen resolution in dpi (72 or 96 dpi default)
    //
    // pixels per em
    // ppem = pointSize * dpi / 72
    //
    // pixel_coordinate = em_coordinate * ppem / units_per_em

    using math::Vector3f;

    // TODO: provide point size with font configuration
    const int point_size = 18;

    // TODO: Consider using actual screen dpi. To simplify implementation for now the 72 dpi would be used.
    //       This means that points and pixels per em are equal.
    const int dpi = 72;

    const float ppem = point_size * dpi / 72;

    const float x_min = glyph.header().x_min() * ppem / units_per_em;
    const float y_min = glyph.header().y_min() * ppem / units_per_em;
    const float x_max = glyph.header().x_max() * ppem / units_per_em;
    const float y_max = glyph.header().y_max() * ppem / units_per_em;

    // ccw vertices order
    Mesh::VertexData vertices;
    vertices.push_back(Vector3f(x_min, y_max, 0.0f) / point_size);
    vertices.push_back(Vector3f(x_min, y_min, 0.0f) / point_size);
    vertices.push_back(Vector3f(x_max, y_min, 0.0f) / point_size);
    vertices.push_back(Vector3f(x_max, y_max, 0.0f) / point_size);

    // 2 triangles in ccw point order
    Mesh::IndicesData bbox;
    bbox.push_back(0);
    bbox.push_back(1);
    bbox.push_back(2);
    bbox.push_back(3);

    GlyphMeshData result;
    result.sub_meshes.push_back({bbox, Mesh::PrimitiveType::line_loop});

    // layout(isolines) in;
    // in vec3 tcPos[];
    // uniform mat4 uMVP;
    // void main() {
    //     float t = gl_TessCoord.x;
    //     vec3 ePos = bezier4(tcPos[0], tcPos[1], tcPos[2], tcPos[3], t);
    //     gl_Position = uMVP * vec4(ePos, 1);
    // }

    for (const auto& contour : glyph.contours()) {
        Vector3f prev_point(0, 0, 0);
        Mesh::IndicesData contour_sub_mesh;
        for (const auto& point : contour) {
            vertices.push_back(prev_point + Vector3f(point.position * ppem / units_per_em / point_size));
            contour_sub_mesh.push_back(static_cast<std::uint16_t>(vertices.size() - 1));

            prev_point = vertices.back();
        }

        result.sub_meshes.push_back({contour_sub_mesh, Mesh::PrimitiveType::line_loop});
    }

    result.vertices = std::move(vertices);

    return result;
}

#pragma endregion

} // namespace

namespace framework::graphics
{

#pragma region class FontData
class Font::FontData
{
public:
    using CodePointToGlyphMap = std::unordered_map<CodePoint, GlyphMeshData>;

    FontData(FontHeader head, HorizontalMetrics hmtx, CharacterToGlyphIndexMapping cmap, GlyphData glyf);

    FontData(const FontData& other);
    FontData(FontData&& other) noexcept = default;

    FontData& operator=(const FontData& other);
    FontData& operator=(FontData&& other) noexcept = default;

    ~FontData() = default;

    void add_glyph(CodePoint codepoint);

    GlyphId glyph_index(CodePoint codepoint) const;
    std::uint16_t advance_width(GlyphId id) const;
    std::int16_t left_sidebearing(GlyphId id) const;
    std::uint16_t units_per_em() const;

    bool baseline_at_y_zero() const;
    bool left_sidebearing_at_x_zero() const;

    const CodePointToGlyphMap& glyphs() const;

private:
    CodePointToGlyphMap m_glyphs;
    FontHeader m_head;
    HorizontalMetrics m_hmtx;
    CharacterToGlyphIndexMapping m_cmap;
    GlyphData m_glyf;
};

Font::FontData::FontData(FontHeader head, HorizontalMetrics hmtx, CharacterToGlyphIndexMapping cmap, GlyphData glyf)
    : m_head(std::move(head))
    , m_hmtx(std::move(hmtx))
    , m_cmap(std::move(cmap))
    , m_glyf(std::move(glyf))
{}

Font::FontData::FontData(const Font::FontData& other)
    : m_head(other.m_head)
    , m_hmtx(other.m_hmtx)
    , m_cmap(other.m_cmap)
    , m_glyf(other.m_glyf)
{}

Font::FontData& Font::FontData::operator=(const Font::FontData& other)
{
    using std::swap;

    FontData tmp(other);
    swap(tmp.m_glyphs, m_glyphs);
    swap(tmp.m_head, m_head);
    swap(tmp.m_hmtx, m_hmtx);
    swap(tmp.m_cmap, m_cmap);
    swap(tmp.m_glyf, m_glyf);

    return *this;
}

void Font::FontData::add_glyph(CodePoint codepoint)
{
    if (m_glyphs.count(codepoint) == 0) {
        const GlyphId glyph_id = glyph_index(codepoint);

        if (glyph_id == missig_glyph_id) {
            throw std::runtime_error("Can't crate mesh for 0 glyph id.");
        }

        const GlyphData::Glyph& glyph = m_glyf.at(glyph_id);

        m_glyphs.emplace(codepoint, create_glyph_vericies(glyph, units_per_em()));
    }
}

GlyphId Font::FontData::glyph_index(CodePoint codepoint) const
{
    return m_cmap.glyph_index(codepoint);
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

const Font::FontData::CodePointToGlyphMap& Font::FontData::glyphs() const
{
    return m_glyphs;
}

#pragma endregion

Font::Font() = default;

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

void Font::precache(const std::string& chars)
{
    if (m_data == nullptr) {
        return;
    }

    for (const auto& cp : utf::to_codepoints(chars)) {
        m_data->add_glyph(cp);
    }
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

    m_data = std::make_unique<Font::FontData>(std::move(head), std::move(hmtx), std::move(cmap), std::move(glyf));

    // TODO: Precache glyph for missing codepoints

    // TODO: Figureout what to do if left sideberint is not equal minx position of glyph
    if (m_data->left_sidebearing_at_x_zero()) {
        return LoadResult::Unsupported;
    }

    return LoadResult::Success;
}

InstanceId Font::instance_id() const
{
    return m_instance_id;
}

Mesh Font::create_text_mesh(const std::string& text) const
{
    if (m_data == nullptr) {
        throw std::runtime_error("Font data is not loaded. See Font::load and Font::precache.");
    }

    // TODO: provide point size with font configuration
    const int point_size = 18;

    // TODO: Consider using actual screen dpi. To simplify implementation for now the 72 dpi would be used.
    //       This means that points and pixels per em are equal.
    const int dpi    = 72;
    const float ppem = point_size * dpi / 72;

    // see OS2 sTypoAscender, sTypoDescender and sTypoLineGap for linespacing

    Mesh mesh;

    Mesh::VertexData vertices;

    math::Vector3f vetricies_offset;

    for (const auto& cp : utf::to_codepoints(text)) {
        auto it = m_data->glyphs().find(cp);

        if (it == m_data->glyphs().end()) {
            // TODO: use empty glyph. See - OS2 table usDefaultChar
            throw std::runtime_error("Usage of empty glyph is not implemented");
        }

        const GlyphId glyph_id             = m_data->glyph_index(cp);
        const std::uint16_t indices_offset = static_cast<std::uint16_t>(vertices.size());

        for (const auto& v : it->second.vertices) {
            vertices.push_back(v + vetricies_offset);
        }

        // devision by point_size is for clamp points in range from 0 to 1.
        const float advance_step = (m_data->advance_width(glyph_id) * ppem / m_data->units_per_em());
        vetricies_offset += math::Vector3f{advance_step / point_size, 0, 0};

        for (const auto& sub_mesh : it->second.sub_meshes) {
            Mesh::IndicesData indices;
            for (const auto& i : sub_mesh.indices) {
                indices.push_back(i + indices_offset);
            }
            mesh.add_sub_mesh(indices, Mesh::PrimitiveType::line_loop);
        }
    }

    // Add axises
    const std::uint16_t indices_offset = static_cast<std::uint16_t>(vertices.size());

    vertices.push_back(math::Vector3f{0, 0, 0});
    vertices.push_back(math::Vector3f{0, 1, 0});
    vertices.push_back(vetricies_offset);

    Mesh::IndicesData axises;
    axises.push_back(indices_offset + 0);
    axises.push_back(indices_offset + 1);
    axises.push_back(indices_offset + 0);
    axises.push_back(indices_offset + 2);

    mesh.set_vertices(vertices);
    mesh.add_sub_mesh(axises, Mesh::PrimitiveType::lines);

    return mesh;
}

void swap(Font& lhs, Font& rhs) noexcept
{
    using std::swap;
    swap(lhs.m_data, rhs.m_data);
}

} // namespace framework::graphics
