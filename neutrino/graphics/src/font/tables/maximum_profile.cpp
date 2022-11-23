#include <common/utils.hpp>

#include <graphics/src/font/tables/maximum_profile.hpp>

namespace neutrino::graphics::details::font
{

MaximumProfile::MaximumProfile(const BytesData& data)
{
    auto in = utils::make_big_endian_buffer_reader(data);

    in >> m_version;
    in >> m_num_glyphs;

    if (m_version == 0x00010000) {
        in >> m_max_points;
        in >> m_max_contours;
        in >> m_max_composite_points;
        in >> m_max_composite_contours;
        in >> m_max_zones;
        in >> m_max_twilight_points;
        in >> m_max_storage;
        in >> m_max_function_defs;
        in >> m_max_instruction_defs;
        in >> m_max_stack_elements;
        in >> m_max_size_of_instructions;
        in >> m_max_component_elements;
        in >> m_max_component_depth;
    }
}

bool MaximumProfile::is_valid() const
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

} // namespace neutrino::graphics::details::font
