/// @file
/// @brief Describes interface for all canvas implementations.
/// @author Fedorov Alexey
/// @date 05.04.2017

#ifndef FRAMEWORK_WINDOW_IMPLEMENTATION_HPP
#define FRAMEWORK_WINDOW_IMPLEMENTATION_HPP

#include <memory>
#include <string>
#include <vector>
#include <window/window.hpp>

namespace framework {

class window::implementation
{
public:
    static std::unique_ptr<implementation> get_implementation();

    implementation()          = default;
    virtual ~implementation() = default;

    implementation(const implementation&) = delete;
    implementation& operator=(const implementation&) = delete;

    // actions
    virtual void show()           = 0;
    virtual void hide()           = 0;
    virtual void focus()          = 0;
    virtual void process_events() = 0;

    virtual void minimize()       = 0;
    virtual void maximize()       = 0;
    virtual void to_full_screen() = 0;
    virtual void restore()        = 0;

    // setters
    virtual void set_size(size_t)         = 0;
    virtual void set_position(position_t) = 0;

    virtual void set_max_size(size_t) = 0;
    virtual void set_min_size(size_t) = 0;

    virtual void set_title(const std::string& title) = 0;

    // getters
    virtual position_t position() const = 0;
    virtual size_t size() const         = 0;

    virtual size_t max_size() const = 0;
    virtual size_t min_size() const = 0;

    virtual std::string title() const = 0;

    // state
    virtual bool full_screen() const = 0;
    virtual bool minimized() const   = 0;
    virtual bool maximized() const   = 0;
    virtual bool resizable() const   = 0;
    virtual bool visible() const     = 0;
    virtual bool focused() const     = 0;
};

} // namespace framework

#endif
