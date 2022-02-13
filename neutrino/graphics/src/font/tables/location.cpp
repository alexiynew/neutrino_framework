#include <common/utils.hpp>

#include <graphics/src/font/tables/location.hpp>

namespace framework::graphics::details::font
{

Location Location::parse(std::int16_t format, std::uint16_t num_glyphs, const std::vector<std::uint8_t>& data)
{
    const size_t size = num_glyphs + 1;

    Location table;

    table.offsets.reserve(size);

    auto from = data.begin();
    for (size_t i = 0; i < num_glyphs; ++i) {
        switch (format) {
            case 0:
                table.offsets.push_back(utils::big_endian_value<Offset16>(from));
                std::advance(from, sizeof(Offset16));
                break;

            case 1:
                table.offsets.push_back(utils::big_endian_value<Offset32>(from));
                std::advance(from, sizeof(Offset32));
                break;
        }
    }

    return table;
}

} // namespace framework::graphics::details::font
