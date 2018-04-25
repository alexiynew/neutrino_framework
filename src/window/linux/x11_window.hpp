/// @file
/// @brief Window implementation for Linux.
/// @author Fedorov Alexey
/// @date 05.04.2017

#ifndef FRAMEWORK_WINDOW_LINUX_X11_WINDOW_HPP
#define FRAMEWORK_WINDOW_LINUX_X11_WINDOW_HPP

#include <X11/Xlib.h>
#include <functional>

#include <common/types.hpp>
#include <window/implementation.hpp>
#include <window/linux/x11_server.hpp>

namespace framework {

class x11_window final : public window::implementation
{
public:
    x11_window(window::size_t size, const std::string& title);
    ~x11_window() override;

    /// @name actions
    /// @{
    void show() override;
    void hide() override;
    void focus() override;
    void process_events() override;

    // On window managers without the ewmh support, proper work is not tested, nor granted.
    void minimize() override;
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
    /// @}

    /// @name state
    /// @{
    bool fullscreen() const override;
    bool minimized() const override;
    bool maximized() const override;
    bool resizable() const override;
    bool visible() const override;
    bool focused() const override;
    /// @}

private:
    enum class state;

    void process(XDestroyWindowEvent event);
    void process(XUnmapEvent event);
    void process(XVisibilityEvent event);
    void process(XConfigureEvent event);
    void process(XFocusChangeEvent event);
    void process(XPropertyEvent event);
    void process(XAnyEvent event);

    void set_wm_hints();
    void set_class_hints();
    void add_protocols(const std::vector<std::string>& protocol_names);
    void create_input_context();

    void process_events_while(const std::function<bool()>& condition);

    void update_size_limits(window::size_t min_size, window::size_t max_size);

    std::shared_ptr<x11_server> m_server = nullptr;

    bool m_viewable       = false;
    bool m_cursor_grabbed = false;
    bool m_resizable      = true;

    state m_state;

    window::size_t m_size         = {640, 480};
    window::position_t m_position = {0, 0};

    mutable window::size_t m_min_size = {0, 0};
    mutable window::size_t m_max_size = {0, 0};

    Window m_window      = 0;
    XIC input_context    = nullptr;
    Time m_lastInputTime = 0;
};

} // namespace framework

#endif
