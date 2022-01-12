#ifndef FRAMEWORK_GRAPHICS_SRC_FONT_TABLES_LOCATION_HPP
#define FRAMEWORK_GRAPHICS_SRC_FONT_TABLES_LOCATION_HPP

#include <vector>

#include <graphics/src/font/types.hpp>

namespace framework::graphics::details::font
{

struct Location
{
    static Location parse(std::int16_t format, std::uint16_t num_glyphs, const std::vector<std::uint8_t>& data);

    std::vector<Offset32> offsets;
};

} // namespace framework::graphics::details::font

#endif
