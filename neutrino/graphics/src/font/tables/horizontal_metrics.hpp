#ifndef GRAPHICS_SRC_FONT_TABLES_HORIZONTAL_METRICS_HPP
#define GRAPHICS_SRC_FONT_TABLES_HORIZONTAL_METRICS_HPP

#include <vector>

#include <graphics/src/font/types.hpp>

namespace framework::graphics::details::font
{

class HorizontalMetrics final
{
public:
    HorizontalMetrics(std::uint16_t number_of_h_metrics, std::uint16_t num_glyphs, const BytesData& data);

    bool valid() const;
    std::uint16_t advance_width(GlyphId id) const;
    std::int16_t left_sidebearing(GlyphId id) const;

private:
    struct LongHorMetricRecord
    {
        std::uint16_t advance_width = 0;
        std::int16_t lsb            = 0;
    };

    std::vector<LongHorMetricRecord> m_metrics;
    std::vector<std::int16_t> m_left_side_bearings;
};

} // namespace framework::graphics::details::font

#endif
