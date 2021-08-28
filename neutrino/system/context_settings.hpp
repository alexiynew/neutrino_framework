// =============================================================================
// MIT License
//
// Copyright (c) 2017-2021 Fedorov Alexey
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
// =============================================================================

#ifndef FRAMEWORK_SYSTEM_CONTEXT_SETTINGS_HPP
#define FRAMEWORK_SYSTEM_CONTEXT_SETTINGS_HPP

#include <common/types.hpp>
#include <common/version.hpp>

namespace framework::system
{

////////////////////////////////////////////////////////////////////////////////
/// @addtogroup graphic_context
/// @{
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
/// @brief Graphic context settings.
///
/// Structure to store context settings. Used by the
/// @ref framework::system::window class to setup graphic context.
/// Context is always double-buffered and always RGB-capable.
////////////////////////////////////////////////////////////////////////////////
class ContextSettings
{
public:
    ////////////////////////////////////////////////////////////////////////////
    /// @brief Antialiasing level values
    ////////////////////////////////////////////////////////////////////////////
    enum class Antialiasing
    {
        dont_care, ///< Get any suitable context.
        best       ///< Find best value.
    };

    ContextSettings() = default;

    ContextSettings(const ContextSettings&) = default;
    ContextSettings(ContextSettings&&)      = default;

    ContextSettings& operator=(const ContextSettings&) noexcept = default;
    ContextSettings& operator=(ContextSettings&&) noexcept = default;

    ~ContextSettings() = default;

#pragma region setters
    ////////////////////////////////////////////////////////////////////////////
    /// @name setters
    /// @{
    ////////////////////////////////////////////////////////////////////////////

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Sets required API version.
    ///
    /// @param version required version.
    ///
    /// @return Reference to this settings.
    ////////////////////////////////////////////////////////////////////////////
    ContextSettings& version(Version version);

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Sets depth buffers bits count.
    ///
    /// @param bits Depth buffer bits count.
    ///
    /// @return Reference to this settings.
    ////////////////////////////////////////////////////////////////////////////
    ContextSettings& depth_bits(int32 bits);

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Sets stencil buffer bits count.
    ///
    /// @param bits Stencil buffer bits count.
    ///
    /// @return Reference to this settings.
    ////////////////////////////////////////////////////////////////////////////
    ContextSettings& stencil_bits(int32 bits);

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Sets The Antialiasing level.
    ///
    /// @param level The Antialiasing level.
    ///
    /// @return Reference to this settings.
    ////////////////////////////////////////////////////////////////////////////
    ContextSettings& antialiasing_level(Antialiasing level);

    ////////////////////////////////////////////////////////////////////////////
    /// @}
    ////////////////////////////////////////////////////////////////////////////
#pragma endregion

#pragma region getters
    ////////////////////////////////////////////////////////////////////////////
    /// @name getters
    /// @{
    ////////////////////////////////////////////////////////////////////////////

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Required API version.
    ///
    /// @return Required API version.
    ////////////////////////////////////////////////////////////////////////////
    Version version() const;

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Required detph buffer bits count.
    ///
    /// @return The detph buffer bits count.
    ////////////////////////////////////////////////////////////////////////////
    int32 depth_bits() const;

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Required stencil buffer bits count.
    ///
    /// @return The stencil buffer bits count.
    ////////////////////////////////////////////////////////////////////////////
    int32 stencil_bits() const;

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Required Antialiasing level.
    ///
    /// @return The Antialiasing level.
    ////////////////////////////////////////////////////////////////////////////
    Antialiasing antialiasing_level() const;

    ////////////////////////////////////////////////////////////////////////////
    /// @}
    ////////////////////////////////////////////////////////////////////////////
#pragma endregion

private:
    int32 m_depth_bits                = 24;
    int32 m_stencil_bits              = 8;
    Antialiasing m_antialiasing_level = Antialiasing::best;
    Version m_version                 = {3, 0};
};

////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////

} // namespace framework::system

#endif
