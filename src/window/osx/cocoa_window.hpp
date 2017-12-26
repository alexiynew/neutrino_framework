/// @file
/// @brief Window implementation for osx.
/// @author Fedorov Alexey
/// @date 19.04.2017

#ifndef FRAMEWORK_WINDOW_OSX_COCOA_WINDOW_HPP
#define FRAMEWORK_WINDOW_OSX_COCOA_WINDOW_HPP

#include <window/window_implementation.hpp>

#import "Cocoa/Cocoa.h"

namespace framework {

class cocoa_window final : public window_implementation
{
public:
    cocoa_window();
    ~cocoa_window() override;

    void show() override;
    void hide() override;
    void focus() override;
    void process_events() override;

    void minimize() override;
    void maximize() override;
    void to_full_screen() override;
    void restore() override;

    void set_size(int32 width, int32 height) override;
    void set_position(int32 x, int32 y) override;

    void set_max_size(int32 width, int32 height) override;
    void set_min_size(int32 width, int32 height) override;

    void set_title(const std::string& title) override;

    int x() override;
    int y() override;
    int width() override;
    int height() override;

    int max_height() override;
    int max_width() override;
    int min_height() override;
    int min_width() override;

    std::string title() override;

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
