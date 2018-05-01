/// @file
/// @brief Window implementation for windows.
/// @author Fedorov Alexey
/// @date 19.04.2017

#include <exception>

#include <log/log.hpp>
#include <window/windows/win32_window.hpp>

namespace {
const wchar_t g_szClassName[] = L"myWindowClass";

// Step 4: the Window Procedure
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg) {
        case WM_CLOSE: DestroyWindow(hwnd); break;
        case WM_DESTROY: PostQuitMessage(0); break;
        default: return DefWindowProc(hwnd, msg, wParam, lParam);
    }
    return 0;
}

std::wstring to_utf16(const std::string& string)
{
    if (string.empty()) {
        return std::wstring();
    }

    int size = MultiByteToWideChar(CP_UTF8, 0, &string[0], static_cast<int>(string.size()), 0, 0);
    std::wstring result(size, 0);
    MultiByteToWideChar(CP_UTF8, 0, &string[0], static_cast<int>(string.size()), &result[0], size);

    return result;
}

HMODULE application_handle()
{
    static HMODULE handle = GetModuleHandle(nullptr);

    if (handle == nullptr) {
        throw std::runtime_error("Failed to get application instance handle.");
    }

    return handle;
}

void unregister_window_class(ATOM*)
{
    UnregisterClass(g_szClassName, application_handle());
}

std::shared_ptr<ATOM> register_window_class_details()
{
    WNDCLASSEX window_class = {0};

    window_class.cbSize        = sizeof(WNDCLASSEX);
    window_class.style         = CS_OWNDC;
    window_class.lpfnWndProc   = WndProc;
    window_class.cbClsExtra    = 0;
    window_class.cbWndExtra    = 0;
    window_class.hInstance     = application_handle();
    window_class.hIcon         = LoadIcon(nullptr, IDI_APPLICATION);
    window_class.hCursor       = LoadCursor(nullptr, IDC_ARROW);
    window_class.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    window_class.lpszMenuName  = nullptr;
    window_class.lpszClassName = g_szClassName;
    window_class.hIconSm       = LoadIcon(nullptr, IDI_APPLICATION);

    if (!RegisterClassEx(&window_class)) {
        throw std::runtime_error("Failed to register window class.");
    }

    return std::shared_ptr<ATOM>(nullptr, unregister_window_class);
}

std::shared_ptr<ATOM> register_window_class()
{
    static std::weak_ptr<ATOM> pointer;

    if (pointer.expired()) {
        std::shared_ptr<ATOM> temp = ::register_window_class_details();

        pointer = temp;

        return temp;
    }

    return pointer.lock();
}

} // namespace

namespace framework {

std::unique_ptr<window::implementation> window::implementation::get_implementation(window::size_t size,
                                                                                   const std::string& title)
{
    return std::make_unique<win32_window>(size, title);
}

win32_window::win32_window(window::size_t size, const std::string& title) : m_size(size)
{
    m_window_class = ::register_window_class();

    m_window = CreateWindowEx(WS_EX_CLIENTEDGE,
                              g_szClassName,
                              to_utf16(title).c_str(),
                              WS_OVERLAPPEDWINDOW,
                              CW_USEDEFAULT,
                              CW_USEDEFAULT,
                              m_size.width,
                              m_size.height,
                              nullptr,
                              nullptr,
                              application_handle(),
                              nullptr);

    if (m_window == nullptr) {
        throw std::runtime_error("Failed to create window.");
    }

    // The first call ignores its parameters
    ShowWindow(m_window, SW_HIDE);
}

win32_window::~win32_window()
{
    DestroyWindow(m_window);
}

/// @name actions
/// @{
void win32_window::show()
{
    ShowWindow(m_window, SW_SHOW);
    UpdateWindow(m_window);
}

void win32_window::hide()
{
    ShowWindow(m_window, SW_HIDE);
}

void win32_window::focus()
{
    BringWindowToTop(m_window);
    SetForegroundWindow(m_window);
}

void win32_window::process_events()
{
    MSG message = {0};

    while (PeekMessage(&message, nullptr, 0, 0, PM_REMOVE)) {
        if (message.message == WM_QUIT) {
            // TODO: process close requet
        } else {
            TranslateMessage(&message);
            DispatchMessage(&message);
        }
    }
}

void win32_window::minimize()
{
    throw std::logic_error("Function is not implemented.");
}

void win32_window::maximize()
{
    throw std::logic_error("Function is not implemented.");
}

void win32_window::switch_to_fullscreen()
{
    throw std::logic_error("Function is not implemented.");
}

void win32_window::restore()
{
    throw std::logic_error("Function is not implemented.");
}
/// @}

/// @name setters
/// @{
void win32_window::set_size(window::size_t)
{
    throw std::logic_error("Function is not implemented.");
}

void win32_window::set_position(window::position_t)
{
    throw std::logic_error("Function is not implemented.");
}

void win32_window::set_max_size(window::size_t)
{
    throw std::logic_error("Function is not implemented.");
}

void win32_window::set_min_size(window::size_t)
{
    throw std::logic_error("Function is not implemented.");
}

void win32_window::set_resizable(bool)
{
    throw std::logic_error("Function is not implemented.");
}

void win32_window::set_title(const std::string&)
{
    throw std::logic_error("Function is not implemented.");
}
/// @}

/// @name getters
/// @{
window::position_t win32_window::position() const
{
    throw std::logic_error("Function is not implemented.");
}

window::size_t win32_window::size() const
{
    throw std::logic_error("Function is not implemented.");
}

window::size_t win32_window::max_size() const
{
    throw std::logic_error("Function is not implemented.");
}

window::size_t win32_window::min_size() const
{
    throw std::logic_error("Function is not implemented.");
}

std::string win32_window::title() const
{
    throw std::logic_error("Function is not implemented.");
}
/// @}

/// @name state
/// @{
bool win32_window::fullscreen() const
{
    throw std::logic_error("Function is not implemented.");
}

bool win32_window::minimized() const
{
    throw std::logic_error("Function is not implemented.");
}

bool win32_window::maximized() const
{
    throw std::logic_error("Function is not implemented.");
}

bool win32_window::resizable() const
{
    throw std::logic_error("Function is not implemented.");
}

bool win32_window::visible() const
{
    return IsWindowVisible(m_window);
}

bool win32_window::focused() const
{
    return GetActiveWindow() == m_window && GetFocus() == m_window;
}
/// @}

} // namespace framework
