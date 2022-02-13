#include <common/utils.hpp>

#include <graphics/src/font/tables/horizontal_metrics.hpp>

namespace framework::graphics::details::font
{

HorizontalMetrics HorizontalMetrics::parse(std::uint16_t number_of_h_metrics,
                                           std::uint16_t num_glyphs,
                                           const std::vector<std::uint8_t>& data)
{
    auto from = data.begin();

    HorizontalMetrics table;
    table.metrics.reserve(number_of_h_metrics);
    for (size_t i = 0; i < number_of_h_metrics; ++i) {
        HorizontalMetrics::Metric metric;
        metric.advance_width = utils::big_endian_value<std::uint16_t>(from);
        metric.lsb           = utils::big_endian_value<std::int16_t>(from + 2);

        table.metrics.push_back(metric);
        std::advance(from, 4);
    }

    if (num_glyphs > number_of_h_metrics) {
        for (size_t i = 0; i < number_of_h_metrics; ++i) {
            table.left_side_bearings.push_back(utils::big_endian_value<std::int16_t>(from));
            std::advance(from, 2);
        }
    }

    return table;
}

bool HorizontalMetrics::valid() const
{
    return true;
}

} // namespace framework::graphics::details::font
