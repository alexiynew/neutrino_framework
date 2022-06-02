#include <functional>
#include <stdexcept>

#include <common/utf.hpp>

#include <system/src/windows/win32_application.hpp>
#include <system/src/windows/win32_keyboard.hpp>
#include <system/src/windows/win32_wgl_context.hpp>
#include <system/src/windows/win32_window.hpp>

#include <hidusage.h>
#include <windowsx.h>

namespace
{

namespace utf = framework::utf;

const DWORD window_style = WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_SIZEBOX | WS_MINIMIZEBOX | WS_CLIPCHILDREN |
                           WS_CLIPSIBLINGS;
const DWORD window_ex_style = WS_EX_OVERLAPPEDWINDOW | WS_EX_APPWINDOW;

framework::system::MouseButton get_mouse_button(UINT message, WPARAM w_param)
{
    using framework::system::MouseButton;

    switch (message) {
        case WM_LBUTTONDOWN:
        case WM_LBUTTONUP: return MouseButton::button_left;

        case WM_MBUTTONDOWN:
        case WM_MBUTTONUP: return MouseButton::button_middle;

        case WM_RBUTTONDOWN:
        case WM_RBUTTONUP: return MouseButton::button_right;

        case WM_XBUTTONDOWN:
        case WM_XBUTTONUP: (GET_XBUTTON_WPARAM(w_param) == XBUTTON1 ? MouseButton::button_4 : MouseButton::button_5);
    }

    return MouseButton::unknown;
}

framework::Size adjust_size(framework::Size size, long style)
{
    RECT rect{0, 0, size.width, size.height};
    AdjustWindowRectEx(&rect, window_style, false, window_ex_style);

    if ((style & WS_SIZEBOX) == 0) {
        // TODO (alex): fix size without size box.
    }

    return {rect.right - rect.left, rect.bottom - rect.top};
}

void set_cursor_in_center(HWND window)
{
    RECT rect;
    GetClientRect(window, &rect);

    POINT p = {rect.right / 2, rect.bottom / 2};
    ClientToScreen(window, &p);
    SetCursorPos(p.x, p.y);
}

void set_cursor_cliping(HWND window, bool enable)
{
    if (enable) {
        RECT rect;
        GetClientRect(window, &rect);

        POINT left_top{rect.left, rect.top};
        ClientToScreen(window, &left_top);

        POINT right_bottom{rect.right, rect.bottom};
        ClientToScreen(window, &right_bottom);

        rect = {left_top.x, left_top.y, right_bottom.x, right_bottom.y};

        ClipCursor(&rect);
    } else {
        ClipCursor(nullptr);
    }
}

framework::system::CursorPosition get_cursor_position(HWND window)
{
    POINT p;
    GetCursorPos(&p);
    ScreenToClient(window, &p);

    return {p.x, p.y};
}

void set_cursor_position(HWND window, framework::system::CursorPosition pos)
{
    POINT p = {pos.x, pos.y};
    ClientToScreen(window, &p);
    SetCursorPos(p.x, p.y);
}

bool is_cursor_in_client_area(HWND window)
{
    RECT rect;
    GetClientRect(window, &rect);

    framework::system::CursorPosition pos = get_cursor_position(window);

    return pos.x >= 0 && pos.y >= 0 && pos.x <= rect.right && pos.y <= rect.bottom;
}

} // namespace

namespace framework::system::details
{

#pragma region class Win32Window::MessageHandler

struct Win32Window::MessageHandler
{
    using CallbackType = std::function<LRESULT(UINT, WPARAM, LPARAM)>;

    LRESULT process_set_focus_message(UINT message, WPARAM w_param, LPARAM l_param);
    LRESULT process_kill_focus_message(UINT message, WPARAM w_param, LPARAM l_param);
    LRESULT process_close_message(UINT message, WPARAM w_param, LPARAM l_param);
    LRESULT process_move_message(UINT message, WPARAM w_param, LPARAM l_param);
    LRESULT process_size_message(UINT message, WPARAM w_param, LPARAM l_param);
    LRESULT process_get_min_max_info_message(UINT message, WPARAM w_param, LPARAM l_param);

    LRESULT process_mouse_leave_message(UINT message, WPARAM w_param, LPARAM l_param);
    LRESULT process_mouse_hover_message(UINT message, WPARAM w_param, LPARAM l_param);
    LRESULT process_mouse_move_message(UINT message, WPARAM w_param, LPARAM l_param);
    LRESULT process_mouse_button_message(UINT message, WPARAM w_param, LPARAM l_param);
    LRESULT process_mouse_wheel_message(UINT message, WPARAM w_param, LPARAM l_param);

    LRESULT process_key_message(UINT message, WPARAM w_param, LPARAM l_param);

    LRESULT process_unichar_message(UINT message, WPARAM w_param, LPARAM l_param);
    LRESULT process_char_message(UINT message, WPARAM w_param, LPARAM l_param);

    LRESULT process_input_message(UINT message, WPARAM w_param, LPARAM l_param);

    CallbackType on_set_focus;
    CallbackType on_kill_focus;
    CallbackType on_close;
    CallbackType on_move;
    CallbackType on_size;
    CallbackType on_get_min_max_info;
    CallbackType on_mouse_leave;
    CallbackType on_mouse_hover;
    CallbackType on_mouse_move;
    CallbackType on_mouse_button;
    CallbackType on_mouse_wheel;
    CallbackType on_key;
    CallbackType on_unichar;
    CallbackType on_char;
    CallbackType on_input;
};

LRESULT Win32Window::MessageHandler::process_set_focus_message(UINT message, WPARAM w_param, LPARAM l_param)
{
    if (on_set_focus) {
        return on_set_focus(message, w_param, l_param);
    }
    return 0;
}

LRESULT Win32Window::MessageHandler::process_kill_focus_message(UINT message, WPARAM w_param, LPARAM l_param)
{
    if (on_kill_focus) {
        return on_kill_focus(message, w_param, l_param);
    }
    return 0;
}

LRESULT Win32Window::MessageHandler::process_close_message(UINT message, WPARAM w_param, LPARAM l_param)
{
    if (on_close) {
        return on_close(message, w_param, l_param);
    }
    return 0;
}

LRESULT Win32Window::MessageHandler::process_move_message(UINT message, WPARAM w_param, LPARAM l_param)
{
    if (on_move) {
        return on_move(message, w_param, l_param);
    }
    return 0;
}

LRESULT Win32Window::MessageHandler::process_size_message(UINT message, WPARAM w_param, LPARAM l_param)
{
    if (on_size) {
        return on_size(message, w_param, l_param);
    }
    return 0;
}

LRESULT Win32Window::MessageHandler::process_get_min_max_info_message(UINT message, WPARAM w_param, LPARAM l_param)
{
    if (on_get_min_max_info) {
        return on_get_min_max_info(message, w_param, l_param);
    }
    return 0;
}

LRESULT Win32Window::MessageHandler::process_mouse_leave_message(UINT message, WPARAM w_param, LPARAM l_param)
{
    if (on_mouse_leave) {
        return on_mouse_leave(message, w_param, l_param);
    }
    return 0;
}

LRESULT Win32Window::MessageHandler::process_mouse_hover_message(UINT message, WPARAM w_param, LPARAM l_param)
{
    if (on_mouse_hover) {
        return on_mouse_hover(message, w_param, l_param);
    }
    return 0;
}

LRESULT Win32Window::MessageHandler::process_mouse_move_message(UINT message, WPARAM w_param, LPARAM l_param)
{
    if (on_mouse_move) {
        return on_mouse_move(message, w_param, l_param);
    }
    return 0;
}

LRESULT Win32Window::MessageHandler::process_mouse_button_message(UINT message, WPARAM w_param, LPARAM l_param)
{
    if (on_mouse_button) {
        return on_mouse_button(message, w_param, l_param);
    }
    return 0;
}

LRESULT Win32Window::MessageHandler::process_mouse_wheel_message(UINT message, WPARAM w_param, LPARAM l_param)
{
    if (on_mouse_wheel) {
        return on_mouse_wheel(message, w_param, l_param);
    }
    return 0;
}

LRESULT Win32Window::MessageHandler::process_key_message(UINT message, WPARAM w_param, LPARAM l_param)
{
    if (on_key) {
        return on_key(message, w_param, l_param);
    }
    return 0;
}

LRESULT Win32Window::MessageHandler::process_unichar_message(UINT message, WPARAM w_param, LPARAM l_param)
{
    if (on_unichar) {
        return on_unichar(message, w_param, l_param);
    }
    return 0;
}

LRESULT Win32Window::MessageHandler::process_char_message(UINT message, WPARAM w_param, LPARAM l_param)
{
    if (on_char) {
        return on_char(message, w_param, l_param);
    }
    return 0;
}

LRESULT Win32Window::MessageHandler::process_input_message(UINT message, WPARAM w_param, LPARAM l_param)
{
    if (on_input) {
        return on_input(message, w_param, l_param);
    }
    return 0;
}

#pragma endregion

Win32Window::Win32Window(const std::string& title, Size size, const ContextSettings& settings)
    : PlatformWindow()
{
    using namespace std::placeholders;

    size = adjust_size(size, window_style);

    m_window = CreateWindowEx(window_ex_style,
                              Win32Application::get_window_class(),
                              utf::to_wstring(title).c_str(),
                              window_style,
                              CW_USEDEFAULT,
                              CW_USEDEFAULT,
                              size.width,
                              size.height,
                              nullptr,
                              nullptr,
                              Win32Application::handle(),
                              nullptr);

    if (m_window == nullptr) {
        throw std::runtime_error("Failed to create window, error: " + std::to_string(GetLastError()));
    }

    m_context = std::make_unique<Win32WglContext>(m_window, settings);

    m_message_handler = std::make_unique<MessageHandler>();

    m_message_handler->on_set_focus        = std::bind(&Win32Window::on_set_focus_message, this, _1, _2, _3);
    m_message_handler->on_kill_focus       = std::bind(&Win32Window::on_kill_focus_message, this, _1, _2, _3);
    m_message_handler->on_close            = std::bind(&Win32Window::on_close_message, this, _1, _2, _3);
    m_message_handler->on_move             = std::bind(&Win32Window::on_move_message, this, _1, _2, _3);
    m_message_handler->on_size             = std::bind(&Win32Window::on_size_message, this, _1, _2, _3);
    m_message_handler->on_get_min_max_info = std::bind(&Win32Window::on_get_min_max_info_message, this, _1, _2, _3);
    m_message_handler->on_mouse_leave      = std::bind(&Win32Window::on_mouse_leave_message, this, _1, _2, _3);
    m_message_handler->on_mouse_hover      = std::bind(&Win32Window::on_mouse_hover_message, this, _1, _2, _3);
    m_message_handler->on_mouse_move       = std::bind(&Win32Window::on_mouse_move_message, this, _1, _2, _3);
    m_message_handler->on_mouse_button     = std::bind(&Win32Window::on_mouse_button_message, this, _1, _2, _3);
    m_message_handler->on_mouse_wheel      = std::bind(&Win32Window::on_mouse_wheel_message, this, _1, _2, _3);
    m_message_handler->on_key              = std::bind(&Win32Window::on_key_message, this, _1, _2, _3);
    m_message_handler->on_unichar          = std::bind(&Win32Window::on_unichar_message, this, _1, _2, _3);
    m_message_handler->on_char             = std::bind(&Win32Window::on_char_message, this, _1, _2, _3);
    m_message_handler->on_input            = std::bind(&Win32Window::on_input_message, this, _1, _2, _3);

    Win32Application::add_window(m_window, this);

    // The first call ignores its parameters
    ShowWindow(m_window, SW_HIDE);
}

Win32Window::~Win32Window()
{
    DestroyWindow(m_window);
    Win32Application::remove_window(m_window);
}

#pragma region actions

void Win32Window::show()
{
    using namespace std::placeholders;

    if (is_visible()) {
        return;
    }

    // Turn off the on_resize callback
    m_message_handler->on_size = nullptr;

    // Turn off the on_move callback
    m_message_handler->on_move = nullptr;

    // Turn off the on_set_focus callback
    m_message_handler->on_set_focus = nullptr;

    if (is_iconified()) {
        ShowWindow(m_window, SW_RESTORE);
    } else if (m_shoud_maximize) {
        ShowWindow(m_window, SW_MAXIMIZE);
        m_shoud_maximize = false;
    } else {
        ShowWindow(m_window, SW_SHOW);
    }
    UpdateWindow(m_window);

    if (m_cursor_grabbed) {
        m_grabbed_cursor_diff = {0, 0};
        m_cursor_position     = get_cursor_position(m_window);
        update_cursor();
        enable_raw_input();
    }

    m_mouse_hover = is_cursor_in_client_area(m_window);

    // Turn on the on_resize callback
    m_message_handler->on_size = std::bind(&Win32Window::on_size_message, this, _1, _2, _3);

    // Turn on the on_move callback
    m_message_handler->on_move = std::bind(&Win32Window::on_move_message, this, _1, _2, _3);

    // Turn on the on_set_focus callback
    m_message_handler->on_set_focus = std::bind(&Win32Window::on_set_focus_message, this, _1, _2, _3);

    // Explicitly call on_show callback
    on_show();

    // Explicitly call on_move callback
    on_move(position());

    // Explicitly call on_resize callback
    on_resize(size());

    if (has_input_focus()) {
        on_focus();
    } else {
        focus();
    }
}

void Win32Window::hide()
{
    if (!is_visible() && !is_iconified()) {
        return;
    }

    if (has_input_focus()) {
        // Call the on_lost_focus callback explicitly
        on_lost_focus();
    }

    if (m_cursor_grabbed) {
        set_cursor_cliping(m_window, false);
        set_cursor_position(m_window, m_cursor_position);

        disable_raw_input();
    }

    ShowWindow(m_window, SW_HIDE);

    // Explicitly call on_hide callback
    on_hide();
}

void Win32Window::focus()
{
    if (!is_visible()) {
        return;
    }

    BringWindowToTop(m_window);
    SetForegroundWindow(m_window);
}

void Win32Window::iconify()
{
    ShowWindow(m_window, SW_MINIMIZE);
}

void Win32Window::maximize()
{
    if (!is_visible()) {
        m_shoud_maximize = true;
        return;
    }

    ShowWindow(m_window, SW_MAXIMIZE);
}

void Win32Window::fullscreen()
{
    if (is_fullscreen()) {
        return;
    }

    if (is_maximized()) {
        SendMessage(m_window, WM_SYSCOMMAND, SC_RESTORE, 0);
    }

    using namespace std::placeholders;

    // Turn off the on_resize callback
    m_message_handler->on_size = nullptr;

    // Turn off the on_move callback
    m_message_handler->on_move = nullptr;

    LONG style    = GetWindowLong(m_window, GWL_STYLE);
    LONG ex_style = GetWindowLong(m_window, GWL_EXSTYLE);
    GetWindowRect(m_window, &m_saved_info.rect);

    SetWindowLong(m_window, GWL_STYLE, style & ~(WS_CAPTION | WS_THICKFRAME));
    SetWindowLong(m_window,
                  GWL_EXSTYLE,
                  ex_style & ~(WS_EX_DLGMODALFRAME | WS_EX_WINDOWEDGE | WS_EX_CLIENTEDGE | WS_EX_STATICEDGE));

    MONITORINFO monitor_info = {};
    monitor_info.cbSize      = sizeof(monitor_info);
    GetMonitorInfo(MonitorFromWindow(m_window, MONITOR_DEFAULTTONEAREST), &monitor_info);

    SetWindowPos(m_window,
                 HWND_TOP,
                 monitor_info.rcMonitor.left,
                 monitor_info.rcMonitor.top,
                 monitor_info.rcMonitor.right,
                 monitor_info.rcMonitor.bottom,
                 SWP_NOZORDER | SWP_NOACTIVATE | SWP_FRAMECHANGED);

    SetForegroundWindow(m_window);

    // Turn on the on_resize callback
    m_message_handler->on_size = std::bind(&Win32Window::on_size_message, this, _1, _2, _3);

    // Turn on the on_move callback
    m_message_handler->on_move = std::bind(&Win32Window::on_move_message, this, _1, _2, _3);

    if (is_visible()) {
        // Explicitly call on_move callback
        on_move(position());

        // Explicitly call on_resize callback
        on_resize(size());
    }
}

void Win32Window::restore()
{
    using namespace std::placeholders;

    // Turn off the on_resize callback
    m_message_handler->on_size = nullptr;

    // Turn off the on_move callback
    m_message_handler->on_move = nullptr;

    bool restored = false;

    if (is_fullscreen()) {
        LONG style    = GetWindowLong(m_window, GWL_STYLE);
        LONG ex_style = GetWindowLong(m_window, GWL_EXSTYLE);

        SetWindowLong(m_window, GWL_STYLE, style | WS_CAPTION | WS_THICKFRAME);
        SetWindowLong(m_window,
                      GWL_EXSTYLE,
                      ex_style | WS_EX_DLGMODALFRAME | WS_EX_WINDOWEDGE | WS_EX_CLIENTEDGE | WS_EX_STATICEDGE);

        SetWindowPos(m_window,
                     HWND_TOP,
                     m_saved_info.rect.left,
                     m_saved_info.rect.top,
                     m_saved_info.rect.right - m_saved_info.rect.left,
                     m_saved_info.rect.bottom - m_saved_info.rect.top,
                     SWP_NOZORDER | SWP_NOACTIVATE | SWP_FRAMECHANGED);
        restored = true;
    } else if (is_iconified()) {
        ShowWindow(m_window, SW_RESTORE);
        restored = true;
    } else if (is_maximized()) {
        ShowWindow(m_window, SW_RESTORE);
        m_shoud_maximize = false;
        restored         = true;
    }

    // Turn on the on_resize callback
    m_message_handler->on_size = std::bind(&Win32Window::on_size_message, this, _1, _2, _3);

    // Turn on the on_move callback
    m_message_handler->on_move = std::bind(&Win32Window::on_move_message, this, _1, _2, _3);

    if (restored && is_visible()) {
        // Explicitly call on_move callback
        on_move(position());

        // Explicitly call on_resize callback
        on_resize(size());
    }
}

void Win32Window::resize(Size size)
{
    auto style = GetWindowLong(m_window, GWL_STYLE);
    size       = adjust_size(size, style);
    SetWindowPos(m_window,
                 HWND_TOP,
                 0,
                 0,
                 size.width,
                 size.height,
                 SWP_NOMOVE | SWP_NOZORDER | SWP_NOOWNERZORDER | SWP_NOACTIVATE);
}

void Win32Window::move(Position position)
{
    RECT rect = {position.x, position.y, position.x, position.y};

    auto style    = GetWindowLong(m_window, GWL_STYLE);
    auto ex_style = GetWindowLong(m_window, GWL_EXSTYLE);

    AdjustWindowRectEx(&rect, style, false, ex_style);

    SetWindowPos(m_window,
                 HWND_TOP,
                 rect.left,
                 rect.top,
                 0,
                 0,
                 SWP_NOSIZE | SWP_NOZORDER | SWP_NOOWNERZORDER | SWP_NOACTIVATE);
}

void Win32Window::grab_cursor()
{
    if (m_cursor_grabbed) {
        return;
    }

    m_cursor_grabbed = true;

    m_grabbed_cursor_diff = {0, 0};
    m_cursor_position     = get_cursor_position(m_window);
    update_cursor();
    enable_raw_input();
}

void Win32Window::release_cursor()
{
    if (!m_cursor_grabbed) {
        return;
    }

    m_cursor_grabbed = false;
    set_cursor_cliping(m_window, false);
    set_cursor_position(m_window, m_cursor_position);

    disable_raw_input();
}

void Win32Window::process_events()
{
    MSG message = {};

    while (PeekMessage(&message, nullptr, 0, 0, PM_REMOVE)) {
        if (message.message == WM_QUIT) {
            m_should_close = true;
            on_close();
        } else {
            TranslateMessage(&message);
            DispatchMessage(&message);
        }
    }
}

#pragma endregion

#pragma region setters

void Win32Window::set_max_size(Size max_size)
{
    m_max_size = max_size;
}

void Win32Window::set_min_size(Size min_size)
{
    m_min_size = min_size;
}

void Win32Window::set_resizable(bool value)
{
    m_resizable = value;

    auto style = GetWindowLong(m_window, GWL_STYLE);

    if (!m_resizable) {
        style &= ~(WS_SIZEBOX | WS_MAXIMIZEBOX);
    } else {
        style |= (WS_SIZEBOX | WS_MAXIMIZEBOX);
    }

    SetWindowLong(m_window, GWL_STYLE, style);

    Size sz = adjust_size(size(), style);
    SetWindowPos(m_window, HWND_TOP, 0, 0, sz.width, sz.height, SWP_NOMOVE | SWP_NOZORDER | SWP_FRAMECHANGED);
}

void Win32Window::set_title(const std::string& title)
{
    const auto whide_char_title = utf::to_wstring(title);
    SetWindowText(m_window, &whide_char_title[0]);
}

void Win32Window::set_cursor_visibility(bool visible)
{
    m_cursor_visible = visible;
    if (m_cursor_visible) {
        SetCursor(LoadCursor(nullptr, IDC_ARROW));
    } else {
        SetCursor(nullptr);
    }
}

#pragma endregion

#pragma region getters

Position Win32Window::position() const
{
    POINT pos = {0, 0};
    ClientToScreen(m_window, &pos);

    return Position{pos.x, pos.y};
}

Size Win32Window::size() const
{
    RECT area;
    GetClientRect(m_window, &area);

    return Size{area.right, area.bottom};
}

Size Win32Window::max_size() const
{
    return m_max_size;
}

Size Win32Window::min_size() const
{
    return m_min_size;
}

std::string Win32Window::title() const
{
    const int32 title_length = GetWindowTextLength(m_window) + 1;

    if (title_length == 1) {
        return std::string();
    }

    std::unique_ptr<wchar_t[]> buffer(new wchar_t[static_cast<std::size_t>(title_length)]);
    GetWindowText(m_window, buffer.get(), title_length);

    return utf::to_utf8(buffer.get());
}

const Context& Win32Window::context() const
{
    if (m_context == nullptr) {
        throw std::runtime_error("Graphic context was not created.");
    }

    return *m_context;
}

Context& Win32Window::context()
{
    if (m_context == nullptr) {
        throw std::runtime_error("Graphic context was not created.");
    }

    return *m_context;
}

#pragma endregion

#pragma region state

bool Win32Window::should_close() const
{
    return m_should_close;
}

bool Win32Window::is_fullscreen() const
{
    RECT window_rect;
    RECT desktop_rect;
    GetWindowRect(m_window, &window_rect);
    GetWindowRect(GetDesktopWindow(), &desktop_rect);

    return (window_rect.left == desktop_rect.left && window_rect.top == desktop_rect.top &&
            window_rect.right == desktop_rect.right && window_rect.bottom == desktop_rect.bottom);
}

bool Win32Window::is_iconified() const
{
    return IsIconic(m_window) != 0;
}

bool Win32Window::is_maximized() const
{
    return IsZoomed(m_window) != 0 || m_shoud_maximize;
}

bool Win32Window::is_resizable() const
{
    return m_resizable;
}

bool Win32Window::is_visible() const
{
    return IsWindowVisible(m_window) && !is_iconified();
    ;
}

bool Win32Window::has_input_focus() const
{
    return GetActiveWindow() == m_window && GetFocus() == m_window;
}

bool Win32Window::is_cursor_visible() const
{
    return GetCursor() != nullptr;
}

bool Win32Window::is_cursor_grabbed() const
{
    return m_cursor_grabbed;
}

#pragma endregion

#pragma region message processing

LRESULT Win32Window::process_message(UINT message, WPARAM w_param, LPARAM l_param)
{
    switch (message) {
        case WM_SETFOCUS: return m_message_handler->process_set_focus_message(message, w_param, l_param);
        case WM_KILLFOCUS: return m_message_handler->process_kill_focus_message(message, w_param, l_param);
        case WM_CLOSE: return m_message_handler->process_close_message(message, w_param, l_param);
        case WM_MOVE: return m_message_handler->process_move_message(message, w_param, l_param);
        case WM_SIZE: return m_message_handler->process_size_message(message, w_param, l_param);
        case WM_GETMINMAXINFO: return m_message_handler->process_get_min_max_info_message(message, w_param, l_param);

        case WM_MOUSELEAVE: return m_message_handler->process_mouse_leave_message(message, w_param, l_param);
        case WM_MOUSEHOVER: return m_message_handler->process_mouse_hover_message(message, w_param, l_param);
        case WM_MOUSEMOVE: return m_message_handler->process_mouse_move_message(message, w_param, l_param);

        case WM_LBUTTONDOWN:
        case WM_MBUTTONDOWN:
        case WM_RBUTTONDOWN:
        case WM_LBUTTONUP:
        case WM_MBUTTONUP:
        case WM_RBUTTONUP:
        case WM_XBUTTONDOWN:
        case WM_XBUTTONUP: return m_message_handler->process_mouse_button_message(message, w_param, l_param);

        case WM_MOUSEHWHEEL:
        case WM_MOUSEWHEEL: return m_message_handler->process_mouse_wheel_message(message, w_param, l_param);

        case WM_KEYDOWN:
        case WM_KEYUP:
        case WM_SYSKEYDOWN:
        case WM_SYSKEYUP:
            m_message_handler->process_key_message(message, w_param, l_param);
            break; // Just break, to pass event to DefWindowProc

        case WM_UNICHAR: return m_message_handler->process_unichar_message(message, w_param, l_param);

        case WM_CHAR:
        case WM_SYSCHAR: return m_message_handler->process_char_message(message, w_param, l_param);

        case WM_INPUT:
            m_message_handler->process_input_message(message, w_param, l_param);
            break; // Just break, to pass event to DefWindowProc

        case WM_SYSCOMMAND: {
            switch (w_param & 0xfff0) {
                case SC_SCREENSAVE:
                case SC_MONITORPOWER: {
                    // We are running in full screen mode, so disallow screen saver and screen blanking
                    if (is_fullscreen()) {
                        return 0;
                    } else
                        break;
                }

                // Don't forward the menu system command, so that pressing ALT or F10 doesn't steal the focus
                case SC_KEYMENU: return 0;
            }
            break;
        }
    }

    return DefWindowProc(m_window, message, w_param, l_param);
}

LRESULT Win32Window::on_set_focus_message(UINT, WPARAM, LPARAM)
{
    if (is_visible()) {
        on_focus();
    }

    return 0;
}

LRESULT Win32Window::on_kill_focus_message(UINT, WPARAM, LPARAM)
{
    if (is_visible()) {
        on_lost_focus();
    }

    return 0;
}

LRESULT Win32Window::on_close_message(UINT, WPARAM, LPARAM)
{
    m_should_close = true;
    on_close();

    return 0;
}

LRESULT Win32Window::on_move_message(UINT, WPARAM, LPARAM)
{
    if (is_visible()) {
        update_cursor();
        on_move(position());
    }

    return 0;
}

LRESULT Win32Window::on_size_message(UINT, WPARAM, LPARAM)
{
    if (is_visible()) {
        update_cursor();
        on_resize(size());
    }

    return 0;
}

LRESULT Win32Window::on_get_min_max_info_message(UINT, WPARAM, LPARAM l_param)
{
    auto minmaxinfo  = reinterpret_cast<MINMAXINFO*>(l_param);
    const auto style = GetWindowLong(m_window, GWL_STYLE);

    if (m_min_size.width != 0 && m_min_size.height != 0) {
        const Size size = adjust_size(m_min_size, style);

        minmaxinfo->ptMinTrackSize.x = size.width;
        minmaxinfo->ptMinTrackSize.y = size.height;
    }

    if (m_max_size.width != 0 && m_max_size.height != 0) {
        const Size size = adjust_size(m_max_size, style);

        minmaxinfo->ptMaxTrackSize.x = size.width;
        minmaxinfo->ptMaxTrackSize.y = size.height;
    }

    return 0;
}

LRESULT Win32Window::on_mouse_leave_message(UINT, WPARAM, LPARAM)
{
    on_mouse_leave();
    m_mouse_hover = false;

    return 0;
}

LRESULT Win32Window::on_mouse_hover_message(UINT, WPARAM, LPARAM)
{
    on_mouse_enter();
    m_mouse_hover = true;

    return 0;
}

LRESULT Win32Window::on_mouse_move_message(UINT, WPARAM, LPARAM l_param)
{
    track_mouse();

    CursorPosition pos{LOWORD(l_param), HIWORD(l_param)};

    if (!m_cursor_grabbed) {
        m_cursor_position = pos;
        on_mouse_move(pos);
    }

    return 0;
}

LRESULT Win32Window::on_mouse_button_message(UINT message, WPARAM w_param, LPARAM l_param)
{
    const MouseButton button = get_mouse_button(message, w_param);
    const CursorPosition position{GET_X_LPARAM(l_param), GET_Y_LPARAM(l_param)};
    const Modifiers mod_state = get_modifiers_state();

    const bool down = (message == WM_LBUTTONDOWN || message == WM_MBUTTONDOWN || message == WM_RBUTTONDOWN ||
                       message == WM_XBUTTONDOWN);

    if (button != MouseButton::unknown) {
        if (down) {
            on_mouse_button_down(button, position, mod_state);
        } else {
            on_mouse_button_up(button, position, mod_state);
        }
    }

    if (message == WM_XBUTTONDOWN || message == WM_XBUTTONUP) {
        return TRUE;
    }

    return 0;
}

LRESULT Win32Window::on_mouse_wheel_message(UINT message, WPARAM w_param, LPARAM)
{
    const short delta = GET_WHEEL_DELTA_WPARAM(w_param);

    switch (message) {
        case WM_MOUSEWHEEL:
            // A positive value indicates that the wheel was rotated forward, away from the user; a negative value
            // indicates that the wheel was rotated backward, toward the user.
            on_mouse_scroll(ScrollOffset{0, delta});
            break;
        case WM_MOUSEHWHEEL:
            // A positive value indicates that the wheel was rotated to the right; a negative value indicates that
            // the wheel was rotated to the left.
            on_mouse_scroll(ScrollOffset{delta, 0});
            break;
    }

    return 0;
}

LRESULT Win32Window::on_key_message(UINT, WPARAM w_param, LPARAM l_param)
{
    switch (w_param) {
        case VK_SHIFT: process_shift_key(l_param); return 0;
        case VK_CONTROL: process_control_key(l_param); return 0;
        case VK_MENU: process_alt_key(l_param); return 0;
        default: break;
    }

    const KeyCode key         = details::map_system_key(static_cast<std::uint32_t>(w_param));
    const Modifiers mod_state = details::get_modifiers_state();
    const bool key_is_down    = ((l_param >> 31) & 1) == 0;

    if (key == KeyCode::unknown) {
        return 0;
    }

    // Print screen does not emmit key down event.
    if (key == KeyCode::key_print_screen) {
        on_key_down(key, mod_state);
        on_key_up(key, mod_state);
        return 0;
    }

    if (key_is_down) {
        on_key_down(key, mod_state);
    } else {
        on_key_up(key, mod_state);
    }

    return 0;
}

LRESULT Win32Window::on_unichar_message(UINT, WPARAM w_param, LPARAM)
{
    if (w_param == UNICODE_NOCHAR) {
        // The WM_UNICHAR message can be used by an application to post input to other windows
        // Returning TRUE here announces support for this message
        return TRUE;
    }
    wchar_t wchar = static_cast<wchar_t>(w_param);
    std::wstring s;
    s += wchar;
    on_character(utf::to_utf8(s));

    return 0;
}

LRESULT Win32Window::on_char_message(UINT, WPARAM w_param, LPARAM)
{
    wchar_t wchar = static_cast<wchar_t>(w_param);
    std::wstring s;
    s += wchar;
    on_character(utf::to_utf8(s));

    return 0;
}

LRESULT Win32Window::on_input_message(UINT, WPARAM, LPARAM l_param)
{
    if (!m_cursor_grabbed) {
        return 0;
    }

    HRAWINPUT handle = reinterpret_cast<HRAWINPUT>(l_param);

    UINT size = 0;
    GetRawInputData(handle, RID_INPUT, nullptr, &size, sizeof(RAWINPUTHEADER));

    RAWINPUT raw_input = RAWINPUT();
    if (GetRawInputData(handle, RID_INPUT, &raw_input, &size, sizeof(RAWINPUTHEADER)) == static_cast<UINT>(-1)) {
        return 0;
    }

    CursorPosition pos = m_cursor_position;
    pos.x += m_grabbed_cursor_diff.x;
    pos.y += m_grabbed_cursor_diff.y;

    int dx = 0;
    int dy = 0;

    if (raw_input.data.mouse.usFlags & MOUSE_MOVE_ABSOLUTE) {
        dx = raw_input.data.mouse.lLastX - pos.x;
        dy = raw_input.data.mouse.lLastY - pos.y;
    } else {
        dx = raw_input.data.mouse.lLastX;
        dy = raw_input.data.mouse.lLastY;
    }

    m_grabbed_cursor_diff.x += dx;
    m_grabbed_cursor_diff.y += dy;
    pos.x += dx;
    pos.y += dy;

    if (dx != 0 || dy != 0) {
        set_cursor_in_center(m_window);
    }

    on_mouse_move(pos);

    return 0;
}

#pragma endregion

#pragma region keyboard processing

void Win32Window::process_shift_key(LPARAM l_param)
{
    const bool key_is_down    = ((l_param >> 31) & 1) == 0;
    const Modifiers mod_state = details::get_modifiers_state();

    const bool left_shift  = ((GetKeyState(VK_LSHIFT) & 0x8000));
    const bool right_shift = ((GetKeyState(VK_RSHIFT) & 0x8000));

    if (key_is_down) {
        if (left_shift != m_modifiers_flags.left_shift) {
            on_key_down(KeyCode::key_left_shift, mod_state);
        } else if (right_shift != m_modifiers_flags.right_shift) {
            on_key_down(KeyCode::key_right_shift, mod_state);
        }
    } else {
        if (m_modifiers_flags.left_shift) {
            on_key_up(KeyCode::key_left_shift, mod_state);
        }
        if (m_modifiers_flags.right_shift) {
            on_key_up(KeyCode::key_right_shift, mod_state);
        }
    }

    m_modifiers_flags.left_shift  = left_shift;
    m_modifiers_flags.right_shift = right_shift;
}

void Win32Window::process_control_key(LPARAM l_param)
{
    const bool key_is_down    = ((l_param >> 31) & 1) == 0;
    const Modifiers mod_state = details::get_modifiers_state();

    const bool left_control  = ((GetKeyState(VK_LCONTROL) & 0x8000));
    const bool right_control = ((GetKeyState(VK_RCONTROL) & 0x8000));

    KeyCode key = KeyCode::unknown;
    if (left_control != m_modifiers_flags.left_control) {
        key = KeyCode::key_left_control;
    } else if (right_control != m_modifiers_flags.right_control) {
        key = KeyCode::key_right_control;
    } else {
        return;
    }

    if (key_is_down) {
        on_key_down(key, mod_state);
    } else {
        on_key_up(key, mod_state);
    }

    m_modifiers_flags.left_control  = left_control;
    m_modifiers_flags.right_control = right_control;
}

void Win32Window::process_alt_key(LPARAM l_param)
{
    const bool key_is_down    = ((l_param >> 31) & 1) == 0;
    const Modifiers mod_state = details::get_modifiers_state();

    const bool left_alt  = ((GetKeyState(VK_LMENU) & 0x8000));
    const bool right_alt = ((GetKeyState(VK_RMENU) & 0x8000));

    KeyCode key = KeyCode::unknown;
    if (left_alt != m_modifiers_flags.left_alt) {
        key = KeyCode::key_left_alt;
    } else if (right_alt != m_modifiers_flags.right_alt) {
        key = KeyCode::key_right_alt;
    } else {
        return;
    }

    if (key_is_down) {
        on_key_down(key, mod_state);
    } else {
        on_key_up(key, mod_state);
    }

    m_modifiers_flags.left_alt  = left_alt;
    m_modifiers_flags.right_alt = right_alt;
}

#pragma endregion

#pragma region mouse handling

void Win32Window::track_mouse()
{
    TRACKMOUSEEVENT track_info;
    track_info.cbSize      = sizeof(track_info);
    track_info.dwFlags     = m_mouse_hover ? TME_LEAVE : TME_HOVER;
    track_info.hwndTrack   = m_window;
    track_info.dwHoverTime = 1;

    TrackMouseEvent(&track_info);
}

void Win32Window::update_cursor()
{
    if (m_cursor_grabbed) {
        set_cursor_in_center(m_window);
        set_cursor_cliping(m_window, true);
    }
}

void Win32Window::enable_raw_input()
{
    const RAWINPUTDEVICE rid = {HID_USAGE_PAGE_GENERIC, HID_USAGE_GENERIC_MOUSE, 0, m_window};
    RegisterRawInputDevices(&rid, 1, sizeof(rid));
}

void Win32Window::disable_raw_input()
{
    const RAWINPUTDEVICE rid = {HID_USAGE_PAGE_GENERIC, HID_USAGE_GENERIC_MOUSE, RIDEV_REMOVE, nullptr};
    RegisterRawInputDevices(&rid, 1, sizeof(rid));
}

#pragma endregion

} // namespace framework::system::details
