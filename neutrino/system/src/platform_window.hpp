#ifndef SYSTEM_SRC_PLATFORM_WINDOW_HPP
#define SYSTEM_SRC_PLATFORM_WINDOW_HPP

#include <memory>
#include <string>

#include <common/position.hpp>
#include <common/size.hpp>
#include <system/context.hpp>
#include <system/context_settings.hpp>
#include <system/window.hpp>

#include <system/src/callbacks_holder.hpp>
#include <system/src/state_data.hpp>

namespace framework::system::details
{

class PlatformWindow
{
public:
    PlatformWindow();

    virtual ~PlatformWindow();

    PlatformWindow(const PlatformWindow&)     = delete;
    PlatformWindow(PlatformWindow&&) noexcept = default;

    PlatformWindow& operator=(const PlatformWindow&)     = delete;
    PlatformWindow& operator=(PlatformWindow&&) noexcept = default;

#pragma region actions
    virtual void show(Window::State state) = 0;
    virtual void hide()                    = 0;

    virtual void request_input_focus() = 0;

    virtual void capture_cursor() = 0;
    virtual void release_cursor() = 0;

    virtual void show_cursor() = 0;
    virtual void hide_cursor() = 0;

    virtual void switch_state(Window::State old_state, Window::State new_state) = 0;

    virtual void process_events() = 0;
#pragma endregion

#pragma region setters
    virtual void set_size(Size size)                          = 0;
    virtual void set_max_size(Size size)                      = 0;
    virtual void set_min_size(Size size)                      = 0;
    virtual void set_resizable(bool value)                    = 0;
    virtual void set_position(Position position)              = 0;
    virtual void set_title(const std::string& title)          = 0;
    virtual void set_cursor_position(CursorPosition position) = 0;
#pragma endregion

#pragma region getters
    virtual bool is_visible() const                = 0;
    virtual bool has_input_focus() const           = 0;
    virtual Window::State state() const            = 0;
    virtual Size size() const                      = 0;
    virtual Size max_size() const                  = 0;
    virtual Size min_size() const                  = 0;
    virtual bool is_resizable() const              = 0;
    virtual Position position() const              = 0;
    virtual std::string title() const              = 0;
    virtual CursorPosition cursor_position() const = 0;
    virtual const Context& context() const         = 0;
    virtual Context& context()                     = 0;
#pragma endregion

    void set_window_interface(Window* window);

protected:
    const CallbacksHolder& callbacks() const;
    const StateData& state_data() const;

    void on_close();

    void on_resize(Size size);
    void on_move(Position position);

    void on_focus();
    void on_lost_focus();

    void on_mouse_enter();
    void on_mouse_leave();
    void on_mouse_move(CursorPosition position);

private:
    Window* m_window_interface = nullptr;
};

} // namespace framework::system::details

#endif
