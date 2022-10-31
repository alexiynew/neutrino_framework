#ifndef SYSTEM_SRC_OSX_OSX_WINDOW_HPP
#define SYSTEM_SRC_OSX_OSX_WINDOW_HPP

#include <functional>
#include <memory>

#include <system/src/platform_window.hpp>

namespace neutrino::system::details
{

class NSWindowWrapper;
class NSViewWrapper;
class OsxContext;

class OsxWindow final : public PlatformWindow
{
public:
    OsxWindow(const std::string& title, Size size, const ContextSettings& settings);

    OsxWindow(const OsxWindow&)     = delete;
    OsxWindow(OsxWindow&&) noexcept = default;

    ~OsxWindow() override;

    OsxWindow& operator=(const OsxWindow&)     = delete;
    OsxWindow& operator=(OsxWindow&&) noexcept = default;

#pragma region actions
    void show(Window::State state) override;
    void hide() override;

    void request_input_focus() override;

    void capture_cursor() override;
    void release_cursor() override;

    void show_cursor() override;
    void hide_cursor() override;

    void switch_state(Window::State old_state, Window::State new_state) override;

    void process_events() override;
#pragma endregion

#pragma region setters
    void set_size(Size size) override;
    void set_max_size(Size size) override;
    void set_min_size(Size size) override;
    void set_resizable(bool value) override;
    void set_position(Position position) override;
    void set_title(const std::string& title) override;
    void set_cursor_position(CursorPosition position) override;
#pragma endregion

#pragma region getters
    bool is_visible() const override;
    bool has_input_focus() const override;
    Window::State state() const override;
    Size size() const override;
    Size max_size() const override;
    Size min_size() const override;
    bool is_resizable() const override;
    Position position() const override;
    std::string title() const override;
    CursorPosition cursor_position() const override;
    const Context& context() const override;
    Context& context() override;
#pragma endregion

#pragma region NSWindowDelegate callbacks
    void window_should_close();
    void window_did_resize();
    void window_did_move();
    void window_did_miniaturize();
    void window_did_deminiaturize();
    void window_did_become_key();
    void window_did_resign_key();
    void window_did_enter_full_screen();
    void window_did_exit_full_screen();

    void key_down(KeyCode key, Modifiers state);
    void key_up(KeyCode key, Modifiers state);
    void character(const std::string&);

    void mouse_entered();
    void mouse_exited();
    void mouse_moved(CursorPosition position);
    void mouse_button_down(MouseButton button, CursorPosition position, Modifiers state);
    void mouse_button_up(MouseButton button, CursorPosition position, Modifiers state);
    void mouse_scroll(ScrollOffset scroll);

    void update_context();
#pragma endregion

private:
    Window::State get_actual_state() const;
    CursorPosition convert_cursor_position(CursorPosition position);

    std::unique_ptr<NSWindowWrapper> m_window;
    std::unique_ptr<NSViewWrapper> m_view;
    std::unique_ptr<OsxContext> m_context;

    bool m_cursor_actually_visible = true;

    Size m_min_size;
    Size m_max_size;

    Window::State m_actual_state;
};

} // namespace neutrino::system::details

#endif
