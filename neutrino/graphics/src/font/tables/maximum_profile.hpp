#ifndef FRAMEWORK_GRAPHICS_SRC_FONT_TABLES_MAXIMUM_PROFILE_HPP
#define FRAMEWORK_GRAPHICS_SRC_FONT_TABLES_MAXIMUM_PROFILE_HPP

#include <vector>

#include <graphics/src/font/types.hpp>

namespace framework::graphics::details::font
{

struct MaximumProfile
{
    static MaximumProfile parse(const std::vector<std::uint8_t>& data);

    bool valid() const;

    Fixed version            = 0;
    std::uint16_t num_glyphs = 0;

    // for version 1.0 only
    std::uint16_t max_points               = 0;
    std::uint16_t max_contours             = 0;
    std::uint16_t max_composite_points     = 0;
    std::uint16_t max_composite_contours   = 0;
    std::uint16_t max_zones                = 0;
    std::uint16_t max_twilight_points      = 0;
    std::uint16_t max_storage              = 0;
    std::uint16_t max_function_defs        = 0;
    std::uint16_t max_instruction_defs     = 0;
    std::uint16_t max_stack_elements       = 0;
    std::uint16_t max_size_of_instructions = 0;
    std::uint16_t max_component_elements   = 0;
    std::uint16_t max_component_depth      = 0;
};

} // namespace framework::graphics::details::font

#endif
