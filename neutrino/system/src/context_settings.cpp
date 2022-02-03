#include <system/context_settings.hpp>

namespace framework::system
{

#pragma region setters

ContextSettings& ContextSettings::version(Version version)
{
    m_version = version;
    return *this;
}

ContextSettings& ContextSettings::depth_bits(std::uint32_t bits)
{
    m_depth_bits = bits;
    return *this;
}

ContextSettings& ContextSettings::stencil_bits(std::uint32_t bits)
{
    m_stencil_bits = bits;
    return *this;
}

ContextSettings& ContextSettings::antialiasing_level(Antialiasing level)
{
    m_antialiasing_level = level;
    return *this;
}

#pragma endregion

#pragma region getters

Version ContextSettings::version() const
{
    return m_version;
}

std::uint32_t ContextSettings::depth_bits() const
{
    return m_depth_bits;
}

std::uint32_t ContextSettings::stencil_bits() const
{
    return m_stencil_bits;
}

ContextSettings::Antialiasing ContextSettings::antialiasing_level() const
{
    return m_antialiasing_level;
}

#pragma endregion

} // namespace framework::system
