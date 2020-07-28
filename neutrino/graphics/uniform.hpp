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

#include <math/math.hpp>

namespace framework::graphics
{
////////////////////////////////////////////////////////////////////////////////
/// @addtogroup graphics_module
/// @{
////////////////////////////////////////////////////////////////////////////////

template <typename T>
class Uniform;

class UniformSetter
{
public:
    virtual ~UniformSetter() = default;

    virtual void set_uniform(int location, const Uniform<float>& uniform) const          = 0;
    virtual void set_uniform(int location, const Uniform<math::Vector2f>& uniform) const = 0;
    virtual void set_uniform(int location, const Uniform<math::Vector3f>& uniform) const = 0;
    virtual void set_uniform(int location, const Uniform<math::Vector4f>& uniform) const = 0;

    virtual void set_uniform(int location, const Uniform<double>& uniform) const         = 0;
    virtual void set_uniform(int location, const Uniform<math::Vector2d>& uniform) const = 0;
    virtual void set_uniform(int location, const Uniform<math::Vector3d>& uniform) const = 0;
    virtual void set_uniform(int location, const Uniform<math::Vector4d>& uniform) const = 0;

    virtual void set_uniform(int location, const Uniform<int>& uniform) const            = 0;
    virtual void set_uniform(int location, const Uniform<math::Vector2i>& uniform) const = 0;
    virtual void set_uniform(int location, const Uniform<math::Vector3i>& uniform) const = 0;
    virtual void set_uniform(int location, const Uniform<math::Vector4i>& uniform) const = 0;

    virtual void set_uniform(int location, const Uniform<unsigned int>& uniform) const   = 0;
    virtual void set_uniform(int location, const Uniform<math::Vector2u>& uniform) const = 0;
    virtual void set_uniform(int location, const Uniform<math::Vector3u>& uniform) const = 0;
    virtual void set_uniform(int location, const Uniform<math::Vector4u>& uniform) const = 0;

    virtual void set_uniform(int location, const Uniform<bool>& uniform) const           = 0;
    virtual void set_uniform(int location, const Uniform<math::Vector2b>& uniform) const = 0;
    virtual void set_uniform(int location, const Uniform<math::Vector3b>& uniform) const = 0;
    virtual void set_uniform(int location, const Uniform<math::Vector4b>& uniform) const = 0;

    virtual void set_uniform(int location, const Uniform<math::Matrix2f>& uniform) const   = 0;
    virtual void set_uniform(int location, const Uniform<math::Matrix3f>& uniform) const   = 0;
    virtual void set_uniform(int location, const Uniform<math::Matrix4f>& uniform) const   = 0;
    virtual void set_uniform(int location, const Uniform<math::Matrix2x3f>& uniform) const = 0;
    virtual void set_uniform(int location, const Uniform<math::Matrix2x4f>& uniform) const = 0;
    virtual void set_uniform(int location, const Uniform<math::Matrix3x2f>& uniform) const = 0;
    virtual void set_uniform(int location, const Uniform<math::Matrix3x4f>& uniform) const = 0;
    virtual void set_uniform(int location, const Uniform<math::Matrix4x2f>& uniform) const = 0;
    virtual void set_uniform(int location, const Uniform<math::Matrix4x3f>& uniform) const = 0;

    virtual void set_uniform(int location, const Uniform<math::Matrix2d>& uniform) const   = 0;
    virtual void set_uniform(int location, const Uniform<math::Matrix3d>& uniform) const   = 0;
    virtual void set_uniform(int location, const Uniform<math::Matrix4d>& uniform) const   = 0;
    virtual void set_uniform(int location, const Uniform<math::Matrix2x3d>& uniform) const = 0;
    virtual void set_uniform(int location, const Uniform<math::Matrix2x4d>& uniform) const = 0;
    virtual void set_uniform(int location, const Uniform<math::Matrix3x2d>& uniform) const = 0;
    virtual void set_uniform(int location, const Uniform<math::Matrix3x4d>& uniform) const = 0;
    virtual void set_uniform(int location, const Uniform<math::Matrix4x2d>& uniform) const = 0;
    virtual void set_uniform(int location, const Uniform<math::Matrix4x3d>& uniform) const = 0;
};

class UniformBase
{
public:
    explicit UniformBase(const std::string& name);

    virtual ~UniformBase();

    virtual void set(int location, const UniformSetter& setter) const = 0;

    const std::string& name() const;

private:
    const std::string m_name;
};

template <typename T>
class Uniform : public UniformBase
{
public:
    Uniform(const std::string& name, const T& value)
        : UniformBase(name)
        , m_value(value)
    {}

    Uniform(Uniform&&) = default;
    Uniform& operator=(Uniform&&) = default;

    void set(int location, const UniformSetter& setter) const override
    {
        setter.set_uniform(location, *this);
    }

    const T& value() const
    {
        return m_value;
    }

private:
    const T m_value;
};

////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////

} // namespace framework::graphics

#endif
