////////////////////////////////////////////////////////////////////////////////
/// @file
/// @brief Renderer command.
/// @author Fedorov Alexey
/// @date 01.04.2020
////////////////////////////////////////////////////////////////////////////////

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

#ifndef FRAMEWORK_GRAPHICS_SRC_RENDER_RENDER_COMMAND_HPP
#define FRAMEWORK_GRAPHICS_SRC_RENDER_RENDER_COMMAND_HPP

#include <vector>

#include <common/instance_id.hpp>
#include <graphics/renderer.hpp>
#include <math/math.hpp>

namespace framework::graphics
{

class RenderCommand
{
public:
    using InstanceIdList = std::vector<InstanceId>;

    struct CachedMatrix
    {
        using MatrixType = Renderer::MatrixCache::value_type;

        const Renderer::MatrixCache& cache;
        const std::size_t index;

        const MatrixType& get() const;
    };

    RenderCommand(InstanceId mesh,
                  InstanceId shader,
                  const InstanceIdList& textures,
                  const math::Matrix4f model_matrix,
                  const CachedMatrix view_matrix,
                  const CachedMatrix projection_matrix,
                  const math::Matrix3f normal_matrix);

    InstanceId mesh() const;
    InstanceId shader() const;

    const InstanceIdList& textures() const;

    const math::Matrix4f& model_matrix() const;
    const math::Matrix4f& view_matrix() const;
    const math::Matrix4f& projection_matrix() const;
    const math::Matrix3f& normal_matrix() const;

private:
    const InstanceId m_mesh;
    const InstanceId m_shader;

    const InstanceIdList m_textures;

    const math::Matrix4f m_model_matrix;
    const CachedMatrix m_view_matrix;
    const CachedMatrix m_projection_matrix;
    const math::Matrix3f m_normal_matrix;
};

} // namespace framework::graphics

#endif
