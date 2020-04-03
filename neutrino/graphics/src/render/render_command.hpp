////////////////////////////////////////////////////////////////////////////////
/// @file
/// @brief Render command.
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

#include <common/instance_id.hpp>

namespace framework::graphics
{
class RenderCommand
{
public:
    explicit RenderCommand(InstanceId mesh_id, InstanceId shader_id);

    InstanceId mesh_id() const;
    InstanceId shader_id() const;

private:
    InstanceId m_mesh_id;
    InstanceId m_shader_id;
};

} // namespace framework::graphics

#endif