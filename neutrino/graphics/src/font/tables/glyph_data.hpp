#ifndef GRAPHICS_SRC_FONT_TABLES_GLYPH_DATA_HPP
#define GRAPHICS_SRC_FONT_TABLES_GLYPH_DATA_HPP

#include <unordered_map>
#include <vector>

#include <math/math.hpp>

#include <graphics/src/font/types.hpp>

namespace framework::graphics::details::font
{

class GlyphData final
{
public:
    struct ControlPoint
    {
        math::Vector2f position;
        bool is_on_curve = false;
    };

    using ContourType = std::vector<ControlPoint>;
    using Contours    = std::vector<ContourType>;

    GlyphData(std::uint16_t num_glyphs, const std::vector<Offset32>& offsets, const BytesData& data);

    bool valid() const;

    bool has(GlyphId index) const;
    const Contours& at(GlyphId index) const;

private:
    std::unordered_map<GlyphId, Contours> m_glyphs;
};

} // namespace framework::graphics::details::font

#endif
