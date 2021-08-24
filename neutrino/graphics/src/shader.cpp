/// @file
/// @brief OpenGL shader.
/// @author Fedorov Alexey
/// @date 12.04.2019

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

#include <fstream>
#include <sstream>

#include <graphics/shader.hpp>

namespace framework::graphics
{

Shader::Shader(const Shader& other)
    : m_vertex_source(other.m_vertex_source)
    , m_fragment_source(other.m_fragment_source)
{}

Shader& Shader::operator=(const Shader& other)
{
    using std::swap;

    Shader tmp(other);
    swap(*this, tmp);
    return *this;
}

Shader::Shader(Shader&& other) noexcept
{
    swap(*this, other);
}

Shader& Shader::operator=(Shader&& other) noexcept
{
    swap(*this, other);
    return *this;
}

bool Shader::load_vertex_source(const std::string& filename)
{
    std::ifstream file(filename, std::ios::in);
    if (!file) {
        return false;
    }

    std::stringstream source;
    source << file.rdbuf();

    set_vertex_source(source.str());

    return true;
}

bool Shader::load_fragment_source(const std::string& filename)
{
    std::ifstream file(filename, std::ios::in);
    if (!file) {
        return false;
    }

    std::stringstream source;
    source << file.rdbuf();

    set_fragment_source(source.str());

    return true;
}

void Shader::set_vertex_source(const std::string& source)
{
    m_vertex_source = source;
}

void Shader::set_fragment_source(const std::string& source)
{
    m_fragment_source = source;
}

void Shader::clear()
{
    m_vertex_source.clear();
    m_fragment_source.clear();
}

InstanceId Shader::instance_id() const
{
    return m_instance_id;
}

const std::string& Shader::vertex_source() const
{
    return m_vertex_source;
}

const std::string& Shader::fragment_source() const
{
    return m_fragment_source;
}

void swap(Shader& lhs, Shader& rhs) noexcept
{
    using std::swap;
    swap(lhs.m_vertex_source, rhs.m_vertex_source);
    swap(lhs.m_fragment_source, rhs.m_fragment_source);
}

} // namespace framework::graphics
