
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
    class GlyphHeader
    {
    public:
        explicit GlyphHeader(BufferReader& in);

        bool is_simple_glyph() const;

        std::int16_t number_of_contours() const;
        std::int16_t x_min() const;
        std::int16_t y_min() const;
        std::int16_t x_max() const;
        std::int16_t y_max() const;

    private:
        std::int16_t m_number_of_contours = 0;
        std::int16_t m_x_min              = 0;
        std::int16_t m_y_min              = 0;
        std::int16_t m_x_max              = 0;
        std::int16_t m_y_max              = 0;
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

    struct CompositeGlyphComponent
    {
        std::uint16_t flags       = 0;
        std::uint16_t glyph_index = 0;
        std::int32_t argument1    = 0;
        std::int32_t argument2    = 0;

        F2Dot14 scale   = 0;
        F2Dot14 xscale  = 0;
        F2Dot14 scale01 = 0;
        F2Dot14 scale10 = 0;
        F2Dot14 yscale  = 0;
    };

    struct CompositeGlyph
    {
        std::vector<CompositeGlyphComponent> components;

        std::uint16_t instruction_length = 0;
        std::vector<std::uint8_t> instructions; // [instruction_length]
    };

    class Glyph
    {
    public:
        explicit Glyph(BufferReader& in);

        const GlyphHeader& header() const;
        const SimpleGlyph& simple_glyph() const;
        const CompositeGlyph& composite_glyph() const;

    private:
        GlyphHeader m_header;
        SimpleGlyph m_simple_glyph;
        CompositeGlyph m_composite_glyph;
    };

    GlyphData(std::uint16_t num_glyphs, const std::vector<Offset32>& offsets, const BytesData& data);

    bool valid() const;

    const Glyph& at(GlyphId index) const;

private:
    std::unordered_map<GlyphId, Glyph> m_glyphs;
};

} // namespace framework::graphics::details::font

#endif
