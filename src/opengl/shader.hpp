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

#include <string>
#include <fstream>

#include <opengl/gl.hpp>
#include <common/types.hpp>

namespace framework::opengl
{

class shader
{
public:
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

    virtual ~shader();

protected:
    shader();

    framework::uint32 m_shader_id = 0;
};


class vertex_shader : public shader
{
public:
    vertex_shader();
};

class fragment_shader : public shader
{
public:
    fragment_shader();
};

class shader_program
{
    

};

}

#endif
