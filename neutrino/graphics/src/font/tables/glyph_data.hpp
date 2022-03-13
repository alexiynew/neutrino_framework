
#ifndef FRAMEWORK_GRAPHICS_SRC_FONT_TABLES_GLYPH_DATA_HPP
#define FRAMEWORK_GRAPHICS_SRC_FONT_TABLES_GLYPH_DATA_HPP

#include <unordered_map>
#include <vector>

#include <math/math.hpp>

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

    class Glyph
    {
    public:
        struct ControlPoint
        {
            math::Vector2f position;
            bool is_on_curve = false;
        };

        using ContourType = std::vector<ControlPoint>;

        explicit Glyph(BufferReader& in);

        const GlyphHeader& header() const;
        const std::vector<ContourType>& contours() const;

    private:
        GlyphHeader m_header;
        std::vector<ContourType> m_contours;
    };

    GlyphData(std::uint16_t num_glyphs, const std::vector<Offset32>& offsets, const BytesData& data);

    bool valid() const;

    const Glyph& at(GlyphId index) const;

private:
    std::unordered_map<GlyphId, Glyph> m_glyphs;
};

} // namespace framework::graphics::details::font

#endif
