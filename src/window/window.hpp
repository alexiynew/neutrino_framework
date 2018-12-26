/// @file
/// @brief Window interface class.
/// @author Fedorov Alexey
/// @date 04.04.2017

// =============================================================================
// MIT License
//
// Copyright (c) 2017-2018 Fedorov Alexey
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

#ifndef FRAMEWORK_WINDOW_WINDOW_HPP
#define FRAMEWORK_WINDOW_WINDOW_HPP

#include <functional>
#include <memory>
#include <optional>

#include <common/types.hpp>
#include <opengl/context.hpp>
#include <window/keyboard.hpp>

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
/// @addtogroup window_class
/// @{

/// @brief A Window class.
///
/// OpenGL-based window, abstracts all window management, input processing, and event handling.
class window final
{
public:
    /// @brief Base class for OS specific realisation.
    class implementation;

    /// @brief Window size.
    struct size_t
    {
        int32 width;  ///< Window width.
        int32 height; ///< Window height.
    };

    /// @brief Window position.
    struct position_t
    {
        int32 x; ///< X coordiante.
        int32 y; ///< Y coordinate.
    };

    template <typename... Args>
    using event_handler = std::function<void(Args...)>;

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

    /// @brief On show callback. Called when window shows after creation.
    event_handler<const window&> on_show = nullptr;

    /// @brief On hide callback. Called when window hides from screen.
    event_handler<const window&> on_hide = nullptr;

    /// @brief On close callback. Called when the user clicks on the close window button.
    event_handler<const window&> on_close = nullptr;

    /// @brief On focus callback. Called when the window gets input focus.
    event_handler<const window&> on_focus = nullptr;

    /// @brief On focus lost callback. Called when the window loses input focus.
    event_handler<const window&> on_focus_lost = nullptr;

    /// @biref On size callback. Called when window size changes.
    event_handler<const window&, window::size_t> on_size = nullptr;

    /// @biref On position callback. Called when window position changes.
    event_handler<const window&, window::position_t> on_position = nullptr;

    event_handler<const window&, key_code, modifiers_state> on_key_press   = nullptr;
    event_handler<const window&, key_code, modifiers_state> on_key_release = nullptr;

    event_handler<const window&, std::string> on_character = nullptr;

    event_handler<const window&, mouse_button, modifiers_state> on_mouse_press   = nullptr;
    event_handler<const window&, mouse_button, modifiers_state> on_mouse_release = nullptr;

    event_handler<const window&> on_mouse_enter = nullptr;
    event_handler<const window&> on_mouse_leave = nullptr;

    event_handler<const window&, cursor_position> mouse_move = nullptr;

private:
    std::unique_ptr<implementation> m_implementation;
};

/// @brief Equality operator for window size.
///
/// @param lhs Size to compare.
/// @param rhs Size to compare.
///
/// @return `true` if lhs equals rhs, otherwise `false`.
bool operator==(const window::size_t& lhs, const window::size_t& rhs);

/// @brief Inequality operator for window size.
///
/// @param lhs Size to compare.
/// @param rhs Size to compare.
///
/// @return `true` if lhs isn't equals rhs, otherwise `false`.
bool operator!=(const window::size_t& lhs, const window::size_t& rhs);

/// @brief Equality operator for window position.
///
/// @param lhs Position to compare.
/// @param rhs Position to compare.
///
/// @return `true` if lhs equals rhs, otherwise `false`.
bool operator==(const window::position_t& lhs, const window::position_t& rhs);

/// @brief Inequality operator for window position.
///
/// @param lhs Position to compare.
/// @param rhs Position to compare.
///
/// @return `true` if lhs isn't equals rhs, otherwise `false`.
bool operator!=(const window::position_t& lhs, const window::position_t& rhs);

/// @brief Helper function to print window size.
///
/// @param ostream Output stream.
/// @param size Window size.
///
/// @return Reference to output stream.
template <typename T>
T& operator<<(T& ostream, const window::size_t& size)
{
    ostream << "{" << size.width << ", " << size.height << "}";
    return ostream;
}

/// @brief Helper function to print window position.
///
/// @param ostream Output stream.
/// @param position Window position.
///
/// @return Reference to output stream.
template <typename T>
T& operator<<(T& ostream, const window::position_t& position)
{
    ostream << "{" << position.x << ", " << position.y << "}";
    return ostream;
}

/// @}

} // namespace framework::system

#endif
