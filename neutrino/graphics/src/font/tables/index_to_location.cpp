#include <common/utils.hpp>

#include <graphics/src/font/tables/index_to_location.hpp>

namespace framework::graphics::details::font
{

IndexToLocation::IndexToLocation(std::int16_t index_to_loc_format, std::uint16_t num_glyphs, const BytesData& data)
{
    const size_t size = num_glyphs + 1;

    m_offsets.reserve(size);

    auto in = utils::make_big_endian_buffer_reader(data);
    for (size_t i = 0; i < size; ++i) {
        switch (index_to_loc_format) {
            case 0: m_offsets.push_back(in.get<Offset16>() * 2); break;
            case 1: m_offsets.push_back(in.get<Offset32>()); break;
        }
    }
}

bool IndexToLocation::is_valid() const
{
    return m_offsets.size() != 0 && m_offsets[0] == 0;
}

const std::vector<Offset32>& IndexToLocation::offsets() const
{
    return m_offsets;
}

} // namespace framework::graphics::details::font
