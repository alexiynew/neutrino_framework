#include <memory>

#include <system/window.hpp>

#include <system/src/platform_window.hpp>
#include <system/src/platform_window_factory.hpp>
#include <system/src/state_data.hpp>

namespace framework::system
{
Window::Window(const std::string& title, Size size, ContextSettings settings)
    : m_platform_window(details::create_platform_window(title, size, std::move(settings)))
    , m_callbacks(std::make_unique<details::CallbacksHolder>())
    , m_state_data(std::make_unique<details::StateData>())
{
    m_platform_window->set_window_interface(this);
}

Window::~Window()
{
    if (m_platform_window) {
        m_platform_window->set_window_interface(nullptr);
    }
}

Window::Window(Window&& other) noexcept
    : m_platform_window(nullptr)
{
    swap(*this, other);
}

Window& Window::operator=(Window&& other) noexcept
{
    swap(*this, other);
    return *this;
}

#pragma region actions

void Window::show()
{
    if (is_visible()) {
        return;
    }

    // Turn off on_resize, on_move and on_focus callbacks
    const auto on_resize_callback = m_callbacks->on_resize_callback;
    const auto on_move_callback   = m_callbacks->on_move_callback;
    const auto on_focus_callback  = m_callbacks->on_focus_callback;

    m_callbacks->on_resize_callback = nullptr;
    m_callbacks->on_move_callback   = nullptr;
    m_callbacks->on_focus_callback  = nullptr;

    // Show window
    m_platform_window->show(m_state_data->state);

    // Turn om on_resize, on_move and on_focus callbacks
    m_callbacks->on_resize_callback = on_resize_callback;
    m_callbacks->on_move_callback   = on_move_callback;
    m_callbacks->on_focus_callback  = on_focus_callback;

    // Explicitly call callbacks
    m_callbacks->on_show();
    m_callbacks->on_move(position());
    m_callbacks->on_resize(size());

    if (m_state_data->cursor_grabbed) {
        m_platform_window->enable_raw_input();
    }

    if (has_input_focus()) {
        m_callbacks->on_focus();
    } else {
        focus();
    }
}

void Window::hide()
{
    if (!is_visible()) {
        return;
    }

    if (has_input_focus()) {
        m_callbacks->on_lost_focus();
    }

    if (m_state_data->cursor_grabbed) {
        m_platform_window->disable_raw_input();
    }

    // Hide window
    m_platform_window->hide();

    // Explicitly call on_hide callback
    m_callbacks->on_hide();
}

void Window::close()
{
    m_state_data->should_close = true;
    m_callbacks->on_close();
}

void Window::focus()
{
    if (!is_visible() || has_input_focus()) {
        return;
    }

    m_platform_window->focus();
}

void Window::grab_cursor()
{
    if (m_state_data->cursor_grabbed) {
        return;
    }

    m_state_data->cursor_grabbed = true;

    m_platform_window->enable_raw_input();
}

void Window::release_cursor()
{
    if (!m_state_data->cursor_grabbed) {
        return;
    }

    m_state_data->cursor_grabbed = false;

    m_platform_window->disable_raw_input();
}

void Window::process_events()
{
    m_platform_window->process_events();
}

#pragma endregion

#pragma region setters

void Window::set_state(State state)
{
    if (!is_visible()) {
        m_state_data->state = state;
        return;
    }

    const Window::State old_state = m_platform_window->state();
    if (state == old_state) {
        return;
    }

    // Turn off the on_resize and on_move callbacks
    const auto on_resize_callback   = m_callbacks->on_resize_callback;
    const auto on_move_callback     = m_callbacks->on_move_callback;
    m_callbacks->on_resize_callback = nullptr;
    m_callbacks->on_move_callback   = nullptr;

    // Switch to new state
    m_platform_window->switch_state(old_state, state);

    // Turn om on_resize, on_move and on_focus callbacks
    m_callbacks->on_resize_callback = on_resize_callback;
    m_callbacks->on_move_callback   = on_move_callback;

    // Update state value
    m_state_data->state = m_platform_window->state();

    // Explicitly call callbacks
    if (m_state_data->state != Window::State::iconified) {
        m_callbacks->on_move(position());
        m_callbacks->on_resize(size());
    }
}

void Window::set_size(Size size)
{
    m_platform_window->set_size(size);
}

void Window::set_max_size(Size max_size)
{
    m_platform_window->set_max_size(max_size);
}

void Window::set_min_size(Size min_size)
{
    m_platform_window->set_min_size(min_size);
}

void Window::set_resizable(bool value)
{
    m_platform_window->set_resizable(value);
}

void Window::set_position(Position position)
{
    m_platform_window->set_position(position);
}

void Window::set_title(const std::string& title)
{
    m_platform_window->set_title(title);
}

void Window::set_cursor_visibility(bool visible)
{
    m_platform_window->set_cursor_visibility(visible);
}

#pragma endregion

#pragma region getters

bool Window::is_visible() const
{
    return m_platform_window->is_visible();
}

bool Window::should_close() const
{
    return m_state_data->should_close;
}

bool Window::has_input_focus() const
{
    return m_platform_window->has_input_focus();
}

bool Window::is_cursor_grabbed() const
{
    return m_state_data->cursor_grabbed;
}

bool Window::is_cursor_visible() const
{
    return m_platform_window->is_cursor_visible();
}

Window::State Window::state() const
{
    return m_state_data->state;
}

Size Window::size() const
{
    return m_platform_window->size();
}

Size Window::max_size() const
{
    return m_platform_window->max_size();
}

Size Window::min_size() const
{
    return m_platform_window->min_size();
}

bool Window::is_resizable() const
{
    return m_platform_window->is_resizable();
}

Position Window::position() const
{
    return m_platform_window->position();
}

std::string Window::title() const
{
    return m_platform_window->title();
}

const Context& Window::context() const
{
    return m_platform_window->context();
}

Context& Window::context()
{
    return m_platform_window->context();
}

#pragma endregion

#pragma region events

void Window::set_on_show_callback(std::function<void()> callback)
{
    m_callbacks->on_show_callback = callback;
}

void Window::set_on_hide_callback(std::function<void()> callback)
{
    m_callbacks->on_hide_callback = callback;
}

void Window::set_on_close_callback(std::function<void()> callback)
{
    m_callbacks->on_close_callback = callback;
}

void Window::set_on_focus_callback(std::function<void()> callback)
{
    m_callbacks->on_focus_callback = callback;
}

void Window::set_on_lost_focus_callback(std::function<void()> callback)
{
    m_callbacks->on_lost_focus_callback = callback;
}

void Window::set_on_resize_callback(std::function<void(Size)> callback)
{
    m_callbacks->on_resize_callback = callback;
}

void Window::set_on_move_callback(std::function<void(Position)> callback)
{
    m_callbacks->on_move_callback = callback;
}

void Window::set_on_key_down_callback(std::function<void(KeyCode, Modifiers)> callback)
{
    m_callbacks->on_key_down_callback = callback;
}

void Window::set_on_key_up_callback(std::function<void(KeyCode, Modifiers)> callback)
{
    m_callbacks->on_key_up_callback = callback;
}

void Window::set_on_character_callback(std::function<void(const std::string&)> callback)
{
    m_callbacks->on_character_callback = callback;
}

void Window::set_on_mouse_move_callback(std::function<void(CursorPosition)> callback)
{
    m_callbacks->on_mouse_move_callback = callback;
}

void Window::set_on_mouse_button_down_callback(std::function<void(MouseButton, CursorPosition, Modifiers)> callback)
{
    m_callbacks->on_mouse_button_down_callback = callback;
}

void Window::set_on_mouse_button_up_callback(std::function<void(MouseButton, CursorPosition, Modifiers)> callback)
{
    m_callbacks->on_mouse_button_up_callback = callback;
}

void Window::set_on_mouse_scroll_callback(std::function<void(ScrollOffset)> callback)
{
    m_callbacks->on_mouse_scroll_callback = callback;
}

void Window::set_on_mouse_enter_callback(std::function<void()> callback)
{
    m_callbacks->on_mouse_enter_callback = callback;
}

void Window::set_on_mouse_leave_callback(std::function<void()> callback)
{
    m_callbacks->on_mouse_leave_callback = callback;
}

#pragma endregion

#pragma region implemnetation callbacks

void Window::on_close()
{
    close();
}

void Window::on_focus()
{
    if (!is_visible()) {
        return;
    }

    if (m_state_data->cursor_grabbed) {
        m_platform_window->enable_raw_input();
    }

    m_callbacks->on_focus();
}

void Window::on_lost_focus()
{
    if (!is_visible()) {
        return;
    }

    if (m_state_data->cursor_grabbed) {
        m_platform_window->disable_raw_input();
    }

    m_callbacks->on_lost_focus();
}

#pragma endregion

void swap(Window& lhs, Window& rhs) noexcept
{
    using std::swap;
    swap(lhs.m_platform_window, rhs.m_platform_window);
    swap(lhs.m_callbacks, rhs.m_callbacks);
    swap(lhs.m_state_data, rhs.m_state_data);

    if (lhs.m_platform_window) {
        lhs.m_platform_window->set_window_interface(&lhs);
    }
    if (rhs.m_platform_window) {
        rhs.m_platform_window->set_window_interface(&rhs);
    }
}

} // namespace framework::system
