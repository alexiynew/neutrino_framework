/// @file
/// @brief Window implementation for Linux.
/// @author Fedorov Alexey
/// @date 05.04.2017

#ifndef FRAMEWORK_WINDOW_LINUX_X11_WINDOW_HPP
#define FRAMEWORK_WINDOW_LINUX_X11_WINDOW_HPP

#include <X11/Xlib.h>
#include <common/common_types.hpp>
#include <window/implementation.hpp>
#include <window/linux/x11_server.hpp>

namespace framework {

class x11_window final : public window::implementation
{
public:
    x11_window();
    ~x11_window() override;

    void show() override;
    void hide() override;
    void focus() override;
    void process_events() override;

    void minimize() override;
    void maximize() override;
    void to_full_screen() override;
    void restore() override;

    void set_size(window::size_t size) override;
    void set_position(window::position_t position) override;

    void set_max_size(window::size_t max_size) override;
    void set_min_size(window::size_t min_size) override;

    void set_title(const std::string& title) override;

    window::position_t position() override;
    window::size_t size() override;

    window::size_t max_size() override;
    window::size_t min_size() override;

    std::string title() override;

    bool full_screen() override;
    bool minimized() override;
    bool maximized() override;
    bool resizable() override;
    bool visible() override;
    bool focused() override;

private:
    void process(XDestroyWindowEvent event);
    void process(XUnmapEvent event);
    void process(XVisibilityEvent event);
    void process(XConfigureEvent event);
    void process(XAnyEvent event);

    std::shared_ptr<x11_server> m_server = nullptr;

    bool m_viewable = false;

    window::size_t m_size         = {640, 480};
    window::position_t m_position = {0, 0};

    Window m_window = 0;
};
} // namespace framework

#endif
