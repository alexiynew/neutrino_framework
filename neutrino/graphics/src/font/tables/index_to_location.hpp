#ifndef FRAMEWORK_GRAPHICS_SRC_FONT_TABLES_INDEX_TO_LOCATION_HPP
#define FRAMEWORK_GRAPHICS_SRC_FONT_TABLES_INDEX_TO_LOCATION_HPP

#include <vector>

#include <graphics/src/font/types.hpp>

namespace framework::graphics::details::font
{

class IndexToLocation
{
public:
    IndexToLocation(std::int16_t index_to_loc_format, std::uint16_t num_glyphs, const std::vector<std::uint8_t>& data);

    bool valid() const;

private:
    std::vector<Offset32> m_offsets;
};

} // namespace framework::graphics::details::font

#endif
