////////////////////////////////////////////////////////////////////////////////
/// @file
/// @brief Renderer implementation interface.
/// @author Fedorov Alexey
/// @date 29.03.2020
////////////////////////////////////////////////////////////////////////////////

// =============================================================================
// MIT License
//
// Copyright (c) 2017-2021 Fedorov Alexey
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

#ifndef FRAMEWORK_GRAPHICS_SRC_RENDER_RENDERER_IMPL_HPP
#define FRAMEWORK_GRAPHICS_SRC_RENDER_RENDERER_IMPL_HPP

#include <vector>

#include <graphics/color.hpp>
#include <graphics/renderer.hpp>
#include <math/math.hpp>

namespace framework::graphics
{
class Mesh;
class Shader;
class Texture;

class RendererImpl
{
public:
    using VertexData  = std::vector<math::Vector4f>;
    using IndicesData = std::vector<int>;

    virtual ~RendererImpl() = default;

    virtual void set_clear_color(const Color& color) = 0;
    virtual void set_viewport(Size size)             = 0;

    virtual bool load(const Mesh& mesh)       = 0;
    virtual bool load(const Shader& shader)   = 0;
    virtual bool load(const Texture& texture) = 0;

    virtual void start_frame()                            = 0;
    virtual void render(const Renderer::Command& command) = 0;
    virtual void end_frame()                              = 0;
};

} // namespace framework::graphics

#endif
