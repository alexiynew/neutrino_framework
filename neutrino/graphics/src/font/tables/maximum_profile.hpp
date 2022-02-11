#ifndef FRAMEWORK_GRAPHICS_SRC_FONT_TABLES_MAXIMUM_PROFILE_HPP
#define FRAMEWORK_GRAPHICS_SRC_FONT_TABLES_MAXIMUM_PROFILE_HPP

#include <vector>

#include <graphics/src/font/types.hpp>

namespace framework::graphics::details::font
{

class MaximumProfile final
{
public:
    inline static constexpr std::uint32_t true_type_version = 0x00010000;
    inline static constexpr std::uint32_t open_type_vetsion = 0x00005000;

    explicit MaximumProfile(const std::vector<std::uint8_t>& data);

    bool valid() const;

    Fixed version() const;
    std::uint16_t num_glyphs() const;

private:
    Fixed m_version            = 0;
    std::uint16_t m_num_glyphs = 0;

    // for version 1.0 only
    std::uint16_t m_max_points               = 0;
    std::uint16_t m_max_contours             = 0;
    std::uint16_t m_max_composite_points     = 0;
    std::uint16_t m_max_composite_contours   = 0;
    std::uint16_t m_max_zones                = 0;
    std::uint16_t m_max_twilight_points      = 0;
    std::uint16_t m_max_storage              = 0;
    std::uint16_t m_max_function_defs        = 0;
    std::uint16_t m_max_instruction_defs     = 0;
    std::uint16_t m_max_stack_elements       = 0;
    std::uint16_t m_max_size_of_instructions = 0;
    std::uint16_t m_max_component_elements   = 0;
    std::uint16_t m_max_component_depth      = 0;
};

} // namespace framework::graphics::details::font

#endif
