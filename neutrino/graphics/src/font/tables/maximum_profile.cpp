#include <common/utils.hpp>

#include <graphics/src/font/tables/maximum_profile.hpp>

namespace framework::graphics::details::font
{

MaximumProfile MaximumProfile::parse(const std::vector<std::uint8_t>& data)
{
    MaximumProfile table;

    table.version    = utils::big_endian_value<Fixed>(data.begin());
    table.num_glyphs = utils::big_endian_value<std::uint16_t>(data.begin() + 4);

    if (table.version == 0x00010000) {
        table.max_points               = utils::big_endian_value<std::uint16_t>(data.begin() + 6);
        table.max_contours             = utils::big_endian_value<std::uint16_t>(data.begin() + 8);
        table.max_composite_points     = utils::big_endian_value<std::uint16_t>(data.begin() + 10);
        table.max_composite_contours   = utils::big_endian_value<std::uint16_t>(data.begin() + 12);
        table.max_zones                = utils::big_endian_value<std::uint16_t>(data.begin() + 14);
        table.max_twilight_points      = utils::big_endian_value<std::uint16_t>(data.begin() + 16);
        table.max_storage              = utils::big_endian_value<std::uint16_t>(data.begin() + 18);
        table.max_function_defs        = utils::big_endian_value<std::uint16_t>(data.begin() + 20);
        table.max_instruction_defs     = utils::big_endian_value<std::uint16_t>(data.begin() + 22);
        table.max_stack_elements       = utils::big_endian_value<std::uint16_t>(data.begin() + 24);
        table.max_size_of_instructions = utils::big_endian_value<std::uint16_t>(data.begin() + 26);
        table.max_component_elements   = utils::big_endian_value<std::uint16_t>(data.begin() + 28);
        table.max_component_depth      = utils::big_endian_value<std::uint16_t>(data.begin() + 30);
    }

    return table;
}

bool MaximumProfile::valid() const
{
    bool valid = true;

    valid &= version == 0x00010000 || version == 0x00005000;
    valid &= num_glyphs != 0;

    return valid;
}

} // namespace framework::graphics::details::font
