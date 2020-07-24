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

#include <graphics/src/render/render_command.hpp>

namespace framework::graphics
{

const RenderCommand::CachedMatrix::MatrixType& RenderCommand::CachedMatrix::get() const
{
    return cache.at(index);
}

RenderCommand::RenderCommand(InstanceId mesh,
                             InstanceId shader,
                             const InstanceIdList& textures,
                             const math::Matrix4f model_matrix,
                             const CachedMatrix view_matrix,
                             const CachedMatrix projection_matrix,
                             const math::Matrix3f normal_matrix)
    : m_mesh(mesh)
    , m_shader(shader)
    , m_textures(textures)
    , m_model_matrix(model_matrix)
    , m_view_matrix(view_matrix)
    , m_projection_matrix(projection_matrix)
    , m_normal_matrix(normal_matrix)
{}

InstanceId RenderCommand::mesh() const
{
    return m_mesh;
}

InstanceId RenderCommand::shader() const
{
    return m_shader;
}

const RenderCommand::InstanceIdList& RenderCommand::textures() const
{
    return m_textures;
}

const math::Matrix4f& RenderCommand::model_matrix() const
{
    return m_model_matrix;
}

const math::Matrix4f& RenderCommand::view_matrix() const
{
    return m_view_matrix.get();
}

const math::Matrix4f& RenderCommand::projection_matrix() const
{
    return m_projection_matrix.get();
}

const math::Matrix3f& RenderCommand::normal_matrix() const
{
    return m_normal_matrix;
}

} // namespace framework::graphics
