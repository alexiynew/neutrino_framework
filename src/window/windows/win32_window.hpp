/// @file
/// @brief Window implementation for windows.
/// @author Fedorov Alexey
/// @date 19.04.2017

#ifndef FRAMEWORK_WINDOW_WINDOWS_WIN32_WINDOW_HPP
#define FRAMEWORK_WINDOW_WINDOWS_WIN32_WINDOW_HPP

#include <Windows.h>

#include <window/implementation.hpp>

class application;

namespace framework {

class win32_window final : public window::implementation
{
public:
    win32_window(window::size_t size, const std::string& title);
    ~win32_window() override;

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
    HWND m_window = nullptr;
    std::shared_ptr<ATOM> m_window_class;

    window::size_t m_min_size = {0, 0};
    window::size_t m_max_size = {0, 0};

    bool m_resizable = true;

    friend class ::application;

    LRESULT process_message(UINT message, WPARAM w_param, LPARAM l_param);
};

} // namespace framework

#endif
