#ifndef GRAPHICS_SRC_RENDER_OPENGL_ATTRIBUTES_HPP
#define GRAPHICS_SRC_RENDER_OPENGL_ATTRIBUTES_HPP

#include <array>

namespace framework::graphics
{
enum class Attribute
{
    position  = 0,
    normal    = 1,
    tangent   = 2,
    color     = 3,
    texcoord0 = 4,
    texcoord1 = 5,
    texcoord2 = 6,
    texcoord3 = 7,
    texcoord4 = 8,
    texcoord5 = 9,
    texcoord6 = 10,
    texcoord7 = 11,
};

static constexpr int attributes_count = 12;

} // namespace framework::graphics

#endif
