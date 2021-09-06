// =============================================================================
// MIT License
//
// Copyright (c) 2017-2021 Fedorov Alexey
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

#include <system/src/platform_window.hpp>

namespace framework::system::details
{
std::string PlatformWindow::application_name = "Application";

PlatformWindow::PlatformWindow()
{}

PlatformWindow::~PlatformWindow() = default;

void PlatformWindow::set_application_name(const std::string& name)
{
    application_name = name;
}

void PlatformWindow::set_window_instance(const Window* window)
{
    m_window_interface = window;
}

void PlatformWindow::on_show() const
{
    if (m_window_interface) {
        m_window_interface->on_show(*m_window_interface);
    }
}

void PlatformWindow::on_hide() const
{
    if (m_window_interface) {
        m_window_interface->on_hide(*m_window_interface);
    }
}

void PlatformWindow::on_close() const
{
    if (m_window_interface) {
        m_window_interface->on_close(*m_window_interface);
    }
}

void PlatformWindow::on_focus() const
{
    if (m_window_interface) {
        m_window_interface->on_focus(*m_window_interface);
    }
}

void PlatformWindow::on_lost_focus() const
{
    if (m_window_interface) {
        m_window_interface->on_lost_focus(*m_window_interface);
    }
}

void PlatformWindow::on_resize(Size new_size) const
{
    if (m_window_interface) {
        m_window_interface->on_resize(*m_window_interface, new_size);
    }
}

void PlatformWindow::on_move(Position new_position) const
{
    if (m_window_interface) {
        m_window_interface->on_move(*m_window_interface, new_position);
    }
}

void PlatformWindow::on_key_down(KeyCode key, Modifiers modifiers) const
{
    if (m_window_interface) {
        m_window_interface->on_key_down(*m_window_interface, key, modifiers);
    }
}

void PlatformWindow::on_key_up(KeyCode key, Modifiers modifiers) const
{
    if (m_window_interface) {
        m_window_interface->on_key_up(*m_window_interface, key, modifiers);
    }
}

void PlatformWindow::on_character(const std::string& str) const
{
    if (m_window_interface) {
        m_window_interface->on_character(*m_window_interface, str);
    }
}

void PlatformWindow::on_mouse_move(CursorPosition position) const
{
    if (m_window_interface) {
        m_window_interface->on_mouse_move(*m_window_interface, position);
    }
}

void PlatformWindow::on_button_down(MouseButton button, CursorPosition position, Modifiers modifiers) const
{
    if (m_window_interface) {
        m_window_interface->on_button_down(*m_window_interface, button, position, modifiers);
    }
}

void PlatformWindow::on_button_up(MouseButton button, CursorPosition position, Modifiers modifiers) const
{
    if (m_window_interface) {
        m_window_interface->on_button_up(*m_window_interface, button, position, modifiers);
    }
}

void PlatformWindow::on_mouse_enter() const
{
    if (m_window_interface) {
        m_window_interface->on_mouse_enter(*m_window_interface);
    }
}

void PlatformWindow::on_mouse_leave() const
{
    if (m_window_interface) {
        m_window_interface->on_mouse_leave(*m_window_interface);
    }
}

} // namespace framework::system::details
