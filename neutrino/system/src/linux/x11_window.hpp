#ifndef FRAMEWORK_WINDOW_DETAILS_LINUX_X11_WINDOW_HPP
#define FRAMEWORK_WINDOW_DETAILS_LINUX_X11_WINDOW_HPP

#include <functional>

#include <common/types.hpp>

#include <system/src/context.hpp>
#include <system/src/linux/x11_server.hpp>
#include <system/src/window_implementation.hpp>

#include <X11/Xlib.h>

namespace framework::system::details
{
class x11_window final : public window_implementation
{
public:
    x11_window(window_size size, const std::string& title, const context_settings& settings);
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
    void make_current() override;
    void swap_buffers() override;
    /// @}

    /// @name setters
    /// @{

    // The size() value will be updated after next event processing
    void set_size(window_size size) override;
    void set_position(window_position position) override;

    void set_max_size(window_size max_size) override;
    void set_min_size(window_size min_size) override;

    void set_resizable(bool value) override;

    void set_title(const std::string& title) override;
    /// @}

    /// @name getters
    /// @{
    window_position position() const override;
    window_size size() const override;

    window_size max_size() const override;
    window_size min_size() const override;

    std::string title() const override;
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
    void process(XDestroyWindowEvent event);
    void process(XUnmapEvent event);
    void process(XVisibilityEvent event);
    void process(XConfigureEvent event);
    void process(XFocusChangeEvent event);
    void process(XPropertyEvent event);
    void process(XClientMessageEvent event);
    void process(XKeyEvent event);
    void process(XButtonEvent event);
    void process(XCrossingEvent event);
    void process(XMotionEvent event);
    void process(XMappingEvent event);

    void maximize_toggle(bool enable);
    void fullscreen_toggle(bool enable);

    void set_wm_hints();
    void set_class_hints();
    void add_protocols(const std::vector<std::string>& protocol_names);

    void create_input_context();

    void process_events_while(const std::function<bool()>& condition);

    void update_size_limits(window_size min_size, window_size max_size);

    std::shared_ptr<x11_server> m_server = nullptr;
    std::unique_ptr<context> m_context   = nullptr;

    bool m_fullscreen     = false;
    bool m_maximized      = false;
    bool m_mapped         = false;
    bool m_cursor_grabbed = false;
    bool m_resizable      = true;

    window_size m_size         = {640, 480};
    window_size m_saved_size   = {0, 0};
    window_position m_position = {0, 0};

    mutable window_size m_min_size = {0, 0};
    mutable window_size m_max_size = {0, 0};

    Window m_window = None;

    XIC m_input_context = nullptr;

    Time m_lastInputTime = 0;
};

} // namespace framework::system::details

#endif
