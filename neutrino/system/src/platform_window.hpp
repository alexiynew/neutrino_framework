#ifndef FRAMEWORK_SYSTEM_SRC_PLATFORM_WINDOW_HPP
#define FRAMEWORK_SYSTEM_SRC_PLATFORM_WINDOW_HPP

#include <memory>
#include <string>

#include <common/position.hpp>
#include <common/size.hpp>
#include <system/context.hpp>
#include <system/context_settings.hpp>
#include <system/window.hpp>

namespace framework::system::details
{
class PlatformWindow
{
public:
    static void set_application_name(const std::string& name);

    PlatformWindow();

    virtual ~PlatformWindow();

    PlatformWindow(const PlatformWindow&) = delete;
    PlatformWindow& operator=(const PlatformWindow&) = delete;

    PlatformWindow(PlatformWindow&&) noexcept = default;
    PlatformWindow& operator=(PlatformWindow&&) noexcept = default;

#pragma region actions
    virtual void show()                  = 0;
    virtual void hide()                  = 0;
    virtual void focus()                 = 0;
    virtual void iconify()               = 0;
    virtual void maximize()              = 0;
    virtual void fullscreen()            = 0;
    virtual void restore()               = 0;
    virtual void resize(Size size)       = 0;
    virtual void move(Position position) = 0;
    virtual void grab_cursor()           = 0;
    virtual void release_cursor()        = 0;
    virtual void process_events()        = 0;
#pragma endregion

#pragma region setters
    virtual void set_max_size(Size size)             = 0;
    virtual void set_min_size(Size size)             = 0;
    virtual void set_resizable(bool value)           = 0;
    virtual void set_title(const std::string& title) = 0;
    virtual void set_cursor_visibility(bool visible) = 0;
#pragma endregion

#pragma region getters
    virtual Position position() const      = 0;
    virtual Size size() const              = 0;
    virtual Size max_size() const          = 0;
    virtual Size min_size() const          = 0;
    virtual std::string title() const      = 0;
    virtual const Context& context() const = 0;
    virtual Context& context()             = 0;
#pragma endregion

#pragma region state
    virtual bool should_close() const      = 0;
    virtual bool is_fullscreen() const     = 0;
    virtual bool is_iconified() const      = 0;
    virtual bool is_maximized() const      = 0;
    virtual bool is_resizable() const      = 0;
    virtual bool is_visible() const        = 0;
    virtual bool has_input_focus() const   = 0;
    virtual bool is_cursor_visible() const = 0;
    virtual bool is_cursor_grabbed() const = 0;
#pragma endregion

    void set_window_instance(const Window* window);

protected:
    void on_show() const;
    void on_hide() const;
    void on_close() const;
    void on_focus() const;
    void on_lost_focus() const;
    void on_resize(Size new_size) const;
    void on_move(Position new_position) const;
    void on_key_down(KeyCode key, Modifiers modifiers) const;
    void on_key_up(KeyCode key, Modifiers modifiers) const;
    void on_character(const std::string& str) const;
    void on_mouse_move(CursorPosition position) const;
    void on_button_down(MouseButton button, CursorPosition position, Modifiers modifiers) const;
    void on_button_up(MouseButton button, CursorPosition position, Modifiers modifiers) const;
    void on_mouse_enter() const;
    void on_mouse_leave() const;

private:
    static std::string application_name;
    const Window* m_window_interface = nullptr;
};

std::unique_ptr<PlatformWindow> create_platform_window(const std::string& title,
                                                       Size size,
                                                       const ContextSettings& settings);

} // namespace framework::system::details

#endif
