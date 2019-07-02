/// @file
/// @brief OpenGL graphic context.
/// @author Fedorov Alexey
/// @date 11.09.2018

// =============================================================================
// MIT License
//
// Copyright (c) 2017-2019 Fedorov Alexey
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

#ifndef FRAMEWORK_GRAPHICS_CONTEXT_HPP
#define FRAMEWORK_GRAPHICS_CONTEXT_HPP

#include <common/types.hpp>
#include <graphics/context_settings.hpp>

namespace framework::opengl
{
/// @addtogroup opengl_module
/// @{

/// @brief OpenGL graphic context.
///
/// Encapsulates the platform dependent graphics context.
/// Actual context is created by ::framework::system::window class. Each window has its own context.
/// The make_current should be called before perform any OpenGL functon.
///
/// @thread_safety Context must be created only on main thread.
///
/// @see ::framework::system::window, context_settings.
class context
{
public:
    /// @brief Creates context with settings.
    ///
    /// @param settings Context settings to use.
    explicit context(context_settings settings) noexcept;

    /// @brief Default copy constructor.
    context(const context&) = default;

    /// @brief Default move constructor.
    context(context&&) = default;

    /// @brief Default copy operator.
    ///
    /// @return Reference to copied object.
    context& operator=(const context&) = default;

    /// @brief Default move operator.
    ///
    /// @return Reference to moved object.
    context& operator=(context&&) = default;

    /// @brief Destructor.
    virtual ~context();

    /// @brief Checks if context is created and valid.
    ///
    /// @return `ture` if context can be used.
    ///
    /// @thread_safety This function can be called only from main thread.
    virtual bool valid() const = 0;

    /// @brief Checks if context is current.
    ///
    /// @return `ture` if context is current.
    ///
    /// @thread_safety This function can be called only from main thread.
    virtual bool is_current() const = 0;

    /// @brief Makes the context current.
    ///
    /// @thread_safety This function can be called only from main thread.
    virtual void make_current() const = 0;

    /// @brief Swaps frame buffers.
    ///
    /// @thread_safety This function can be called only from main thread.
    virtual void swap_buffers() const = 0;

    /// @brief Current context settings.
    ///
    /// @return Current context settings.
    ///
    /// @thread_safety This function may be called from any thread.
    const context_settings& settings() const;

private:
    context_settings m_settings; ///< Current context settings.
};

/// @}

} // namespace framework::opengl

#endif
