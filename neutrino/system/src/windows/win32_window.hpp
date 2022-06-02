#ifndef FRAMEWORK_WINDOW_DETAILS_WINDOWS_WIN32_WINDOW_HPP
#define FRAMEWORK_WINDOW_DETAILS_WINDOWS_WIN32_WINDOW_HPP

#include <memory>

#include <system/context_settings.hpp>

#include <system/src/platform_window.hpp>

#include <Windows.h>

namespace framework::system
{
class Context;
}

namespace framework::system::details
{
class Win32Window final : public PlatformWindow
{
public:
    Win32Window(const std::string& title, Size size, const ContextSettings& settings);
    ~Win32Window() override;

    Win32Window(const Win32Window&) = delete;
    Win32Window& operator=(const Win32Window&) = delete;

#pragma region actions
    void show() override;
    void hide() override;
    void focus() override;
    void iconify() override;
    void maximize() override;
    void fullscreen() override;
    void restore() override;
    void resize(Size size) override;
    void move(Position position) override;
    void grab_cursor() override;
    void release_cursor() override;
    void process_events() override;
#pragma endregion

#pragma region setters
    void set_max_size(Size max_size) override;
    void set_min_size(Size min_size) override;
    void set_resizable(bool value) override;
    void set_title(const std::string& title) override;
    void set_cursor_visibility(bool visible) override;
#pragma endregion

#pragma region getters
    Position position() const override;
    Size size() const override;
    Size max_size() const override;
    Size min_size() const override;
    std::string title() const override;
    const Context& context() const override;
    Context& context() override;
#pragma endregion

#pragma region state
    bool should_close() const override;
    bool is_fullscreen() const override;
    bool is_iconified() const override;
    bool is_maximized() const override;
    bool is_resizable() const override;
    bool is_visible() const override;
    bool has_input_focus() const override;
    bool is_cursor_visible() const override;
    bool is_cursor_grabbed() const override;
#pragma endregion

    LRESULT process_message(UINT message, WPARAM w_param, LPARAM l_param);

private:
    struct WindowInfo
    {
        RECT rect;
    };

    struct ModifiersFlags
    {
        bool left_shift;
        bool right_shift;
        bool left_control;
        bool right_control;
        bool left_alt;
        bool right_alt;
    };

    struct MessageHandler;

    LRESULT on_set_focus_message(UINT message, WPARAM w_param, LPARAM l_param);
    LRESULT on_kill_focus_message(UINT message, WPARAM w_param, LPARAM l_param);
    LRESULT on_close_message(UINT message, WPARAM w_param, LPARAM l_param);
    LRESULT on_move_message(UINT message, WPARAM w_param, LPARAM l_param);
    LRESULT on_size_message(UINT message, WPARAM w_param, LPARAM l_param);
    LRESULT on_get_min_max_info_message(UINT message, WPARAM w_param, LPARAM l_param);

    LRESULT on_mouse_leave_message(UINT message, WPARAM w_param, LPARAM l_param);
    LRESULT on_mouse_hover_message(UINT message, WPARAM w_param, LPARAM l_param);
    LRESULT on_mouse_move_message(UINT message, WPARAM w_param, LPARAM l_param);
    LRESULT on_mouse_button_message(UINT message, WPARAM w_param, LPARAM l_param);
    LRESULT on_mouse_wheel_message(UINT message, WPARAM w_param, LPARAM l_param);

    LRESULT on_key_message(UINT message, WPARAM w_param, LPARAM l_param);

    LRESULT on_unichar_message(UINT message, WPARAM w_param, LPARAM l_param);
    LRESULT on_char_message(UINT message, WPARAM w_param, LPARAM l_param);

    LRESULT on_input_message(UINT message, WPARAM w_param, LPARAM l_param);

    void process_shift_key(LPARAM l_param);
    void process_control_key(LPARAM l_param);
    void process_alt_key(LPARAM l_param);

    void track_mouse();
    void update_cursor();
    void enable_raw_input();
    void disable_raw_input();

    HWND m_window = nullptr;
    HDC m_hdc     = nullptr;
    HGLRC m_hglrc = nullptr;

    Size m_min_size = {0, 0};
    Size m_max_size = {0, 0};

    bool m_resizable      = true;
    bool m_mouse_hover    = false;
    bool m_should_close   = false;
    bool m_cursor_visible = true;
    bool m_cursor_grabbed = false;
    bool m_shoud_maximize = false;

    CursorPosition m_grabbed_cursor_diff = {0, 0};
    CursorPosition m_cursor_position     = {0, 0};

    WindowInfo m_saved_info = {{0, 0, 0, 0}};

    std::unique_ptr<Context> m_context                = nullptr;
    std::unique_ptr<MessageHandler> m_message_handler = nullptr;

    ModifiersFlags m_modifiers_flags = {false, false, false, false, false, false};
};

} // namespace framework::system::details

#endif
