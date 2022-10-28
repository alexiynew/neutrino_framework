#ifndef GRAPHICS_SRC_FONT_TABLES_INDEX_TO_LOCATION_HPP
#define GRAPHICS_SRC_FONT_TABLES_INDEX_TO_LOCATION_HPP

#include <vector>

#include <graphics/src/font/types.hpp>

namespace framework::graphics::details::font
{

class IndexToLocation final
{
public:
    IndexToLocation(std::int16_t index_to_loc_format, std::uint16_t num_glyphs, const BytesData& data);

    bool is_valid() const;

    const std::vector<Offset32>& offsets() const;

private:
    std::vector<Offset32> m_offsets;
};

} // namespace framework::graphics::details::font

#endif
