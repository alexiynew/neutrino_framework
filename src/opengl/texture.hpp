/// @file
/// @brief OpenGL texture.
/// @author Fedorov Alexey
/// @date 16.04.2019

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

#ifndef FRAMEWORK_OPENGL_TEXTURE_HPP
#define FRAMEWORK_OPENGL_TEXTURE_HPP

#include <common/types.hpp>
#include <common/pixel_type.hpp>
#include <opengl/gl.hpp>

namespace framework::opengl
{

enum class min_filter
{
    nearest = GL_NEAREST, // Returns the value of the texture element that is nearest (in Manhattan distance) to the center of the pixel being textured.
    linear = GL_LINEAR, // Returns the weighted average of the four texture elements that are closest to the center of the pixel being textured.
    nearest_mipmap_nearest = GL_NEAREST_MIPMAP_NEAREST, // Chooses the mipmap that most closely matches the size of the pixel being textured and uses the GL_NEAREST criterion (the texture element nearest to the center of the pixel) to produce a texture value.
    linear_mipmap_nearest = GL_LINEAR_MIPMAP_NEAREST, // Chooses the mipmap that most closely matches the size of the pixel being textured and uses the GL_LINEAR criterion (a weighted average of the four texture elements that are closest to the center of the pixel) to produce a texture value.
    nearest_mipmap_linear = GL_NEAREST_MIPMAP_LINEAR, // Chooses the two mipmaps that most closely match the size of the pixel being textured and uses the GL_NEAREST criterion (the texture element nearest to the center of the pixel) to produce a texture value from each mipmap. The final texture value is a weighted average of those two values.
    linear_mipmap_linear = GL_LINEAR_MIPMAP_LINEAR,// Chooses the two mipmaps that most closely match the size of the pixel being textured and uses the GL_LINEAR criterion (a weighted average of the four texture elements that are closest to the center of the pixel) to produce a texture value from each mipmap. The final texture value is a weighted average of those two values. 
};

enum class mag_filter
{
    nearest = GL_NEAREST, // Returns the value of the texture element that is nearest (in Manhattan distance) to the center of the pixel being textured.
    linear = GL_LINEAR, //  Returns the weighted average of the four texture elements that are closest to the center of the pixel being textured.
};

enum class wrap_s
{
    clamp_to_edge = GL_CLAMP_TO_EDGE, 
    mirrored_repeat = GL_MIRRORED_REPEAT, 
    repeat = GL_REPEAT,
};

enum class wrap_t
{
    clamp_to_edge = GL_CLAMP_TO_EDGE, 
    mirrored_repeat = GL_MIRRORED_REPEAT, 
    repeat = GL_REPEAT,
};

enum class internal_format
{
    rgb,
    rgba,
};

class texture
{
public:

    texture(min_filter minf = min_filter::linear, 
            mag_filter magf = mag_filter::linear, 
            wrap_s ws = wrap_s::repeat, 
            wrap_t wt = wrap_t::repeat);

    void load(internal_format ifmt, int32 width, int32 height, pixel_t<pixel_format::rgb>* data)
    {

    }

    void bind();
    void unbind();

    void texture_id() const;
    void texture_unit() const;

private:
    framework::uint32 m_texture_id = 0;
};

}

#endif

