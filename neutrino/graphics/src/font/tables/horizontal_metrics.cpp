#include <common/utils.hpp>

#include <graphics/src/font/tables/horizontal_metrics.hpp>

namespace framework::graphics::details::font
{

HorizontalMetrics::HorizontalMetrics(std::uint16_t number_of_h_metrics, std::uint16_t num_glyphs, const BytesData& data)
{
    auto in = utils::make_big_endian_buffer_reader(data);

    m_metrics.reserve(number_of_h_metrics);
    for (size_t i = 0; i < number_of_h_metrics; ++i) {
        HorizontalMetrics::LongHorMetricRecord metric;
        in >> metric.advance_width;
        in >> metric.lsb;

        m_metrics.push_back(metric);
    }

    if (num_glyphs > number_of_h_metrics) {
        const size_t bearings_count = num_glyphs - number_of_h_metrics;
        for (size_t i = 0; i < bearings_count; ++i) {
            m_left_side_bearings.push_back(in.get<std::int16_t>());
        }
    }
}

bool HorizontalMetrics::valid() const
{
    return m_metrics.size() != 0 || m_left_side_bearings.size() != 0;
}

} // namespace framework::graphics::details::font
