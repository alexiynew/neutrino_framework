#include <system/src/callbacks_holder.hpp>

namespace neutrino::system::details
{
void CallbacksHolder::on_show() const
{
    if (on_show_callback) {
        on_show_callback();
    }
}

void CallbacksHolder::on_hide() const
{
    if (on_hide_callback) {
        on_hide_callback();
    }
}

void CallbacksHolder::on_close() const
{
    if (on_close_callback) {
        on_close_callback();
    }
}

void CallbacksHolder::on_focus() const
{
    if (on_focus_callback) {
        on_focus_callback();
    }
}

void CallbacksHolder::on_lost_focus() const
{
    if (on_lost_focus_callback) {
        on_lost_focus_callback();
    }
}

void CallbacksHolder::on_resize(Size size) const
{
    if (on_resize_callback) {
        on_resize_callback(size);
    }
}

void CallbacksHolder::on_move(Position position) const
{
    if (on_move_callback) {
        on_move_callback(position);
    }
}

void CallbacksHolder::on_key_down(KeyCode key, Modifiers modifiers) const
{
    if (on_key_down_callback) {
        on_key_down_callback(key, modifiers);
    }
}

void CallbacksHolder::on_key_up(KeyCode key, Modifiers modifiers) const
{
    if (on_key_up_callback) {
        on_key_up_callback(key, modifiers);
    }
}

void CallbacksHolder::on_character(const std::string& str) const
{
    if (on_character_callback) {
        on_character_callback(str);
    }
}

void CallbacksHolder::on_mouse_move(CursorPosition position) const
{
    if (on_mouse_move_callback) {
        on_mouse_move_callback(position);
    }
}

void CallbacksHolder::on_mouse_button_down(MouseButton button, CursorPosition position, Modifiers modifiers) const
{
    if (on_mouse_button_down_callback) {
        on_mouse_button_down_callback(button, position, modifiers);
    }
}

void CallbacksHolder::on_mouse_button_up(MouseButton button, CursorPosition position, Modifiers modifiers) const
{
    if (on_mouse_button_up_callback) {
        on_mouse_button_up_callback(button, position, modifiers);
    }
}

void CallbacksHolder::on_mouse_scroll(ScrollOffset offset) const
{
    if (on_mouse_scroll_callback) {
        on_mouse_scroll_callback(offset);
    }
}

void CallbacksHolder::on_mouse_enter() const
{
    if (on_mouse_enter_callback) {
        on_mouse_enter_callback();
    }
}

void CallbacksHolder::on_mouse_leave() const
{
    if (on_mouse_leave_callback) {
        on_mouse_leave_callback();
    }
}

} // namespace neutrino::system::details
