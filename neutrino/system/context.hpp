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

#ifndef FRAMEWORK_SYSTEM_CONTEXT_HPP
#define FRAMEWORK_SYSTEM_CONTEXT_HPP

#include <memory>

#include <common/types.hpp>
#include <system/context_settings.hpp>

namespace framework::system
{

////////////////////////////////////////////////////////////////////////////////
/// @addtogroup graphic_context
/// @{
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
/// @brief Graphic context.
////////////////////////////////////////////////////////////////////////////////
class Context
{
public:
    ////////////////////////////////////////////////////////////////////////////
    /// @brief Supported graphic api.
    ////////////////////////////////////////////////////////////////////////////
    enum class Api
    {
        opengl,
    };

    using VoidFunctionPtr = void (*)();

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Creates context with provided ContextSettings.
    ////////////////////////////////////////////////////////////////////////////
    explicit Context(ContextSettings settings) noexcept;

    Context(const Context&) = default;
    Context(Context&&)      = default;

    Context& operator=(const Context&) noexcept = default;
    Context& operator=(Context&&) noexcept = default;

    virtual ~Context();

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Checks if a context is created properly.
    ///
    /// @return `True` if context can be used.
    ////////////////////////////////////////////////////////////////////////////
    virtual bool valid() const = 0;

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Checks if a context is current for rendering.
    ///
    /// @return `True` if a context is set up for rendering.
    ////////////////////////////////////////////////////////////////////////////
    virtual bool is_current() const = 0;

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Graphic API supported by this context.
    ///
    /// @return Supported API.
    ////////////////////////////////////////////////////////////////////////////
    virtual Api api_type() const = 0;

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Returns OS specific functon pointer by name.
    ///
    /// @param function_name Function to get.
    ///
    /// @return Addres of OS function.
    ////////////////////////////////////////////////////////////////////////////
    virtual VoidFunctionPtr get_function(const char* function_name) const = 0;

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Set a context as current for rendering.
    ////////////////////////////////////////////////////////////////////////////
    virtual void make_current() = 0;

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Shows on-screen what has been rendered so far.
    ////////////////////////////////////////////////////////////////////////////
    virtual void swap_buffers() = 0;

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Current context settings.
    ///
    /// @return Current context settings.
    ////////////////////////////////////////////////////////////////////////////
    const ContextSettings& settings() const;

protected:
    void update_settings(const ContextSettings& settings);

private:
    ContextSettings m_settings;
};

////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////

} // namespace framework::system

#endif
