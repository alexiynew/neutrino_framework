#ifndef FRAMEWORK_GRAPHICS_SRC_FONT_TABLES_FONT_HEADER_HPP
#define FRAMEWORK_GRAPHICS_SRC_FONT_TABLES_FONT_HEADER_HPP

#include <vector>

#include <graphics/src/font/types.hpp>

namespace framework::graphics::details::font
{

struct FontHeader
{
    static FontHeader parse(const std::vector<std::uint8_t>& data);

    bool valid() const;

    std::uint16_t major_version        = 0;
    std::uint16_t minor_version        = 0;
    Fixed font_revision                = 0;
    std::uint32_t check_sum_adjustment = 0;
    std::uint32_t magic_number         = 0;
    std::uint16_t flags                = 0;
    std::uint16_t units_per_em         = 0;
    DateTime created                   = 0;
    DateTime modified                  = 0;
    std::int16_t x_min                 = 0;
    std::int16_t y_min                 = 0;
    std::int16_t x_max                 = 0;
    std::int16_t y_max                 = 0;
    std::uint16_t mac_style            = 0;
    std::uint16_t lowest_rec_ppem      = 0;
    std::int16_t font_direction_hint   = 0;
    std::int16_t index_to_loc_format   = 0;
    std::int16_t glyph_data_format     = 0;
};

} // namespace framework::graphics::details::font

#endif
