/// @file
/// @brief Window implementation for Linux.
/// @author Fedorov Alexey
/// @date 05.04.2017

#ifndef FRAMEWORK_WINDOW_LINUX_X11_WINDOW_HPP
#define FRAMEWORK_WINDOW_LINUX_X11_WINDOW_HPP

#include <X11/Xlib.h>
#include <common/common_types.hpp>
#include <window/window_implementation.hpp>

namespace framework {

struct x_server_connection;

class x11_window final : public window_implementation
{
public:
    x11_window();
    ~x11_window() override;

    void show() override;
    void hide() override;
    void focus() override;

    void minimize() override;
    void maximize() override;
    void to_full_screen() override;
    void restore() override;

    void set_size(int32 width, int32 height) override;
    void set_position(int32 x, int32 y) override;

    void set_max_size(int32 width, int32 height) override;
    void set_min_size(int32 width, int32 height) override;

    void set_title(const std::string& title) override;

    int x() override;
    int y() override;
    int width() override;
    int height() override;

    int max_height() override;
    int max_width() override;
    int min_height() override;
    int min_width() override;

    std::string title() override;

    bool full_screen() override;
    bool minimized() override;
    bool maximized() override;
    bool resizable() override;
    bool visible() override;
    bool focused() override;

private:
    std::shared_ptr<x_server_connection> m_connection;

    uint32 m_width;
    uint32 m_height;

    Window m_window;
};
} // namespace framework

#endif
