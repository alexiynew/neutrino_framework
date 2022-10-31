#include <system/context_settings.hpp>

namespace neutrino::system
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

ContextSettings& ContextSettings::samples_count(std::uint32_t samples)
{
    m_samples_count = samples;
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

std::uint32_t ContextSettings::samples_count() const
{
    return m_samples_count;
}

#pragma endregion

} // namespace neutrino::system
