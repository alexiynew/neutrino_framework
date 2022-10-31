#ifndef FRAMEWORK_WINDOW_DETAILS_WINDOWS_WIN32_APPLICATION_HPP
#define FRAMEWORK_WINDOW_DETAILS_WINDOWS_WIN32_APPLICATION_HPP

#include <map>

#include <Windows.h>

namespace neutrino::system::details
{
class Win32Window;

class Win32Application
{
public:
    static void add_window(HANDLE handle, Win32Window* window);
    static Win32Window* get_window(HANDLE handle);
    static void remove_window(HANDLE handle);

    static HMODULE handle();

    static LPCWSTR get_window_class();

    static LRESULT CALLBACK main_window_procedure(HWND window_handle, UINT message, WPARAM w_param, LPARAM l_param);

private:
    using HandleToWindowMap = std::map<HANDLE, Win32Window*>;

    static const std::wstring& get_window_class_name();

    static HandleToWindowMap m_windows;
    static HMODULE m_handle;

    static std::wstring m_window_class_name;
    static LPCWSTR m_window_class;
};

} // namespace neutrino::system::details

#endif
