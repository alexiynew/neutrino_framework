
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
    struct GlyphHeader
    {
        std::int16_t number_of_contours = 0;
        std::int16_t x_min              = 0;
        std::int16_t y_min              = 0;
        std::int16_t x_max              = 0;
        std::int16_t y_max              = 0;
    };

    struct SimpleGlyph
    {
        std::vector<std::uint16_t> end_pts_of_contours; // [number_of_contours]
        std::uint16_t instruction_length = 0;
        std::vector<std::uint8_t> instructions; // [instruction_length]
        std::vector<std::uint8_t> flags;        // [end_pts_of_contours.back() + 1]

        // It's called coordinates,
        // BUT it's actually offset from the previous point with (0,0) as the implicit first point.
        std::vector<std::int16_t> x_coordinates; // [end_pts_of_contours.back() + 1]
        std::vector<std::int16_t> y_coordinates; // [end_pts_of_contours.back() + 1]
    };

    struct Glyph
    {
        GlyphHeader header;
        SimpleGlyph data;
    };

    GlyphData(std::uint16_t num_glyphs, const std::vector<Offset32>& offsets, const std::vector<std::uint8_t>& data);

    bool valid() const;

private:
    std::unordered_map<GlyphId, Glyph> m_glyphs;
};

} // namespace framework::graphics::details::font

#endif