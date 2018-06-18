/// @file
/// @brief Describes interface for all opengl_canvas implementations.
/// @author Fedorov Alexey
/// @date 05.04.2017

#ifndef FRAMEWORK_GRAPHIC_OPENGL_CANVAS_IMPLEMENTATION_HPP
#define FRAMEWORK_GRAPHIC_OPENGL_CANVAS_IMPLEMENTATION_HPP

#include <graphic/opengl/opengl_canvas.hpp>
#include <graphic/window.hpp>

namespace framework
{
namespace graphic
{
class opengl_canvas::implementation
{
public:
    static std::unique_ptr<implementation> create(const ::framework::graphic::window& window);

    implementation()          = default;
    virtual ~implementation() = default;

    implementation(const implementation&) = delete;
    implementation& operator=(const implementation&) = delete;

    virtual void make_current() = 0;
    virtual void swap_buffers() = 0;
};

} // namespace graphic

} // namespace framework

#endif
