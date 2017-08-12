/// @file window_implementation.hpp
/// @brief Describes interface for all canvas implementations.
/// @author Fedorov Alexey
/// @date 05.04.2017

#ifndef FRAMEWORK_WINDOW_WINDOW_IMPLEMENTATION_HPP
#define FRAMEWORK_WINDOW_WINDOW_IMPLEMENTATION_HPP

#include <common/common_types.hpp>
#include <memory>

namespace framework {

class window_implementation
{
public:
    virtual ~window_implementation() = default;

    virtual void show()  = 0;
    virtual void hide()  = 0;
    virtual void focus() = 0;

    virtual void minimize()       = 0;
    virtual void maximize()       = 0;
    virtual void to_full_screen() = 0;
    virtual void restore()        = 0;

    // setters
    virtual void set_size(int32 width, int32 height) = 0;
    virtual void set_position(int32 x, int32 y)      = 0;

    virtual void set_max_size(int32 width, int32 height) = 0;
    virtual void set_min_size(int32 width, int32 height) = 0;

    virtual void set_title(const std::string& title) = 0;

    // getters
    virtual int x()      = 0;
    virtual int y()      = 0;
    virtual int width()  = 0;
    virtual int height() = 0;

    virtual int max_height() = 0;
    virtual int max_width()  = 0;
    virtual int min_height() = 0;
    virtual int min_width()  = 0;

    virtual std::string title() = 0;

    virtual bool full_screen() = 0;
    virtual bool minimized()   = 0;
    virtual bool maximized()   = 0;
    virtual bool resizable()   = 0;
    virtual bool visible()     = 0;
    virtual bool focused()     = 0;
};

std::unique_ptr<window_implementation> get_implementation();
}

#endif
