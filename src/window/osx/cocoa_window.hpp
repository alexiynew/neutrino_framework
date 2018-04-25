/// @file
/// @brief Window implementation for osx.
/// @author Fedorov Alexey
/// @date 19.04.2017

#ifndef FRAMEWORK_WINDOW_OSX_COCOA_WINDOW_HPP
#define FRAMEWORK_WINDOW_OSX_COCOA_WINDOW_HPP

#import "Cocoa/Cocoa.h"

#include <window/implementation.hpp>

namespace framework {

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

} // namespace framework

#endif
