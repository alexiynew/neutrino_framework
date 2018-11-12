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

/// @brief OpenGL graphic context settings.
/// 
/// Structure to store context settings. Used in the @ref window class to setuap graphic context.
class context_settings
{
public:
    /// @breif Color type
    enum class color
    {
        rgba
    };

    /// @breif Samples 
    enum class samples
    {
        any,
        best
    };

    context_settings() = default;

    context_settings(const context_settings&) = default;
    context_settings(context_settings&&)      = default;

    context_settings& operator=(const context_settings&) = default;
    context_settings& operator=(context_settings&&) = default;

    ~context_settings() = default;

    context_settings& set_double_buffered();
    context_settings& set_single_buffered();
    context_settings& set_version(utils::version version);
    context_settings& set_depth_bits(int32 bits);
    context_settings& set_stencil_bits(int32 bits);
    context_settings& set_color_type(color type);
    context_settings& set_samples_count(samples count);

    bool double_buffered() const;
    bool single_buffered() const;
    
    utils::version version() const;
    int32 depth_bits() const;
    int32 stencil_bits() const;
    color color_type() const;
    samples samples_count() const;

private:
    bool m_double_buffered   = true;
    utils::version m_version = {3, 0};
    int32 m_depth_bits       = 24;
    int32 m_stencil_bits     = 8;
    color m_color_type       = color::rgba;
    samples m_samples_count  = samples::best;
};

class context
{
public:
    explicit context(context_settings settings) noexcept;

    context(const context&) = default;
    context(context&&)      = default;

    context& operator=(const context&) = default;
    context& operator=(context&&) = default;

    virtual ~context();

    virtual bool valid() const      = 0;
    virtual bool is_current() const = 0;

    virtual void make_current() const = 0;
    virtual void swap_buffers() const = 0;

    context_settings settings() const;

private:
    context_settings m_settings;
};

} // namespace framework::opengl

#endif