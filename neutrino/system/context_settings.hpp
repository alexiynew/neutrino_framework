#ifndef SYSTEM_CONTEXT_SETTINGS_HPP
#define SYSTEM_CONTEXT_SETTINGS_HPP

#include <limits>

#include <common/global_defines.hpp>
#include <common/version.hpp>
namespace neutrino::system
{

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @addtogroup system_graphic_context
/// @{
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @brief Graphic context settings.
///
/// Structure to store context settings. Used by the @ref neutrino::system::window class to setup graphic context.
/// Context is always double-buffered and always RGB-capable.
/// After the context is created, the values in the ContextSettings are updated to the actual ones.
/// If the any value is set to `dont_care`, this parameter is not taken into account when creating the context.
/// Otherwise, the closest to the specified value is selected.
class ContextSettings
{
public:
    static constexpr std::uint32_t default_max_depth_bits   = 24;
    static constexpr std::uint32_t default_max_stencil_bits = 8;

    static constexpr std::uint32_t best      = 999;
    static constexpr std::uint32_t dont_care = 0;

    ContextSettings() = default;

    ContextSettings(const ContextSettings&) = default;
    ContextSettings(ContextSettings&&)      = default;

    ~ContextSettings() = default;

    ContextSettings& operator=(const ContextSettings&) noexcept = default;
    ContextSettings& operator=(ContextSettings&&) noexcept      = default;

#pragma region setters
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// @name setters
    /// @{
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    /// @brief Sets required API version.
    ///
    /// @param version required version.
    ///
    /// @return Reference to context settings.
    LIBRARY_API ContextSettings& version(Version version);

    /// @brief Sets depth buffers bits count.
    ///
    /// @param bits Depth buffer bits count.
    ///
    /// @return Reference to context settings.
    LIBRARY_API ContextSettings& depth_bits(std::uint32_t bits);

    /// @brief Sets stencil buffer bits count.
    ///
    /// @param bits Stencil buffer bits count.
    ///
    /// @return Reference to context settings.
    LIBRARY_API ContextSettings& stencil_bits(std::uint32_t bits);

    /// @brief Sets the semples count for multisampling (antialiasing).
    ///
    /// @param samples The number of samples per pixel.
    ///
    /// @return Reference to context settings.
    LIBRARY_API ContextSettings& samples_count(std::uint32_t samples);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// @}
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#pragma endregion

#pragma region getters
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// @name getters
    /// @{
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    ////////////////////////////////////////////////////////////////////////////
    /// @brief API version.
    ///
    /// @return Required API version.
    ////////////////////////////////////////////////////////////////////////////
    LIBRARY_API Version version() const;

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Detph buffer bits count.
    ///
    /// @return The detph buffer bits count.
    ////////////////////////////////////////////////////////////////////////////
    LIBRARY_API std::uint32_t depth_bits() const;

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Stencil buffer bits count.
    ///
    /// @return The stencil buffer bits count.
    ////////////////////////////////////////////////////////////////////////////
    LIBRARY_API std::uint32_t stencil_bits() const;

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Samples count.
    ///
    /// @return The number of samples per pixel.
    ////////////////////////////////////////////////////////////////////////////
    LIBRARY_API std::uint32_t samples_count() const;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// @}
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#pragma endregion

private:
    std::uint32_t m_depth_bits    = best;
    std::uint32_t m_stencil_bits  = best;
    std::uint32_t m_samples_count = best;
    Version m_version             = {3, 2};
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

} // namespace neutrino::system

#endif
