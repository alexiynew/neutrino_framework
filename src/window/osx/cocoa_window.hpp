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

    // actions
    void show() override;
    void hide() override;
    void focus() override;
    void process_events() override;

    void minimize() override;
    void maximize() override;
    void to_full_screen() override;
    void restore() override;

    // setters
    void set_size(window::size_t size) override;
    void set_position(window::position_t position) override;

    void set_max_size(window::size_t max_size) override;
    void set_min_size(window::size_t min_size) override;

    void set_title(const std::string& title) override;

    // getters
    virtual window::position_t position() override;
    virtual window::size_t size() override;

    virtual window::size_t max_size() override;
    virtual window::size_t min_size() override;

    std::string title() override;

    // state
    bool full_screen() override;
    bool minimized() override;
    bool maximized() override;
    bool resizable() override;
    bool visible() override;
    bool focused() override;

private:
    NSAutoreleasePool* pool;
    NSWindow* window;
};

} // namespace framework

#endif
