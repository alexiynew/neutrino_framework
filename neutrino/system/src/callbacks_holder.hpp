#ifndef SYSTEM_SRC_CALLBACKS_HOLDER_HPP
#define SYSTEM_SRC_CALLBACKS_HOLDER_HPP

#include <functional>
#include <string>

#include <common/position.hpp>
#include <common/size.hpp>
#include <system/keyboard.hpp>
#include <system/mouse.hpp>
#include <system/window.hpp>

namespace framework::system::details
{
class CallbacksHolder
{
public:
    void on_show() const;
    void on_hide() const;
    void on_resize(Size new_size) const;
    void on_move(Position new_position) const;
    void on_key_down(KeyCode key, Modifiers modifiers) const;
    void on_key_up(KeyCode key, Modifiers modifiers) const;
    void on_character(const std::string& str) const;
    void on_mouse_button_down(MouseButton button, CursorPosition position, Modifiers modifiers) const;
    void on_mouse_button_up(MouseButton button, CursorPosition position, Modifiers modifiers) const;
    void on_mouse_scroll(ScrollOffset offset) const;

private:
    friend class framework::system::Window;

    void on_close() const;
    void on_focus() const;
    void on_lost_focus() const;

    void on_mouse_enter() const;
    void on_mouse_leave() const;
    void on_mouse_move(CursorPosition position) const;

    std::function<void()> on_show_callback;
    std::function<void()> on_hide_callback;
    std::function<void()> on_close_callback;
    std::function<void()> on_focus_callback;
    std::function<void()> on_lost_focus_callback;
    std::function<void(Size new_size)> on_resize_callback;
    std::function<void(Position new_position)> on_move_callback;
    std::function<void(KeyCode key, Modifiers modifiers)> on_key_down_callback;
    std::function<void(KeyCode key, Modifiers modifiers)> on_key_up_callback;
    std::function<void(const std::string& str)> on_character_callback;
    std::function<void(CursorPosition position)> on_mouse_move_callback;
    std::function<void(MouseButton button, CursorPosition position, Modifiers modifiers)> on_mouse_button_down_callback;
    std::function<void(MouseButton button, CursorPosition position, Modifiers modifiers)> on_mouse_button_up_callback;
    std::function<void(ScrollOffset offset)> on_mouse_scroll_callback;
    std::function<void()> on_mouse_enter_callback;
    std::function<void()> on_mouse_leave_callback;
};

} // namespace framework::system::details

#endif
