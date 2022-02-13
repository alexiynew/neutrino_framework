#include <algorithm>
#include <array>
#include <cstdint>
#include <exception>
#include <fstream>
#include <unordered_map>
#include <vector>

#include <common/utils.hpp>
#include <graphics/font.hpp>

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
    std::vector<std::uint8_t> data;
};

bool Table::read_data(std::ifstream& in)
{
    in.seekg(record.offset, in.beg);

    data.resize(record.length);
    in.read(reinterpret_cast<char*>(data.data()), record.length);

    return in.good();
}

std::uint32_t table_checksum(const std::vector<std::uint8_t>& data)
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

} // namespace

namespace framework::graphics
{

Font::LoadResult Font::load(const std::filesystem::path& file)
{
    if (!std::filesystem::exists(file)) {
        return LoadResult::FileNotExists;
    }

    try {
        return parse(file);
    } catch (UnsupportedError&) {
        return LoadResult::Unsupported;
    } catch (UnimplementedError&) {
        return LoadResult::Unsupported;
    } catch (ParsingError&) {
        return LoadResult::TableParsingError;
    } catch (std::exception&) {
        return LoadResult::UnknownError;
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

    if (table_directory.sfnt_version == TableDirectory::true_type_tag) {
        const IndexToLocation loca(head.index_to_loc_format(), maxp.num_glyphs(), tables.at(Tag::Loca).data);
        if (!loca.valid()) {
            return LoadResult::TableParsingError;
        }

        if ((maxp.num_glyphs() + 1) != loca.offsets().size()) {
            return LoadResult::TableParsingError;
        }

        const GlyphData glyf(maxp.num_glyphs(), loca.offsets(), tables.at(Tag::Glyf).data);
        if (!glyf.valid()) {
            return LoadResult::TableParsingError;
        }

        return LoadResult::Unsupported;
    }

    return LoadResult::Success;
}

} // namespace framework::graphics
