////////////////////////////////////////////////////////////////////////////////
/// @file
/// @brief Uniform.
/// @author Fedorov Alexey
/// @date 25.07.2019
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

#ifndef FRAMEWORK_GRAPHICS_UNIFORM_HPP
#define FRAMEWORK_GRAPHICS_UNIFORM_HPP

#include <string>
#include <variant>

#include <math/math.hpp>

namespace framework::graphics
{
////////////////////////////////////////////////////////////////////////////////
/// @addtogroup graphics_module
/// @{
////////////////////////////////////////////////////////////////////////////////

using UniformValue = std::variant<float,
                                  math::Vector2f,
                                  math::Vector3f,
                                  math::Vector4f,
                                  //
                                  double,
                                  math::Vector2d,
                                  math::Vector3d,
                                  math::Vector4d,
                                  //
                                  int,
                                  math::Vector2i,
                                  math::Vector3i,
                                  math::Vector4i,
                                  //
                                  unsigned int,
                                  math::Vector2u,
                                  math::Vector3u,
                                  math::Vector4u,
                                  //
                                  bool,
                                  math::Vector2b,
                                  math::Vector3b,
                                  math::Vector4b,
                                  //
                                  math::Matrix2f,
                                  math::Matrix3f,
                                  math::Matrix4f,
                                  math::Matrix2x3f,
                                  math::Matrix2x4f,
                                  math::Matrix3x2f,
                                  math::Matrix3x4f,
                                  math::Matrix4x2f,
                                  math::Matrix4x3f,
                                  //
                                  math::Matrix2d,
                                  math::Matrix3d,
                                  math::Matrix4d,
                                  math::Matrix2x3d,
                                  math::Matrix2x4d,
                                  math::Matrix3x2d,
                                  math::Matrix3x4d,
                                  math::Matrix4x2d,
                                  math::Matrix4x3d>;

class Uniform
{
public:
    template <typename T>
    Uniform(std::string name, const T& value) noexcept
        : m_name(std::move(name))
        , m_value(value)
    {}

    template <typename T>
    Uniform(std::string name, T&& value) noexcept
        : m_name(std::move(name))
        , m_value(std::forward<T>(value))
    {}

    Uniform() = default;

    Uniform(const Uniform&) = default;
    Uniform& operator=(const Uniform&) = default;

    Uniform(Uniform&&) = default;
    Uniform& operator=(Uniform&&) = default;

    const std::string& name() const;
    const UniformValue& value() const;

private:
    std::string m_name;
    UniformValue m_value;
};

////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////

} // namespace framework::graphics

#endif
