#include <common/utils.hpp>

#include <graphics/src/font/tables/glyph_data.hpp>

namespace
{

struct SimpleGlyph
{
    std::vector<std::uint16_t> end_pts_of_contours; // [number_of_contours]
    std::uint16_t instruction_length = 0;
    std::vector<std::uint8_t> instructions; // [instruction_length]
    std::vector<std::uint8_t> flags;        // [variable]

    // std::vector<std::uint8_t or std::int16_t> x_coordinates; // [variable]
    // std::vector<std::uint8_t or std::int16_t> y_coordinates; // [variable]
};

} // namespace

namespace framework::graphics::details::font
{

GlyphData::GlyphData(std::uint16_t num_glyphs,
                     const std::vector<Offset32>& offsets,
                     const std::vector<std::uint8_t>& data)
{
    m_glyphs.reserve(num_glyphs);

    for (GlyphId i = 0; i < num_glyphs; ++i) {
        const auto from = std::next(data.begin(), offsets[i]);

        GlyphHeader& header = m_glyphs[i].header;

        header.number_of_contours = utils::big_endian_value<std::int16_t>(from, data.end());
        header.x_min              = utils::big_endian_value<std::int16_t>(from + 2, data.end());
        header.y_min              = utils::big_endian_value<std::int16_t>(from + 4, data.end());
        header.x_max              = utils::big_endian_value<std::int16_t>(from + 6, data.end());
        header.y_max              = utils::big_endian_value<std::int16_t>(from + 8, data.end());
    }
}

bool GlyphData::valid() const
{
    return false;
}

} // namespace framework::graphics::details::font
