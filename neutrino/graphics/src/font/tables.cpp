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


#pragma endregion

#pragma region cmapTable

// cmapTable cmapTable::read(std::ifstream& in, const TableRecord& record)
//{
//    char buffer[TableRecord::size];
//    in.read(buffer, TableRecord::size);
//}
//
// bool cmapTable::valid() const
//{}

#pragma endregion

#pragma region Helper Functions

std::vector<TableRecord> read_table_records(std::ifstream& in, std::uint32_t num_tables)
{
    std::vector<TableRecord> records(num_tables);

    for (std::uint32_t i = 0; i < num_tables; i++) {
        records[i] = utils::big_endian_value<TableRecord>(in);
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
