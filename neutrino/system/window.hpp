/// @file
/// @brief Window interface class.
/// @author Fedorov Alexey
/// @date 04.04.2017

// =============================================================================
// MIT License
//
// Copyright (c) 2017-2019 Fedorov Alexey
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
// =============================================================================

#ifndef FRAMEWORK_SYSTEM_WINDOW_HPP
#define FRAMEWORK_SYSTEM_WINDOW_HPP

#include <functional>
#include <memory>

#include <common/position.hpp>
#include <common/signal.hpp>
#include <common/size.hpp>
#include <system/context_settings.hpp>
#include <system/keyboard.hpp>
#include <system/mouse.hpp>

/// @details
///
/// Contains different OS related stuff.
///
/// @defgroup system_module System
/// @{

/// @defgroup window_class Window

/// @}

/// @brief Operating System related classes.
namespace framework::system
{
namespace details
{
/// @brief Base class for OS specific window realisation.
class PlatformWindow;
} // namespace details

/// @addtogroup window_class
/// @{

/// @brief Window class.
///
/// Window, abstracts all window management, input processing, and event handling.
class Window final
{
public:
    /// @brief Sets the formal name of the application.
    ///
    /// @param name Application name.
    static void set_application_name(const std::string& name);

    /// @brief Creates window.
    ///
    /// @param size Window size.
    /// @param title Window name.
    /// @param settings Gpaphic context settings.
    ///
    /// @thread_safety This function can be called only from main thread.
    Window(Size size, const std::string& title, ContextSettings settings = ContextSettings());

    /// @brief Destructor.
    ~Window();

    Window(const Window&) = delete;
    Window& operator=(const Window&) = delete;

    /// @brief Move constructor.
    ///
    /// @param other Window to move from.
    Window(Window&& other) noexcept;

    /// @brief Move operator.
    ///
    /// @param other Window to move from.
    ///
    /// @return Reference to moved object.
    Window& operator=(Window&& other) noexcept;

    /// @name actions
    /// @{

    /// @brief Makes the window visible.
    void show();

    /// @brief Hides the window.
    void hide();

    /// @brief If window is visible, brings it to the front and may make it the focused.
    void focus();

    /// @brief Switch window to iconic state.
    void iconify();

    /// @brief Maximize window.
    void maximize();

    /// @brief Switch to fullscreen mode.
    void fullscreen();

    /// @brief Restore normal window mode.
    void restore();

    /// @brief Resize window.
    ///
    /// @param size New window size.
    void resize(Size size);

    /// @brief Move window.
    ///
    /// @param position New winodw position.
    void move(Position position);

    /// @brief Pull all system events and process it.
    void process_events();

    /// @brief Marks the window as target for drawing operations.
    void make_current();

    /// @brief Shows on window what has been drawed.
    void swap_buffers();

    /// @}

    /// @name setters
    /// @{

    /// @brief Sets maximum window size.
    ///
    /// @param size Maximum window size.
    void set_max_size(Size size);

    /// @brief Sets minimum window size.
    ///
    /// @param size Minimum window size.
    void set_min_size(Size size);

    /// @brief Forbids/permits window resizing.
    ///
    /// When the value is false, window can't be resized by the user.
    /// The @ref size function can still change the window size.
    ///
    /// @param value Is window resizable.
    void set_resizable(bool value);

    /// @brief Sets window title.
    ///
    /// @param title New window title.
    void set_title(const std::string& title);

    /// @}

    /// @name getters
    /// @{

    /// @brief Window position.
    ///
    /// @return Current window position.
    Position position() const;

    /// @brief Window size.
    ///
    /// @return Current window size.
    Size size() const;

    /// @brief Maximum window size.
    ///
    /// @return Current maximum size.
    Size max_size() const;

    /// @brief Minimum window size.
    ///
    /// @return Current minimum size.
    Size min_size() const;

    /// @brief Window title.
    ///
    /// @return Current window title.
    std::string title() const;

    /// @name state
    /// @{

    /// @brief Checks if window is should be destoyed.
    ///
    /// @return `true` if on_close signal was emited.
    bool should_close() const;

    /// @brief Checks if window is in fullscreen mode.
    ///
    /// @return `true` if window is in fullscreen mode.
    bool is_fullscreen() const;

    /// @brief Checks if window is in iconic state.
    ///
    /// @return `true` if window is in iconic state.
    bool is_iconified() const;

    /// @brief Checks if window is maximized.
    ///
    /// @return `true` if window is maximized.
    bool is_maximized() const;

    /// @brief Checks if window resizing is allowed.
    ///
    /// @return `true` if window resizing is allowed.
    bool is_resizable() const;

    /// @brief Checks if window is visible to the user.
    ///
    /// @return `true` if window is visible.
    bool is_visible() const;

    /// @brief Checks if window has input focus.
    ///
    /// @return `true` if window is focused.
    bool has_input_focus() const;
    /// @}

    /// @name events
    /// @{

    /// @brief Set on show callback. Called when window shows after creation.
    Signal<const Window&> on_show;

    /// @brief Set on hide callback. Called when window hides from screen.
    Signal<const Window&> on_hide;

    /// @brief Set on close callback. Called when the user clicks on the close window button.
    Signal<const Window&> on_close;

    /// @brief Set on focus callback. Called when the window gets input focus.
    Signal<const Window&> on_focus;

    /// @brief Set on focus lost callback. Called when the window loses input focus.
    Signal<const Window&> on_lost_focus;

    /// @brief Set on size callback. Called when window size changes.
    Signal<const Window&, Size> on_resize;

    /// @brief Set on position callback. Called when window position changes.
    Signal<const Window&, Position> on_move;

    /// @brief Set on key press callback. Called when key is pressed. Can be called multiple times.
    Signal<const Window&, KeyCode, Modifiers> on_key_down;

    /// @brief Set on key release callback. Called when key is released.
    Signal<const Window&, KeyCode, Modifiers> on_key_up;

    /// @brief Set on character callback. Called when user press the char symbol key.
    Signal<const Window&, std::string> on_character;

    /// @brief Set on mouse move callback. Called when the mouse is moving.
    Signal<const Window&, CursorPosition> on_mouse_move;

    /// @brief Set on mouse button press callback. Called when the mouse button is pressed.
    Signal<const Window&, MouseButton, CursorPosition, Modifiers> on_button_down;

    /// @brief Set on mouse button release callback. Called when the mouse button is released.
    Signal<const Window&, MouseButton, CursorPosition, Modifiers> on_button_up;

    /// @brief Set on mouse enter callback. Called when the cursor enters in the window frame.
    Signal<const Window&> on_mouse_enter;

    /// @brief Set on mouse leave callback. Called when the cursor leaves the window frame.
    Signal<const Window&> on_mouse_leave;
    /// @}

private:
    std::unique_ptr<details::PlatformWindow> m_platform_window;
};

/// @}

} // namespace framework::system

#endif
