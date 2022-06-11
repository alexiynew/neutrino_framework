#ifndef FRAMEWORK_SYSTEM_SRC_OSX_OSX_WINDOW_HPP
#define FRAMEWORK_SYSTEM_SRC_OSX_OSX_WINDOW_HPP

#include <functional>
#include <memory>

#include <system/src/platform_window.hpp>

namespace framework::system::details
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
    void show() override;
    void hide() override;
    void focus() override;
    void grab_cursor() override;
    void release_cursor() override;
    void process_events() override;
#pragma endregion

#pragma region setters
    void set_state(Window::State state) override;
    void set_size(Size size) override;
    void set_max_size(Size size) override;
    void set_min_size(Size size) override;
    void set_resizable(bool value) override;
    void set_position(Position position) override;
    void set_title(const std::string& title) override;
    void set_cursor_visibility(bool visible) override;
#pragma endregion

#pragma region getters
    bool is_visible() const override;
    bool should_close() const override;
    bool has_input_focus() const override;
    bool is_cursor_grabbed() const override;
    bool is_cursor_visible() const override;
    Window::State state() const override;
    Size size() const override;
    Size max_size() const override;
    Size min_size() const override;
    bool is_resizable() const override;
    Position position() const override;
    std::string title() const override;
    const Context& context() const override;
    Context& context() override;
#pragma endregion

private:
#pragma region NSWindowDelegate callbacks
    void window_should_close();
    void window_did_resize();
    void window_did_move();
    void window_did_miniaturize();
    void window_did_deminiaturize();
    void window_did_becomekey();
    void window_did_resignkey();
    void window_did_enter_full_screen();
    void window_did_exit_full_screen();
#pragma endregion

    bool switch_to_other_window();

    void update_context();

    std::unique_ptr<NSWindowWrapper> m_window;
    std::unique_ptr<NSViewWrapper> m_view;
    std::unique_ptr<OsxContext> m_context;

    bool m_should_close   = false;
    Window::State m_state = Window::State::normal;

    Size m_min_size;
    Size m_max_size;
};

} // namespace framework::system::details

#endif
