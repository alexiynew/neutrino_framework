#ifndef FRAMEWORK_GRAPHICS_SRC_FONT_TABLES_HORIZONTAL_HEADER_HPP
#define FRAMEWORK_GRAPHICS_SRC_FONT_TABLES_HORIZONTAL_HEADER_HPP

#include <vector>

#include <graphics/src/font/types.hpp>

namespace framework::graphics::details::font
{

struct HorizontalHeader
{
    static HorizontalHeader parse(const std::vector<std::uint8_t>& data);

    bool valid() const;

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

} // namespace framework::graphics::details::font

#endif
