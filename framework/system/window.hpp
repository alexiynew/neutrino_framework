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

#include <graphics/context.hpp>
#include <system/details/window_position.hpp>
#include <system/details/window_size.hpp>
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
/// @brief Base class for OS specific realisation.
class implementation;

/// @brief Helper class to handle events.
class event_handler;

} // namespace details

/// @addtogroup window_class
/// @{

/// @brief A Window class.
///
/// OpenGL-based window, abstracts all window management, input processing, and event handling.
class window final
{
public:
    using size_t     = details::window_size;
    using position_t = details::window_position;

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
    window(size_t size, const std::string& title, opengl::context_settings settings = opengl::context_settings());

    /// @brief Destructor.
    ~window();

    window(const window&) = delete;
    window& operator=(const window&) = delete;

    /// @brief Move constructor.
    ///
    /// @param other Window to move from.
    window(window&& other) noexcept;

    /// @brief Move operator.
    ///
    /// @param other Window to move from.
    ///
    /// @return Reference to moved object.
    window& operator=(window&& other) noexcept;

    /// @name actions
    /// @{

    /// @brief Makes the window visible.
    void show();

    /// @brief Hides the window.
    void hide();

    /// @brief If window is visible, brings it to the front and may make it the focused.
    void focus();

    /// @brief Pull all system events and process it.
    void process_events();

    /// @brief Switch window to iconic state.
    void iconify();

    /// @brief Maximize window.
    void maximize();

    /// @brief Switch to fullscreen mode.
    void switch_to_fullscreen();

    /// @brief Restore normal window mode.
    void restore();
    /// @}

    /// @name setters
    /// @{

    /// @brief Resize window.
    ///
    /// @param size New window size.
    void set_size(size_t size);

    /// @brief Move window.
    ///
    /// @param position New winodw position.
    void set_position(position_t position);

    /// @brief Sets maximum window size.
    ///
    /// @param max_size Maximum window size.
    void set_max_size(size_t max_size);

    /// @brief Sets minimum window size.
    ///
    /// @param min_size Minimum window size.
    void set_min_size(size_t min_size);

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
    position_t position() const;

    /// @brief Window size.
    ///
    /// @return Current window size.
    size_t size() const;

    /// @brief Maximum window size.
    ///
    /// @return Current maximum size.
    size_t max_size() const;

    /// @brief Minimum window size.
    ///
    /// @return Current minimum size.
    size_t min_size() const;

    /// @brief Window title.
    ///
    /// @return Current window title.
    std::string title() const;

    /// @brief Returns graphic context associated with this window.
    ///
    /// @return Graphic context.
    framework::opengl::context* context() const;
    /// @}

    /// @name state
    /// @{

    /// @brief Checks if window is in fullscreen mode.
    ///
    /// @return `true` if window is in fullscreen mode.
    bool fullscreen() const;

    /// @brief Checks if window is in iconic state.
    ///
    /// @return `true` if window is in iconic state.
    bool iconified() const;

    /// @brief Checks if window is maximized.
    ///
    /// @return `true` if window is maximized.
    bool maximized() const;

    /// @brief Checks if window resizing is allowed.
    ///
    /// @return `true` if window resizing is allowed.
    bool resizable() const;

    /// @brief Checks if window is visible to the user.
    ///
    /// @return `true` if window is visible.
    bool visible() const;

    /// @brief Checks if window has input focus.
    ///
    /// @return `true` if window is focused.
    bool focused() const;
    /// @}

    /// @name events
    /// @{

    using event_callback           = std::function<void(const window&)>;
    using size_event_callback      = std::function<void(const window&, size_t)>;
    using position_event_callback  = std::function<void(const window&, position_t)>;
    using key_event_callback       = std::function<void(const window&, key_code, modifiers_state)>;
    using character_event_callback = std::function<void(const window&, std::string)>;
    using mouse_move_callback      = std::function<void(const window&, cursor_position)>;
    using mouse_button_callback    = std::function<void(const window&, mouse_button, cursor_position, modifiers_state)>;

    /// @brief Set on show callback. Called when window shows after creation.
    void set_on_show_callback(event_callback callback);

    /// @brief Set on hide callback. Called when window hides from screen.
    void set_on_hide_callback(event_callback callback);

    /// @brief Set on close callback. Called when the user clicks on the close window button.
    void set_on_close_callback(event_callback callback);

    /// @brief Set on focus callback. Called when the window gets input focus.
    void set_on_focus_callback(event_callback callback);

    /// @brief Set on focus lost callback. Called when the window loses input focus.
    void set_on_focus_lost_callback(event_callback callback);

    /// @biref Set on size callback. Called when window size changes.
    void set_on_size_callback(size_event_callback callback);

    /// @biref Set on position callback. Called when window position changes.
    void set_on_position_callback(position_event_callback callback);

    /// @biref Set on key press callback. Called when key is pressed. Can be called multiple times.
    void set_on_key_press_callback(key_event_callback callback);

    /// @biref Set on key release callback. Called when key is released.
    void set_on_key_release_callback(key_event_callback callback);

    /// @biref Set on character callback. Called when user press the char symbol key.
    void set_on_character_callback(character_event_callback callback);

    /// @biref Set on mouse move callback. Called when the mouse is moving.
    void set_on_mouse_move_callback(mouse_move_callback callback);

    /// @biref Set on mouse button press callback. Called when the mouse button is pressed.
    void set_on_mouse_button_press_callback(mouse_button_callback callback);

    /// @biref Set on mouse button release callback. Called when the mouse button is released.
    void set_on_mouse_button_release_callback(mouse_button_callback callback);

    /// @biref Set on mouse enter callback. Called when the cursor enters in the window frame.
    void set_on_mouse_enter_callback(event_callback callback);

    /// @biref Set on mouse leave callback. Called when the cursor leaves the window frame.
    void set_on_mouse_leave_callback(event_callback callback);
    /// @}

private:
    std::unique_ptr<details::implementation> m_implementation;
    std::unique_ptr<details::event_handler> m_event_handler;
};

/// @}

} // namespace framework::system

#endif
