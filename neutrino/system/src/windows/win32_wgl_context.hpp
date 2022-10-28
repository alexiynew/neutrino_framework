#ifndef FRAMEWORK_WINDOW_DETAILS_WINDOWS_WIN32_CONTEXT_HPP
#define FRAMEWORK_WINDOW_DETAILS_WINDOWS_WIN32_CONTEXT_HPP

#include <system/context.hpp>

#include <Windows.h>

namespace framework::system::details
{
class Win32WglContext final : public Context
{
public:
    Win32WglContext(HWND window, const ContextSettings& settings);
    ~Win32WglContext() override;

    Win32WglContext(const Win32WglContext&) = default;
    Win32WglContext(Win32WglContext&&)      = default;

    Win32WglContext& operator=(const Win32WglContext&) = default;
    Win32WglContext& operator=(Win32WglContext&&)      = default;

    bool is_valid() const override;
    bool is_current() const override;
    Api api_type() const override;

    void make_current() override;
    void swap_buffers() override;

private:
    using VoidFunctionPtr = void (*)();

    VoidFunctionPtr get_function(const char* function_name) const;

    HWND m_window = nullptr;
    HDC m_hdc     = nullptr;
    HGLRC m_hglrc = nullptr;
};

} // namespace framework::system::details

#endif
