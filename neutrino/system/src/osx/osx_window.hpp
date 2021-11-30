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

    OsxWindow& operator=(const OsxWindow&) = delete;
    OsxWindow& operator=(OsxWindow&&) noexcept = default;

#pragma region actions
    void show() override;
    void hide() override;
    void focus() override;
    void iconify() override;
    void maximize() override;
    void fullscreen() override;
    void restore() override;
    void resize(Size size) override;
    void move(Position position) override;
    void grab_cursor() override;
    void release_cursor() override;
    void process_events() override;
#pragma endregion

#pragma region setters
    void set_max_size(Size size) override;
    void set_min_size(Size size) override;
    void set_resizable(bool value) override;
    void set_title(const std::string& title) override;
    void set_cursor_visibility(bool visible) override;
#pragma endregion

#pragma region getters
    Position position() const override;
    Size size() const override;
    Size max_size() const override;
    Size min_size() const override;
    std::string title() const override;
    const Context& context() const override;
    Context& context() override;
#pragma endregion

#pragma region state
    bool should_close() const override;
    bool is_fullscreen() const override;
    bool is_iconified() const override;
    bool is_maximized() const override;
    bool is_resizable() const override;
    bool is_visible() const override;
    bool has_input_focus() const override;
    bool is_cursor_visible() const override;
    bool is_cursor_grabbed() const override;
#pragma endregion

private:
    void window_should_close();
    void window_did_resize();
    void window_did_move();
    void window_did_miniaturize();
    void window_did_deminiaturize();
    void window_did_becomekey();
    void window_did_resignkey();

    void update_context();

    std::unique_ptr<NSWindowWrapper> m_window;
    std::unique_ptr<NSViewWrapper> m_view;
    std::unique_ptr<OsxContext> m_context;

    bool m_should_close = false;

    Size m_min_size;
    Size m_max_size;
};

} // namespace framework::system::details

#endif
