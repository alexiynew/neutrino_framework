#include <common/utils.hpp>

#include <graphics/src/font/tables/maximum_profile.hpp>

namespace framework::graphics::details::font
{

MaximumProfile::MaximumProfile(const std::vector<std::uint8_t>& data)
{
    m_version    = utils::big_endian_value<Fixed>(data.begin());
    m_num_glyphs = utils::big_endian_value<std::uint16_t>(data.begin() + 4);

    if (m_version == 0x00010000) {
        m_max_points               = utils::big_endian_value<std::uint16_t>(data.begin() + 6);
        m_max_contours             = utils::big_endian_value<std::uint16_t>(data.begin() + 8);
        m_max_composite_points     = utils::big_endian_value<std::uint16_t>(data.begin() + 10);
        m_max_composite_contours   = utils::big_endian_value<std::uint16_t>(data.begin() + 12);
        m_max_zones                = utils::big_endian_value<std::uint16_t>(data.begin() + 14);
        m_max_twilight_points      = utils::big_endian_value<std::uint16_t>(data.begin() + 16);
        m_max_storage              = utils::big_endian_value<std::uint16_t>(data.begin() + 18);
        m_max_function_defs        = utils::big_endian_value<std::uint16_t>(data.begin() + 20);
        m_max_instruction_defs     = utils::big_endian_value<std::uint16_t>(data.begin() + 22);
        m_max_stack_elements       = utils::big_endian_value<std::uint16_t>(data.begin() + 24);
        m_max_size_of_instructions = utils::big_endian_value<std::uint16_t>(data.begin() + 26);
        m_max_component_elements   = utils::big_endian_value<std::uint16_t>(data.begin() + 28);
        m_max_component_depth      = utils::big_endian_value<std::uint16_t>(data.begin() + 30);
    }
}

bool MaximumProfile::valid() const
{
    bool valid = true;

    valid &= m_version == true_type_version || m_version == open_type_vetsion;
    valid &= m_num_glyphs != 0;

    return valid;
}

Fixed MaximumProfile::version() const
{
    return m_version;
}

std::uint16_t MaximumProfile::num_glyphs() const
{
    return m_num_glyphs;
}

} // namespace framework::graphics::details::font
