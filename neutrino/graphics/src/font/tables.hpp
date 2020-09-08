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

#ifndef FRAMEWORK_GRAPHICS_SRC_FONT_TABLES_HPP
#define FRAMEWORK_GRAPHICS_SRC_FONT_TABLES_HPP

#include <cstdint>
#include <fstream>

#include <graphics/src/font/tags.hpp>

namespace framework::graphics::details::font
{

#pragma region Font Headers

struct OffsetTable
{
    inline static constexpr std::uint32_t true_type_tag = 0x00010000;
    inline static constexpr std::uint32_t open_type_tag = 0x4F54544F;

    bool valid() const;

    std::uint32_t sfnt_version   = 0;
    std::uint16_t num_tables     = 0;
    std::uint16_t search_range   = 0;
    std::uint16_t entry_selector = 0;
    std::uint16_t range_shift    = 0;
};

struct TableRecord
{
    Tag tag                 = Tag::invalid;
    std::uint32_t check_sum = 0;
    std::uint32_t offset    = 0;
    std::uint32_t length    = 0;
};

struct Table
{
    bool read_data(std::ifstream& in);
    bool valid() const;

    TableRecord record;
    std::vector<std::uint8_t> data;
};

#pragma endregion

#pragma region Font Tables

struct headTable
{
    std::uint16_t major_version        = 0;
    std::uint16_t minor_version        = 0;
    std::uint32_t font_revision        = 0; // Fixed type
    std::uint32_t check_sum_adjustment = 0;
    std::uint32_t magic_number         = 0;
    std::uint16_t flags                = 0;
    std::uint16_t units_per_em         = 0;
    std::int64_t created               = 0; // LONGDATETIME
    std::int64_t modified              = 0; // LONGDATETIME
    std::int16_t x_min                 = 0;
    std::int16_t y_min                 = 0;
    std::int16_t x_max                 = 0;
    std::int16_t y_max                 = 0;
    std::uint16_t mac_style            = 0;
    std::uint16_t lowest_rec_ppem      = 0;
    std::int16_t font_direction_hint   = 0;
    std::int16_t index_to_loc_format   = 0;
    std::int16_t glyph_data_format     = 0;
};

struct cmapTable
{
    struct EncodingRecord
    {
        static EncodingRecord read(std::ifstream& in);

        std::uint16_t platform_id = 0; // Platform ID.
        std::uint16_t encoding_id = 0; // Platform-specific encoding ID.
        std::uint32_t offset      = 0; // Byte offset from beginning of table to the subtable for this encoding.
    };

    static cmapTable read(std::ifstream& in, const TableRecord& record);

    std::uint16_t version    = 0;
    std::uint16_t num_tables = 0;
    std::vector<EncodingRecord> encoding_records;
};

#pragma endregion

#pragma region Helper Functions

std::vector<TableRecord> read_table_records(std::ifstream& in, std::uint32_t num_tables);

bool has_required_tables(const std::vector<TableRecord>& records);

#pragma endregion

} // namespace framework::graphics::details::font

#endif
