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

#ifndef FRAMEWORK_GRAPHICS_SHADER_HPP
#define FRAMEWORK_GRAPHICS_SHADER_HPP

#include <istream>
#include <string>

#include <common/types.hpp>
#include <math/math.hpp>

namespace framework::opengl
{
/// @addtogroup opengl_module
/// @{

/// @brief base class for OpenGL shaders.
///
/// Encapsulates all base operations with shader.
/// Provides unified interface for all kinds of shaders.
///
/// @thread_safety All operations must be done only in main thread.
///
/// @see vertex_shader fragment_shader
class shader_base
{
public:
    /// @brief Destructor.
    ///
    /// Marks shader for deletion.
    virtual ~shader_base() = 0;

    shader_base(const shader_base&) = delete;
    shader_base& operator=(const shader_base&) = delete;

    /// @brief Move constructor.
    ///
    /// @param other Shader to move from.
    shader_base(shader_base&&);

    /// @brief Move operator.
    ///
    /// @param other Shader to move from.
    ///
    /// @return Reference to moved object.
    shader_base& operator=(shader_base&&);

    /// @brief Sets the new shader source code.
    ///
    /// Deletes old shader source code and sets the new one.
    /// After source code was set, the shader need to be compiled @ref compile.
    ///
    /// @param src Shader source code.
    void set_source(const std::string& src);

    /// @brief Reads shader source code from input stream.
    ///
    /// Deletes old shader source code and sets the new one.
    /// After source code was set, the shader need to be compiled @ref compile.
    ///
    /// @param src_stream Shader source code stream.
    void set_source(std::istream& src_stream);

    /// @brief Compiles the shader.
    ///
    /// Compiles stored shader code.
    /// Compilation status can be obtained by @ref compiled.
    /// If compilation fails for any reason, information about errors can be obtained by @ref info_log.
    void compile();

    /// @brief Deletes OpenGL shader object.
    ///
    /// If a shader is attached to a shader_program, it will be flagged for deletion, but it will not be deleted until
    /// it is no longer attached to any shader_program.
    void mark_for_deletion();

    /// @brief OpenGL shader object type.
    ///
    /// @retrun Shader object type (e.g: GL_VERTEX_SHADER, GL_FRAGMENT_SHADER)
    framework::int32 shader_type() const;

    /// @brief Determines if shader can be used.
    ///
    /// @return `true` if shader created and not yet deleted.
    bool valid() const;

    /// @brief Determines if shader sources compiled.
    ///
    /// @return `true` if shader source loaded and compiled successfully.
    bool compiled() const;

    /// @brief Length of shader sources.
    ///
    /// @return Length of loaded shader source code.
    framework::int32 source_length() const;

    /// @brief Shader sources.
    ///
    /// @return Loaded shader source code.
    std::string source() const;

    /// @brief Shader information log.
    ///
    /// Shader info log updated when shader is compiled.
    ///
    /// @return Shader information log if any.
    std::string info_log() const;

    /// @brief Shader id.
    ///
    /// @return OpenGL shader object id.
    framework::uint32 shader_id() const;

protected:
    shader_base(int32 shader_type);

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

    shader_program(shader_program&&);
    shader_program& operator=(shader_program&&);

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
