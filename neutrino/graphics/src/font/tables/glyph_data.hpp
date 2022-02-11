
#ifndef FRAMEWORK_GRAPHICS_SRC_FONT_TABLES_GLYPH_DATA_HPP
#define FRAMEWORK_GRAPHICS_SRC_FONT_TABLES_GLYPH_DATA_HPP

#include <unordered_map>
#include <vector>

#include <graphics/src/font/types.hpp>

namespace framework::graphics::details::font
{

class GlyphData final
{
public:
    GlyphData(std::uint16_t num_glyphs, const std::vector<Offset32>& offsets, const std::vector<std::uint8_t>& data);

    bool valid() const;

private:
    struct GlyphHeader
    {
        std::int16_t number_of_contours = 0;
        std::int16_t x_min              = 0;
        std::int16_t y_min              = 0;
        std::int16_t x_max              = 0;
        std::int16_t y_max              = 0;
    };

    struct Glyph
    {
        GlyphHeader header;
    };

    std::unordered_map<GlyphId, Glyph> m_glyphs;
};

} // namespace framework::graphics::details::font

#endif