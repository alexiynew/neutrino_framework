#ifndef FRAMEWORK_WINDOW_DETAILS_LINUX_X11_WINDOW_HPP
#define FRAMEWORK_WINDOW_DETAILS_LINUX_X11_WINDOW_HPP

#include <memory>

#include <system/context_settings.hpp>

#include <system/src/linux/x11_server.hpp>
#include <system/src/linux/x11_utils.hpp>
#include <system/src/platform_window.hpp>

#include <X11/Xlib.h>

namespace framework::system
{
class Context;
}

namespace framework::system::details
{
class X11Window final : public PlatformWindow
{
public:
    X11Window(const std::string& title, Size size, const ContextSettings& settings);
    ~X11Window() override;

    X11Window(const X11Window&)            = delete;
    X11Window& operator=(const X11Window&) = delete;

#pragma region actions
    void show() override;
    void hide() override;
    void close() override;
    void focus() override;
    void grab_cursor() override;
    void release_cursor() override;
    void process_events() override;
#pragma endregion

#pragma region setters
    void set_state(Window::State state) override;
    void set_size(Size size) override;
    void set_max_size(Size max_size) override;
    void set_min_size(Size min_size) override;
    void set_resizable(bool value) override;
    void set_position(Position position) override;
    void set_title(const std::string& title) override;
    void set_cursor_visibility(bool visible) override;
#pragma endregion

#pragma region getters
    bool is_visible() const override;
    bool should_close() const override;
    bool has_input_focus() const override;
    bool is_cursor_grabbed() const override;
    bool is_cursor_visible() const override;
    Window::State state() const override;
    Size size() const override;
    Size max_size() const override;
    Size min_size() const override;
    bool is_resizable() const override;
    Position position() const override;
    std::string title() const override;
    const Context& context() const override;
    Context& context() override;
#pragma endregion

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

    void update_size_limits(Size min_size, Size max_size);
    void move_window(Position new_position);

    std::shared_ptr<X11Server> m_server = nullptr;
    std::unique_ptr<Context> m_context  = nullptr;

    bool m_fullscreen     = false;
    bool m_maximized      = false;
    bool m_mapped         = false;
    bool m_cursor_grabbed = false;
    bool m_resizable      = true;
    bool m_shoud_close    = false;
    bool m_wait_focus     = false;

    Size m_size         = {640, 480};
    Size m_saved_size   = {0, 0};
    Position m_position = {0, 0};
    utils::FrameExtents m_frame_extents;

    mutable Size m_min_size = {0, 0};
    mutable Size m_max_size = {0, 0};

    XLibWindow m_window = None;

    XIC m_input_context = nullptr;

    Time m_lastInputTime = 0;
};

} // namespace framework::system::details

#endif
