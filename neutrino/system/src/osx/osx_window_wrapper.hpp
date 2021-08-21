/// @file
/// @brief Window implementation for OSX.
/// @author Fedorov Alexey
/// @date 20.12.2017

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

#ifndef FRAMEWORK_WINDOW_DETAILS_LINUX_X11_WINDOW_HPP
#define FRAMEWORK_WINDOW_DETAILS_LINUX_X11_WINDOW_HPP

#include <functional>
#include <memory>

#include <common/types.hpp>

#include <system/src/platform_window.hpp>

namespace framework::system
{
class Context;
}

namespace framework::system::details
{
class OSXWindowWrapper final : public PlatformWindow
{
public:
    OSXWindowWrapper(Size size, const std::string& title, const ContextSettings& settings);
    ~OSXWindowWrapper() override;

    OSXWindowWrapper(const OSXWindowWrapper&) = delete;
    OSXWindowWrapper& operator=(const OSXWindowWrapper&) = delete;

    /// @name actions
    /// @{
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
    /// @}

    /// @name setters
    /// @{
    void set_max_size(Size size) override;
    void set_min_size(Size size) override;
    void set_resizable(bool value) override;
    void set_title(const std::string& title) override;
    void set_cursor_visibility(bool visible) override;
    /// @}

    /// @name getters
    /// @{
    Position position() const override;
    Size size() const override;
    Size max_size() const override;
    Size min_size() const override;
    std::string title() const override;
    const Context& context() const override;
    /// @}

    /// @name state
    /// @{
    bool should_close() const override;
    bool is_fullscreen() const override;
    bool is_iconified() const override;
    bool is_maximized() const override;
    bool is_resizable() const override;
    bool is_visible() const override;
    bool has_input_focus() const override;
    bool is_cursor_visible() const override;
    bool is_cursor_grabbed() const override;
    /// @}

private:
    void setup_application();
    void ensureThreadHasPool();
    void drainThreadPool();

    void* m_window;

    std::unique_ptr<Context> m_context = nullptr;
};

} // namespace framework::system::details

#endif
