#include <common/utils.hpp>

#include <graphics/src/font/tables/horizontal_metrics.hpp>

namespace neutrino::graphics::details::font
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

bool HorizontalMetrics::is_valid() const
{
    return m_metrics.size() != 0 || m_left_side_bearings.size() != 0;
}

std::uint16_t HorizontalMetrics::advance_width(GlyphId id) const
{
    if (m_metrics.size() > id) {
        return m_metrics[id].advance_width;
    }
    return m_metrics.back().advance_width;
}

std::int16_t HorizontalMetrics::left_sidebearing(GlyphId id) const
{
    if (m_metrics.size() > id) {
        return m_metrics[id].lsb;
    }

    return m_left_side_bearings.at(static_cast<GlyphId>(id - m_metrics.size()));
}

} // namespace neutrino::graphics::details::font
