/// @file
/// @brief Window implementation for Linux.
/// @author Fedorov Alexey
/// @date 05.04.2017

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

#ifndef FRAMEWORK_WINDOW_DETAILS_LINUX_X11_WINDOW_HPP
#define FRAMEWORK_WINDOW_DETAILS_LINUX_X11_WINDOW_HPP

#include <X11/Xlib.h>
#include <functional>

#include <common/types.hpp>
#include <graphic/window/implementation.hpp>
#include <graphic/window/linux/x11_server.hpp>

namespace framework
{
namespace graphic
{
class x11_window final : public window::implementation
{
public:
    x11_window(window::size_t size, const std::string& title);
    ~x11_window() override;

    x11_window(const x11_window&) = delete;
    x11_window& operator=(const x11_window&) = delete;

    /// @name actions
    /// @{
    void show() override;
    void hide() override;
    void focus() override;
    void process_events() override;

    // On window managers without the ewmh support, proper work is not tested, nor granted.
    void iconify() override;
    void maximize() override;
    void switch_to_fullscreen() override;
    void restore() override;
    /// @}

    /// @name setters
    /// @{

    // The size() value will be updated after next event processing
    void set_size(window::size_t size) override;
    void set_position(window::position_t position) override;

    void set_max_size(window::size_t max_size) override;
    void set_min_size(window::size_t min_size) override;

    void set_resizable(bool value) override;

    void set_title(const std::string& title) override;
    /// @}

    /// @name getters
    /// @{
    window::position_t position() const override;
    window::size_t size() const override;

    window::size_t max_size() const override;
    window::size_t min_size() const override;

    std::string title() const override;

    std::unique_ptr<window::graphic_context> context() const override;
    /// @}

    /// @name state
    /// @{
    bool fullscreen() const override;
    bool iconified() const override;
    bool maximized() const override;
    bool resizable() const override;
    bool visible() const override;
    bool focused() const override;
    /// @}

private:
    class x11_graphic_context : public window::graphic_context
    {
    public:
        x11_graphic_context(Display* display, Window window, GLXContext context);

        bool valid() const override;
        bool is_current() const override;

        void make_current() override;
        void swap_buffers() override;

    private:
        Display* m_display   = nullptr;
        Window m_window      = None;
        GLXContext m_context = nullptr;
    };

    void process(XDestroyWindowEvent event);
    void process(XUnmapEvent event);
    void process(XVisibilityEvent event);
    void process(XConfigureEvent event);
    void process(XFocusChangeEvent event);
    void process(XPropertyEvent event);
    void process(XAnyEvent event);

    void maximize_impl();
    void switch_to_fullscreen_impl();

    void set_wm_hints();
    void set_class_hints();
    void add_protocols(const std::vector<std::string>& protocol_names);

    void create_input_context();

    void process_events_while(const std::function<bool()>& condition);

    void update_size_limits(window::size_t min_size, window::size_t max_size);

    std::shared_ptr<x11_server> m_server = nullptr;

    bool m_fullscreen     = false;
    bool m_maximized      = false;
    bool m_mapped         = false;
    bool m_cursor_grabbed = false;
    bool m_resizable      = true;

    window::size_t m_size         = {640, 480};
    window::size_t m_saved_size   = {0, 0};
    window::position_t m_position = {0, 0};

    mutable window::size_t m_min_size = {0, 0};
    mutable window::size_t m_max_size = {0, 0};

    Window m_window     = None;
    Colormap m_colormap = None;

    GLXFBConfig m_framebuffer_config = nullptr;
    GLXContext m_glx_context         = nullptr;
    XIC m_input_context              = nullptr;

    Time m_lastInputTime = 0;
};

} // namespace graphic

} // namespace framework

#endif
