#ifndef SYSTEM_WINDOW_HPP
#define SYSTEM_WINDOW_HPP

#include <functional>
#include <memory>

#include <common/position.hpp>
#include <common/signal.hpp>
#include <common/size.hpp>
#include <system/context.hpp>
#include <system/context_settings.hpp>
#include <system/keyboard.hpp>
#include <system/mouse.hpp>

namespace framework::system
{

namespace details
{
class PlatformWindow;
class CallbacksHolder;
struct StateData;
} // namespace details

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @addtogroup system_window_class
/// @{
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @brief Window class.
///
/// Window, abstracts all window management, input processing, and event handling.
class Window final
{
public:
    /// @brief State of a window.
    enum class State
    {
        normal,     ///< Normal window state.
        iconified,  ///< Window displayed as icon in the taskbar. When the window is iconified it loses input focus.
        maximized,  ///< Window has maximum available size with borders and title bar.
        fullscreen, ///< Fullscreen mode.
    };

    /// @brief Creates a window.
    ///
    /// @param title Window name.
    /// @param size Window size.
    /// @param settings Gpaphic context settings.
    ///
    /// @thread_safety This function can be called only from main thread.
    Window(const std::string& title, Size size, ContextSettings settings = ContextSettings());

    ~Window();

    Window(const Window&) = delete;
    Window(Window&& other) noexcept;

    Window& operator=(const Window&) = delete;
    Window& operator=(Window&& other) noexcept;

#pragma region actions
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// @name actions
    /// @{
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    /// @brief Makes the window visible on the screen.
    ///
    /// Window appears on the screen in it's state @see set_state.
    /// If the window is already visible, this function does nothing.@n
    /// If the window has iconified state before show, it resets to normal state.@n
    /// If the window has been shown this function calls the
    ///     - @ref on_show
    ///     - @ref on_move
    ///     - @ref on_resize
    ///     - @ref on_focus
    ///     .
    /// callbacks in the specified order.
    ///
    /// @thread_safety This function can be called only from main thread.
    void show();

    /// @brief Removes the window from the screen.
    ///
    /// If the window has input focus then before hiding it the @ref on_lost_focus callback would be called.@n
    /// At the end of execution, it calls the @ref on_hide callback.
    ///
    /// @thread_safety This function can be called only from main thread.
    void hide();

    /// @brief Close the window
    ///
    /// Essentially sets the @ref should_close flag and call the on_close callback.
    ///
    /// @thread_safety This function can be called only from main thread.
    void close();

    /// @brief Bring the window to the front and switch input focus to it.
    ///
    /// If the window is not visible function has no effect.@n
    /// If the window gets input focus the @ref on_focus callback would be called.
    ///
    /// @thread_safety This function can be called only from main thread.
    void request_input_focus();

    /// @brief Captures the cursor, providing unlimited cursor movement.
    ///
    /// Blocks the cursor inside the window and the mouse movement tracks, as if it had no borders.
    /// If window is hidden or lost input focus the cursor restore its previous position.
    /// If window became visible or got input focus, and cursor was previously captured, the cursor would captured again.
    ///
    /// @thread_safety This function can be called only from main thread.
    void capture_cursor();

    /// @brief Releases the cursor, if it was gabbed.
    ///
    /// Moves cursor to its previous position. And restores mouse tracking to normal mode.
    ///
    /// @thread_safety This function can be called only from main thread.
    void release_cursor();

    /// @brief Pull all system events and process it.
    ///
    /// @thread_safety This function can be called only from main thread.
    void process_events();

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// @}
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#pragma endregion

#pragma region setters
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// @name setters
    /// @{
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    /// @brief Set new window state.
    ///
    /// Window state can be set before @ref show call.
    ///
    /// @thread_safety This function can be called only from main thread.
    void set_state(State state);

    /// @brief Set the size of the window content.
    ///
    /// @param size New window size.
    ///
    /// @thread_safety This function can be called only from main thread.
    void set_size(Size size);

    /// @brief Sets the maximum size of the window content.
    ///
    /// The maximum size constraint is enforced for resizing by the user as well as for the @ref resize function.
    /// The default maximum size is @ref Size(0, 0), which means there are no
    /// maximum size constrictions set. Setting size to @ref Size(0, 0) resets
    /// the maximum size of a window to its default system-dependent values.
    /// Setting size of the negative value has no effect.
    ///
    /// @param size Maximum window content size.
    ///
    /// @thread_safety This function can be called only from main thread.
    void set_max_size(Size size);

    /// @brief Sets the minimum size of the window content.
    ///
    /// The minimum size constraint is enforced for resizing by the user as
    /// well as for the @ref resize function.
    /// The default minimum size is @ref Size(0, 0), which means there are no
    /// minimum size constrictions set. Setting size to @ref Size(0, 0) resets
    /// the minimum size of a window to its default system-dependent values.
    /// Setting size of the negative value has no effect.
    ///
    /// @param size Minimum window content size.
    ///
    /// @thread_safety This function can be called only from main thread.
    void set_min_size(Size size);

    /// @brief Forbids/permits window resizing.
    ///
    /// When the value is false, window can't be resized by the user.
    /// The @ref size function can still change the window size.
    ///
    /// @param value Is window resizable.
    ///
    /// @thread_safety This function can be called only from main thread.
    void set_resizable(bool value);

    /// @brief Move window to new point.
    ///
    /// Tries to move the window so that the upper-left corner of the window content is located at a specified point.
    /// Actual window position may differ, because different desktop environments may add offsets to window position
    /// for menus, panels, etc. The fullscreen window is guaranteed to be at (0, 0) point.
    ///
    /// @param position New winodw position.
    ///
    /// @thread_safety This function can be called only from main thread.
    void set_position(Position position);

    /// @brief Sets window title.
    ///
    /// @param title New window title.
    ///
    /// @thread_safety This function can be called only from main thread.
    void set_title(const std::string& title);

    /// @brief Makes the cursor invisible when set to `false` if it is over the window.
    ///
    /// @param visible New cursor visibility.
    ///
    /// @thread_safety This function can be called only from main thread.
    void set_cursor_visible(bool visible);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// @}
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#pragma endregion

#pragma region getters
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// @name getters
    /// @{
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    /// @brief Checks if window is visible to the user.
    ///
    /// The window is visible to the user if the show function was called. Window in iconified state is still visible.
    ///
    /// @return `true` if window is visible.
    ///
    /// @thread_safety This function can be called from any thread.
    bool is_visible() const;

    /// @brief Checks if window is should be destoyed.
    ///
    /// @return `true` if on_close signal was emited.
    ///
    /// @thread_safety This function can be called from any thread.
    bool should_close() const;

    /// @brief Checks if window has input focus.
    ///
    /// @return `true` if window is focused.
    ///
    /// @thread_safety This function can be called from any thread.
    bool has_input_focus() const;

    /// @brief Checks if cursor captured.
    ///
    /// Regardless window visible state or if it has or not input focus.
    ///
    /// @return `true` if cursor is captured.
    ///
    /// @thread_safety This function can be called from any thread.
    bool is_cursor_captured() const;

    /// @brief Checks if cursor visible in the window.
    ///
    /// @return `true` if cursor is visible.
    ///
    /// @thread_safety This function can be called from any thread.
    bool is_cursor_visible() const;

    /// @brief Checks if cursor is inside the window worcking area.
    ///
    /// @return `true` if cursor is inside the window..
    ///
    /// @thread_safety This function can be called from any thread.
    bool is_cursor_hover() const;

    /// @brief Window state.
    ///
    /// @return Current window state.
    ///
    /// @thread_safety This function can be called from any thread.
    State state() const;

    /// @brief Window size.
    ///
    /// @return Current window size.
    ///
    /// @thread_safety This function can be called from any thread.
    Size size() const;

    /// @brief Maximum window size.
    ///
    /// @return Current maximum size.
    ///
    /// @thread_safety This function can be called from any thread.
    Size max_size() const;

    /// @brief Minimum window size.
    ///
    /// @return Current minimum size.
    ///
    /// @thread_safety This function can be called from any thread.
    Size min_size() const;

    /// @brief Checks if window resizing is allowed.
    ///
    /// @return `true` if window resizing is allowed.
    ///
    /// @thread_safety This function can be called from any thread.
    bool is_resizable() const;

    /// @brief Window position.
    ///
    /// @return Current window position.
    ///
    /// @thread_safety This function can be called from any thread.
    Position position() const;

    /// @brief Window title.
    ///
    /// @return Current window title.
    ///
    /// @thread_safety This function can be called from any thread.
    std::string title() const;

    /// @brief Window context.
    ///
    /// @return Window context.
    ///
    /// @thread_safety This function can be called from any thread.
    const Context& context() const;

    /// @brief Window context.
    ///
    /// @return Window context.
    ///
    /// @thread_safety This function can be called from any thread.
    Context& context();

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// @}
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#pragma endregion

#pragma region events
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// @name events
    /// @{
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    /// @brief Set on show callback. Called when window shows after creation.
    void set_on_show_callback(std::function<void()> callback);

    /// @brief Set on hide callback. Called when window hides from screen.
    void set_on_hide_callback(std::function<void()> callback);

    /// @brief Set on close callback. Called when the user clicks on the close window button.
    void set_on_close_callback(std::function<void()> callback);

    /// @brief Set on focus callback. Called when the window gets input focus.
    void set_on_focus_callback(std::function<void()> callback);

    /// @brief Set on focus lost callback. Called when the window loses input focus.
    void set_on_lost_focus_callback(std::function<void()> callback);

    /// @brief Set on size callback. Called when window size changes.
    void set_on_resize_callback(std::function<void(Size)> callback);

    /// @brief Set on position callback. Called when window position changes.
    void set_on_move_callback(std::function<void(Position)> callback);

    /// @brief Set on key down callback. Called when key is pressed. Can be called multiple times.
    void set_on_key_down_callback(std::function<void(KeyCode, Modifiers)> callback);

    /// @brief Set on key up callback. Called when key is released.
    void set_on_key_up_callback(std::function<void(KeyCode, Modifiers)> callback);

    /// @brief Set on character callback. Called when user press the char symbol key.
    void set_on_character_callback(std::function<void(const std::string&)> callback);

    /// @brief Set on mouse move callback. Called when the mouse is moving.
    void set_on_mouse_move_callback(std::function<void(CursorPosition)> callback);

    /// @brief Set on mouse button down callback. Called when the mouse button is pressed.
    void set_on_mouse_button_down_callback(std::function<void(MouseButton, CursorPosition, Modifiers)> callback);

    /// @brief Set on mouse button up callback. Called when the mouse button is released.
    void set_on_mouse_button_up_callback(std::function<void(MouseButton, CursorPosition, Modifiers)> callback);

    /// @brief Set on mouse scroll callback. Called when the user scrolls.
    void set_on_mouse_scroll_callback(std::function<void(ScrollOffset)> callback);

    /// @brief Set on mouse enter callback. Called when the cursor enters in the window frame.
    void set_on_mouse_enter_callback(std::function<void()> callback);

    /// @brief Set on mouse leave callback. Called when the cursor leaves the window frame.
    void set_on_mouse_leave_callback(std::function<void()> callback);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// @}
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#pragma endregion

private:
    friend class details::PlatformWindow;
    friend void swap(Window& lhs, Window& rhs) noexcept;

    void on_close();

    void on_resize(Size size);
    void on_move(Position position);

    void on_focus();
    void on_lost_focus();

    void on_mouse_enter();
    void on_mouse_leave();
    void on_mouse_move(CursorPosition position);

    void update_cursor_visibility();
    void update_cursor_position();

    void set_cursor_in_center();

    std::unique_ptr<details::PlatformWindow> m_platform_window;
    std::unique_ptr<details::CallbacksHolder> m_callbacks;
    std::unique_ptr<details::StateData> m_state_data;
};

/// @brief Swaps two Windows.
///
/// @param lhs Winodw to swap.
/// @param rhs Window  to swap.
void swap(Window& lhs, Window& rhs) noexcept;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

} // namespace framework::system

#endif
