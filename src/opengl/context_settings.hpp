/// @file
/// @brief OpenGL graphic context settings.
/// @author Fedorov Alexey
/// @date 12.11.2018

// =============================================================================
// MIT License
//
// Copyright (c) 2017-2018 Fedorov Alexey
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

#ifndef FRAMEWORK_OPENGL_CONTEXT_SETTINGS_HPP
#define FRAMEWORK_OPENGL_CONTEXT_SETTINGS_HPP

#include <common/types.hpp>
#include <common/version.hpp>

namespace framework::opengl
{
/// @addtogroup opengl_module
/// @{

/// @brief OpenGL graphic context settings.
///
/// Structure to store context settings. Used by the @ref ::framework::system::window class to setup graphic context.
///
/// @see ::framework::system::window, context
class context_settings
{
public:
    /// @brief Samples count
    enum class samples
    {
        dont_care, ///< Get any suitable context.
        best       ///< Get context with maximum samples count.
    };

    /// @brief Default constructor
    context_settings() = default;

    /// @brief Default copy constructor.
    context_settings(const context_settings&) = default;

    /// @brief Default move constructor.
    context_settings(context_settings&&) = default;

    /// @brief Default copy operator.
    ///
    /// @return Reference to copied object.
    context_settings& operator=(const context_settings&) = default;

    /// @brief Default move operator.
    ///
    /// @return Reference to moved object.
    context_settings& operator=(context_settings&&) = default;

    /// @brief Default destructor
    ~context_settings() = default;

#pragma region setters

    /// @brief Request double buffered context.
    ///
    /// @return Reference to this settings.
    context_settings& set_double_buffered();

    /// @brief Request single buffered context.
    ///
    /// @return Reference to this settings.
    context_settings& set_single_buffered();

    /// @brief Sets required OpenGL version.
    ///
    /// @param version required OpenGl version.
    ///
    /// @return Reference to this settings.
    context_settings& set_version(utils::version version);

    /// @brief Sets depth buffers bits count.
    ///
    /// @param bits Depth buffer bits count.
    ///
    /// @return Reference to this settings.
    context_settings& set_depth_bits(int32 bits);

    /// @brief Sets stencil buffer bits count.
    ///
    /// @param bits Stencil buffer bits count.
    ///
    /// @return Reference to this settings.
    context_settings& set_stencil_bits(int32 bits);

    /// @brief Sets samples count.
    ///
    /// @param count Samples count.
    ///
    /// @return Reference to this settings.
    context_settings& set_samples_count(samples count);

#pragma endregion

#pragma region getters

    /// @brief Check if double buffered context required.
    ///
    /// @return `true` if double buffered context required.
    bool double_buffered() const;

    /// @brief Check if single buffered context required.
    ///
    /// @return `true` if single buffered context required.
    bool single_buffered() const;

    /// @brief Required OpenGl version.
    ///
    /// @return Required OpenGl version.
    utils::version version() const;

    /// @brief Required detph buffer bits count.
    ///
    /// @return The detph buffer bits count.
    int32 depth_bits() const;

    /// @brief Required stencil buffer bits count.
    ///
    /// @return The stencil buffer bits count.
    int32 stencil_bits() const;

    /// @brief Required samples count.
    ///
    /// @return The samples count.
    samples samples_count() const;

#pragma endregion

private:
    bool m_double_buffered   = true;
    utils::version m_version = {3, 0};
    int32 m_depth_bits       = 24;
    int32 m_stencil_bits     = 8;
    samples m_samples_count  = samples::best;
};

/// @}

} // namespace framework::opengl

#endif
