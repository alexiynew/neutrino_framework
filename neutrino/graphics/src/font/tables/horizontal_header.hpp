#ifndef GRAPHICS_SRC_FONT_TABLES_HORIZONTAL_HEADER_HPP
#define GRAPHICS_SRC_FONT_TABLES_HORIZONTAL_HEADER_HPP

#include <vector>

#include <graphics/src/font/types.hpp>

namespace framework::graphics::details::font
{

class HorizontalHeader final
{
public:
    explicit HorizontalHeader(const BytesData& data);

    bool valid() const;

    std::uint16_t number_of_h_metrics() const;

private:
    std::uint16_t m_major_version       = 0;
    std::uint16_t m_minor_version       = 0;
    FWord m_ascender                    = 0;
    FWord m_descender                   = 0;
    FWord m_line_gap                    = 0;
    UFWord m_advance_width_max          = 0;
    FWord m_min_left_side_bearing       = 0;
    FWord m_min_right_side_bearing      = 0;
    FWord m_x_max_extent                = 0;
    std::int16_t m_caret_slope_rise     = 0;
    std::int16_t m_caret_slope_run      = 0;
    std::int16_t m_caret_offset         = 0;
    std::int16_t m_metric_data_format   = 0;
    std::uint16_t m_number_of_h_metrics = 0;
};

} // namespace framework::graphics::details::font

#endif
