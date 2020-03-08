/// @file
/// @brief Describes interface for all window implementations.
/// @author Fedorov Alexey
/// @date 05.04.2017

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

#ifndef FRAMEWORK_SYSTEM_SRC_WINDOW_IMPLEMENTATION_HPP
#define FRAMEWORK_SYSTEM_SRC_WINDOW_IMPLEMENTATION_HPP

#include <memory>
#include <string>

#include <system/context_settings.hpp>
#include <system/window.hpp>

#include <common/position.hpp>
#include <common/size.hpp>


namespace framework::system::details
{
class PlatformWindow
{
public:
    static void set_application_name(const std::string& name);

    PlatformWindow(const Window& window_interface);

    virtual ~PlatformWindow();

    PlatformWindow(const PlatformWindow&) = delete;
    PlatformWindow& operator=(const PlatformWindow&) = delete;

    PlatformWindow(PlatformWindow&&) = default;
    PlatformWindow& operator=(PlatformWindow&&) = default;

    /// @name actions
    /// @{
    virtual void show()                  = 0;
    virtual void hide()                  = 0;
    virtual void focus()                 = 0;
    virtual void iconify()               = 0;
    virtual void maximize()              = 0;
    virtual void fullscreen()            = 0;
    virtual void restore()               = 0;
    virtual void resize(Size size)       = 0;
    virtual void move(Position position) = 0;
    virtual void process_events()        = 0;
    virtual void make_current()          = 0;
    virtual void swap_buffers()          = 0;
    /// @}

    /// @name setters
    /// @{
    virtual void set_max_size(Size size) = 0;
    virtual void set_min_size(Size size) = 0;
    virtual void set_resizable(bool value) = 0;
    virtual void set_title(const std::string& title) = 0;
    /// @}

    /// @name getters
    /// @{
    virtual Position position() const = 0;
    virtual Size size() const         = 0;
    virtual Size max_size() const = 0;
    virtual Size min_size() const = 0;
    virtual std::string title() const = 0;
    /// @}

    /// @name state
    /// @{
    virtual bool should_close() const    = 0;
    virtual bool is_fullscreen() const   = 0;
    virtual bool is_iconified() const    = 0;
    virtual bool is_maximized() const    = 0;
    virtual bool is_resizable() const    = 0;
    virtual bool is_visible() const      = 0;
    virtual bool has_input_focus() const = 0;
    /// @}

protected:
    static std::string application_name;
    const Window& m_window_interface;
};

// @brief Fabric function to make platform dependent implementation
std::unique_ptr<PlatformWindow> create_platform_window(const Window& window, 
                                                       Size size,
                                                       const std::string& title,
                                                       const context_settings& settings);

} // namespace framework::system::details

#endif
