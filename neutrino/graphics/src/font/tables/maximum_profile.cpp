#include <common/utils.hpp>

#include <graphics/src/font/tables/maximum_profile.hpp>

namespace framework::graphics::details::font
{

MaximumProfile MaximumProfile::parse(const std::vector<std::uint8_t>& data)
{
    MaximumProfile table;

    table.version    = utils::big_endian_value<Fixed>(data.begin(), data.end());
    table.num_glyphs = utils::big_endian_value<std::uint16_t>(data.begin() + 4, data.end());

    if (table.version == 0x00010000) {
        table.max_points               = utils::big_endian_value<std::uint16_t>(data.begin() + 6, data.end());
        table.max_contours             = utils::big_endian_value<std::uint16_t>(data.begin() + 8, data.end());
        table.max_composite_points     = utils::big_endian_value<std::uint16_t>(data.begin() + 10, data.end());
        table.max_composite_contours   = utils::big_endian_value<std::uint16_t>(data.begin() + 12, data.end());
        table.max_zones                = utils::big_endian_value<std::uint16_t>(data.begin() + 14, data.end());
        table.max_twilight_points      = utils::big_endian_value<std::uint16_t>(data.begin() + 16, data.end());
        table.max_storage              = utils::big_endian_value<std::uint16_t>(data.begin() + 18, data.end());
        table.max_function_defs        = utils::big_endian_value<std::uint16_t>(data.begin() + 20, data.end());
        table.max_instruction_defs     = utils::big_endian_value<std::uint16_t>(data.begin() + 22, data.end());
        table.max_stack_elements       = utils::big_endian_value<std::uint16_t>(data.begin() + 24, data.end());
        table.max_size_of_instructions = utils::big_endian_value<std::uint16_t>(data.begin() + 26, data.end());
        table.max_component_elements   = utils::big_endian_value<std::uint16_t>(data.begin() + 28, data.end());
        table.max_component_depth      = utils::big_endian_value<std::uint16_t>(data.begin() + 30, data.end());
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
