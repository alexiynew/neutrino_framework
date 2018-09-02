/// @file
/// @brief Window implementation for osx.
/// @author Fedorov Alexey
/// @date 19.04.2017

// =============================================================================
// MIT License
//
// Copyright (c) 2017-2018 Fedorov Alexey
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

#ifndef FRAMEWORK_GRAPHIC_WINDOW_OSX_COCOA_WINDOW_HPP
#define FRAMEWORK_GRAPHIC_WINDOW_OSX_COCOA_WINDOW_HPP

#import "Cocoa/Cocoa.h"

#include <graphic/window_implementation.hpp>

namespace framework
{
namespace graphic
{
class cocoa_window final : public window::implementation
{
public:
    cocoa_window();
    ~cocoa_window() override;

    /// @name actions
    /// @{
    void show() override;
    void hide() override;
    void focus() override;
    void process_events() override;

    void minimize() override;
    void maximize() override;
    void switch_to_fullscreen() override;
    void restore() override;
    /// @}

    /// @name setters
    /// @{
    void set_size(window::size_t size) override;
    void set_position(window::position_t position) override;

    void set_max_size(window::size_t max_size) override;
    void set_min_size(window::size_t min_size) override;

    void set_resizable(bool value) override;

    void set_title(const std::string& title) override;
    /// @}

    /// @name getters
    /// @{
    window::position_t position() const override;
    window::size_t size() const override;

    window::size_t max_size() const override;
    window::size_t min_size() const override;

    std::string title() const override;
    /// @}

    /// @name state
    /// @{
    bool fullscreen() const override;
    bool minimized() const override;
    bool maximized() const override;
    bool resizable() const override;
    bool visible() const override;
    bool focused() const override;
    /// @}

private:
    NSAutoreleasePool* pool;
    NSWindow* window;
};

} // namespace graphic

} // namespace framework

#endif
