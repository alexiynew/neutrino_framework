/// @file
/// @brief OpenGL shader.
/// @author Fedorov Alexey
/// @date 12.04.2019

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

#ifndef FRAMEWORK_OPENGL_SHADER_HPP
#define FRAMEWORK_OPENGL_SHADER_HPP

#include <fstream>
#include <string>

#include <common/types.hpp>
#include <math/math.hpp>
#include <opengl/gl.hpp>

namespace framework::opengl
{
class shader_base
{
public:
    shader_base(const shader_base&) = delete;
    shader_base& operator=(const shader_base&) = delete;

    void set_source(const std::string& src);
    void set_source(std::ifstream& src_stream);

    void compile();
    void mark_for_deletion();

    framework::int32 shader_type() const;
    bool valid() const;
    bool compiled() const;
    bool marked_for_deletion() const;
    framework::int32 source_length() const;

    std::string source() const;
    std::string info_log() const;
    framework::int32 shader_id() const;

    virtual ~shader_base();

protected:
    shader_base();

    shader_base(shader_base&&) = default;
    shader_base& operator=(shader_base&&) = default;

    framework::uint32 m_shader_id = 0;
};

class vertex_shader : public shader_base
{
public:
    vertex_shader();
    ~vertex_shader() = default;

    vertex_shader(const vertex_shader&) = delete;
    vertex_shader& operator=(const vertex_shader&) = delete;

    vertex_shader(vertex_shader&&) = default;
    vertex_shader& operator=(vertex_shader&&) = default;
};

class fragment_shader : public shader_base
{
public:
    fragment_shader();
    ~fragment_shader() = default;

    fragment_shader(const fragment_shader&) = delete;
    fragment_shader& operator=(const fragment_shader&) = delete;

    fragment_shader(fragment_shader&&) = default;
    fragment_shader& operator=(fragment_shader&&) = default;
};

class shader_program
{
public:
    shader_program();
    ~shader_program();

    shader_program(const shader_program&) = delete;
    shader_program& operator=(const shader_program&) = delete;

    shader_program(shader_program&&) = default;
    shader_program& operator=(shader_program&&) = default;

    void arttach(const shader_base& shader);

    void link();

    void use();
    void stop_using();

    void uniform(const std::string& name, int value);
    void uniform(const std::string& name, math::matrix4f value, bool transpose = false);

    std::string info_log() const;
    bool linked() const;

    framework::uint32 program_id() const;

private:
    framework::uint32 m_program_id = 0;
};

} // namespace framework::opengl

#endif
