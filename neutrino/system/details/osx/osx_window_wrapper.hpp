/// @file
/// @brief Window implementation for OSX.
/// @author Fedorov Alexey
/// @date 20.12.2017

// =============================================================================
// MIT License
//
// Copyright (c) 2017-2019 Fedorov Alexey
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

#include <common/types.hpp>

#include <system/details/context.hpp>
#include <system/details/window_implementation.hpp>

namespace framework::system::details
{
class osx_window_wrapper final : public window_implementation
{
public:
    osx_window_wrapper(window_size size, const std::string& title, const context_settings& settings);
    ~osx_window_wrapper() override;

    osx_window_wrapper(const osx_window_wrapper&) = delete;
    osx_window_wrapper& operator=(const osx_window_wrapper&) = delete;

    /// @name actions
    /// @{
    void show() override;
    void hide() override;
    void focus() override;
    void process_events() override;

    // On window managers without the ewmh support, proper work is not tested, nor granted.
    void iconify() override;
    void maximize() override;
    void switch_to_fullscreen() override;
    void restore() override;
    void make_current() override;
    void swap_buffers() override;
    /// @}

    /// @name setters
    /// @{

    // The size() value will be updated after next event processing
    void set_size(window_size size) override;
    void set_position(window_position position) override;

    void set_max_size(window_size max_size) override;
    void set_min_size(window_size min_size) override;

    void set_resizable(bool value) override;

    void set_title(const std::string& title) override;
    /// @}

    /// @name getters
    /// @{
    window_position position() const override;
    window_size size() const override;

    window_size max_size() const override;
    window_size min_size() const override;

    std::string title() const override;
    /// @}

    /// @name state
    /// @{
    bool fullscreen() const override;
    bool iconified() const override;
    bool maximized() const override;
    bool resizable() const override;
    bool visible() const override;
    bool focused() const override;
    /// @}

private:
    void* self;
};

} // namespace framework::system::details

#endif
