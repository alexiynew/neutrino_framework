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

using FWord    = std::int16_t;  // int16 that describes a quantity in font design units.
using UFWord   = std::uint16_t; // uint16 that describes a quantity in font design units.
using Fixed    = std::int32_t;  // 32-bit signed fixed-point number (16.16)
using DateTime = std::int64_t;  // Date represented in number of seconds since 12:00 midnight, January 1, 1904.
using F2Dot14  = std::int16_t;  // 16-bit signed fixed number with the low 14 bits of fraction (2.14).

struct FontHeaderTable
{
    static FontHeaderTable read(const std::vector<std::uint8_t>& data);

    std::uint16_t major_version        = 0;
    std::uint16_t minor_version        = 0;
    Fixed font_revision                = 0;
    std::uint32_t check_sum_adjustment = 0;
    std::uint32_t magic_number         = 0;
    std::uint16_t flags                = 0;
    std::uint16_t units_per_em         = 0;
    DateTime created                   = 0;
    DateTime modified                  = 0;
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

struct CharacterToGlyphIndexMappingTable
{
    struct EncodingRecord
    {
        std::uint16_t platform_id = 0; // Platform ID.
        std::uint16_t encoding_id = 0; // Platform-specific encoding ID.
        std::uint32_t offset      = 0; // Byte offset from beginning of table to the subtable for this encoding.
    };

    static CharacterToGlyphIndexMappingTable read(const std::vector<std::uint8_t>& data);

    std::uint16_t version    = 0;
    std::uint16_t num_tables = 0;
    std::vector<EncodingRecord> encoding_records;
};

struct HorizontalHeaderTable
{
    static HorizontalHeaderTable read(const std::vector<std::uint8_t>& data);

    std::uint16_t major_version       = 0;
    std::uint16_t minor_version       = 0;
    FWord ascender                    = 0;
    FWord descender                   = 0;
    FWord line_gap                    = 0;
    UFWord advance_width_max          = 0;
    FWord min_left_side_bearing       = 0;
    FWord min_right_side_bearing      = 0;
    FWord x_max_extent                = 0;
    std::int16_t caret_slope_rise     = 0;
    std::int16_t caret_slope_run      = 0;
    std::int16_t caret_offset         = 0;
    std::int16_t reserved1            = 0;
    std::int16_t reserved2            = 0;
    std::int16_t reserved3            = 0;
    std::int16_t reserved4            = 0;
    std::int16_t metric_data_format   = 0;
    std::uint16_t number_of_h_metrics = 0;
};

struct MaximumProfileTable
{
    static MaximumProfileTable read(std::uint32_t sfnt_version, const std::vector<std::uint8_t>& data);

    Fixed version                          = 0;
    std::uint16_t num_glyphs               = 0;
    std::uint16_t max_points               = 0;
    std::uint16_t max_contours             = 0;
    std::uint16_t max_composite_points     = 0;
    std::uint16_t max_composite_contours   = 0;
    std::uint16_t max_zones                = 0;
    std::uint16_t max_twilight_points      = 0;
    std::uint16_t max_storage              = 0;
    std::uint16_t max_function_defs        = 0;
    std::uint16_t max_instruction_defs     = 0;
    std::uint16_t max_stack_elements       = 0;
    std::uint16_t max_size_of_instructions = 0;
    std::uint16_t max_component_elements   = 0;
    std::uint16_t max_component_depth      = 0;
};

struct HorizontalMetricsTable
{
    struct Metric
    {
        std::uint16_t advance_width = 0; // Advance width, in font design units.
        std::int16_t lsb            = 0; // Glyph left side bearing, in font design units.
    };

    static HorizontalMetricsTable read(std::uint16_t number_of_h_metrics,
                                       std::uint16_t num_glyphs,
                                       const std::vector<std::uint8_t>& data);

    std::vector<Metric> metrics; // [number_of_h_metrics]
                                 // Paired advance width and left side bearing values for each glyph.

    std::vector<std::int16_t> left_side_bearings; // [num_glyphs - number_of_h_metrics]
                                                  // Left side bearings for glyph IDs greater than or equal to
                                                  // number_of_h_metrics. Records are indexed by glyph ID.
};

#pragma endregion

#pragma region Helper Functions

std::vector<TableRecord>
read_table_records(std::ifstream& in, std::uint32_t num_tables);

bool has_required_tables(const std::vector<TableRecord>& records);

#pragma endregion

} // namespace framework::graphics::details::font

#endif
