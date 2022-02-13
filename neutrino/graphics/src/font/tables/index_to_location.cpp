#include <common/utils.hpp>

#include <graphics/src/font/tables/index_to_location.hpp>

namespace framework::graphics::details::font
{

IndexToLocation::IndexToLocation(std::int16_t index_to_loc_format,
                                 std::uint16_t num_glyphs,
                                 const std::vector<std::uint8_t>& data)
{
    const size_t size = num_glyphs + 1;

    m_offsets.reserve(size);

    auto from = data.begin();
    for (size_t i = 0; i < size; ++i) {
        switch (index_to_loc_format) {
            case 0: {
                const Offset16 offset = utils::big_endian_value<Offset16>(from);
                m_offsets.push_back(offset * 2);
                std::advance(from, sizeof(Offset16));
            } break;

            case 1: {
                m_offsets.push_back(utils::big_endian_value<Offset32>(from));
                std::advance(from, sizeof(Offset32));
            } break;
        }
    }
}

bool IndexToLocation::valid() const
{
    return m_offsets.size() != 0 && m_offsets[0] == 0;
}

const std::vector<Offset32>& IndexToLocation::offsets() const
{
    return m_offsets;
}

} // namespace framework::graphics::details::font
