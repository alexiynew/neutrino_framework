#ifndef FRAMEWORK_GRAPHICS_SRC_FONT_TABLES_HORIZONTAL_METRICS_HPP
#define FRAMEWORK_GRAPHICS_SRC_FONT_TABLES_HORIZONTAL_METRICS_HPP

#include <vector>

#include <graphics/src/font/types.hpp>

namespace framework::graphics::details::font
{

struct HorizontalMetrics
{
    struct Metric
    {
        std::uint16_t advance_width = 0;
        std::int16_t lsb            = 0;
    };

    static HorizontalMetrics parse(std::uint16_t number_of_h_metrics,
                                   std::uint16_t num_glyphs,
                                   const std::vector<std::uint8_t>& data);

    bool valid() const;

    std::vector<Metric> metrics;
    std::vector<std::int16_t> left_side_bearings;
};

} // namespace framework::graphics::details::font

#endif
