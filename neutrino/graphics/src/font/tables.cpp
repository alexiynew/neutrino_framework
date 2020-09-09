////////////////////////////////////////////////////////////////////////////////
/// @file
/// @brief Font tables
/// @author Fedorov Alexey
/// @date 04.09.2020
////////////////////////////////////////////////////////////////////////////////

// =============================================================================
// MIT License
//
// Copyright (c) 2017-2019 Fedorov Alexey
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
// =============================================================================

#include <array>

#include <common/utils.hpp>

#include <graphics/src/font/tables.hpp>

namespace
{
int inline max_power_of_2(int n)
{
    int exp = 0;

    while (n != 0) {
        n = n >> 1;
        exp++;
    }

    return std::max(exp - 1, 0);
}

std::uint32_t table_checksum(const std::vector<std::uint8_t>& data)
{
    std::uint32_t sum = 0;
    size_t count      = ((data.size() + 3) / 4) * 4;
    for (size_t i = 0; i < count; i += 4) {
        std::uint32_t value = 0;
        value += (i + 0 < data.size() ? data[i + 0] : 0) << 24;
        value += (i + 1 < data.size() ? data[i + 1] : 0) << 16;
        value += (i + 2 < data.size() ? data[i + 2] : 0) << 8;
        value += (i + 3 < data.size() ? data[i + 3] : 0) << 0;

        sum += value;
    }

    return sum;
}

} // namespace

namespace framework::graphics::details::font
{

#pragma region OffsetTable

bool OffsetTable::valid() const
{
    const int exp = max_power_of_2(num_tables);

    const int check_search_range   = static_cast<int>(std::pow(2, exp) * 16);
    const int check_entry_selector = exp;
    const int check_range_shift    = std::max(0, num_tables * 16 - search_range);

    return (sfnt_version == OffsetTable::true_type_tag || sfnt_version == OffsetTable::open_type_tag) &&
           num_tables != 0 && search_range == check_search_range && entry_selector == check_entry_selector &&
           range_shift == check_range_shift;
}

#pragma endregion

#pragma region TableRecord

bool Table::read_data(std::ifstream& in)
{
    in.seekg(record.offset, in.beg);

    data.resize(record.length);
    in.read(reinterpret_cast<char*>(data.data()), record.length);

    return in.good();
}

bool Table::valid() const
{
    auto get_check_sum = [this](const auto& data) {
        std::uint32_t data_check_sum = table_checksum(data);

        if (record.tag == Tag::head) {
            data_check_sum -= utils::big_endian_value<std::uint32_t>(data.data() + 8);
        }

        return data_check_sum;
    };

    const std::uint32_t data_check_sum = get_check_sum(data);
    return data_check_sum == record.check_sum;
}

#pragma endregion

#pragma region headTable

FontHeaderTable FontHeaderTable::read(const std::vector<std::uint8_t>& data)
{
    constexpr size_t table_size = utils::packed_sizeof_v<FontHeaderTable>;

    if (table_size <= data.size()) {
        return utils::big_endian_value<FontHeaderTable>(data.data());
    }

    return FontHeaderTable();
}

#pragma endregion

#pragma region CharacterToGlyphIndexMappingTable

CharacterToGlyphIndexMappingTable CharacterToGlyphIndexMappingTable::read(const std::vector<std::uint8_t>& data)
{
    constexpr size_t table_header_size = (sizeof(CharacterToGlyphIndexMappingTable::version) + sizeof(CharacterToGlyphIndexMappingTable::num_tables));
    constexpr size_t record_size = utils::packed_sizeof_v<CharacterToGlyphIndexMappingTable::EncodingRecord>;
    constexpr size_t version_size = sizeof(CharacterToGlyphIndexMappingTable::version);
    
    if (data.size() < table_header_size) {
        return CharacterToGlyphIndexMappingTable();
    }

    CharacterToGlyphIndexMappingTable table;
    table.version    = utils::big_endian_value<decltype(CharacterToGlyphIndexMappingTable::version)>(data.data());
    table.num_tables = utils::big_endian_value<decltype(CharacterToGlyphIndexMappingTable::num_tables)>(data.data() + version_size);

    if (data.size() < table_header_size + table.num_tables * record_size) {
        return CharacterToGlyphIndexMappingTable();
    }

    table.encoding_records.reserve(table.num_tables);

    size_t offset = table_header_size;
    for (size_t i = 0; i < table.num_tables; ++i) {
        table.encoding_records.push_back(
        utils::big_endian_value<CharacterToGlyphIndexMappingTable::EncodingRecord>(data.data() + offset));
        offset += record_size;
    }

    return table;
}

#pragma endregion

#pragma region HorizontalHeaderTable

HorizontalHeaderTable HorizontalHeaderTable::read(const std::vector<std::uint8_t>& data)
{
    constexpr size_t table_size = utils::packed_sizeof_v<HorizontalHeaderTable>;
    
    if (table_size <= data.size()) {
        return utils::big_endian_value<HorizontalHeaderTable>(data.data());
    }

    return HorizontalHeaderTable();
}

#pragma endregion

#pragma region MaximumProfileTable

MaximumProfileTable MaximumProfileTable::read(std::uint32_t sfnt_version, const std::vector<std::uint8_t>& data)
{
    constexpr size_t true_type_table_size = utils::packed_sizeof_v<MaximumProfileTable>;
    constexpr size_t open_type_table_size = (sizeof(MaximumProfileTable::version) + sizeof(MaximumProfileTable::num_glyphs));


    switch (sfnt_version) {
        case OffsetTable::true_type_tag: 
            if (true_type_table_size <= data.size()) {
                return utils::big_endian_value<MaximumProfileTable>(data.data());
            }
        case OffsetTable::open_type_tag:
            if (open_type_table_size <= data.size()) {
                MaximumProfileTable table;
                table.version    = utils::big_endian_value<decltype(MaximumProfileTable::version)>(data.data());
                table.num_glyphs = utils::big_endian_value<decltype(MaximumProfileTable::num_glyphs)>(data.data());
                return table;
            }
    }

    return MaximumProfileTable();
}

#pragma endregion

#pragma region HorizontalMetricsTable

HorizontalMetricsTable HorizontalMetricsTable::read(std::uint16_t number_of_h_metrics,
                                                    std::uint16_t num_glyphs,
                                                    const std::vector<std::uint8_t>& data)
{
    constexpr size_t metric_size = utils::packed_sizeof_v<HorizontalMetricsTable::Metric>;

    if (data.size() < metric_size * number_of_h_metrics) {
        return HorizontalMetricsTable();
    }

    size_t offset = 0;

    HorizontalMetricsTable table;
    table.metrics.reserve(number_of_h_metrics);
    for (size_t i = 0; i < number_of_h_metrics; ++i) {
        table.metrics.push_back(utils::big_endian_value<HorizontalMetricsTable::Metric>(data.data() + offset));
        offset += metric_size;
    }

    if (num_glyphs > number_of_h_metrics) {
        using LeftSideBearingsType = decltype(HorizontalMetricsTable::left_side_bearings)::value_type;

        constexpr size_t left_side_bearings_size = sizeof(LeftSideBearingsType);
        const size_t left_side_bearings_count = num_glyphs - number_of_h_metrics;

        if (data.size() < offset + left_side_bearings_count * left_side_bearings_size) {
            return HorizontalMetricsTable();
        }

        for (size_t i = 0; i < number_of_h_metrics; ++i) {
            table.left_side_bearings.push_back(utils::big_endian_value<LeftSideBearingsType>(data.data() + offset));
            offset += left_side_bearings_size;
        }
    }

    return table;
}

#pragma endregion

#pragma region Helper Functions

std::vector<TableRecord> read_table_records(std::ifstream& in, std::uint32_t num_tables)
{
    std::vector<TableRecord> records(num_tables);

    for (std::uint32_t i = 0; i < num_tables; i++) {
        records[i] = utils::big_endian_value<TableRecord>(in);
        if (!in) {
            return std::vector<TableRecord>();
        }
    }

    std::sort(records.begin(), records.end(), [](const TableRecord& a, const TableRecord& b) {
        return a.offset < b.offset;
    });

    return records;
}

bool has_required_tables(const std::vector<TableRecord>& records)
{
    constexpr std::array<Tag, 8> common_required_tags =
    {Tag::cmap, Tag::head, Tag::hhea, Tag::hmtx, Tag::maxp, Tag::name, Tag::OS2, Tag::post};

    for (const Tag tag : common_required_tags) {
        const auto it = std::find_if(records.begin(), records.end(), [tag](const TableRecord& record) {
            return record.tag == tag;
        });

        if (it == records.end()) {
            return false;
        }
    }

    return true;
}

#pragma endregion

} // namespace framework::graphics::details::font
