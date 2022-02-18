#ifndef FRAMEWORK_GRAPHICS_UNIFORM_HPP
#define FRAMEWORK_GRAPHICS_UNIFORM_HPP

#include <string>
#include <variant>

#include <common/instance_id.hpp>
#include <math/math.hpp>

namespace framework::graphics
{
class Texture;

////////////////////////////////////////////////////////////////////////////////
/// @addtogroup graphics_renderer_module
/// @{
////////////////////////////////////////////////////////////////////////////////

class TextureBinding
{
public:
    TextureBinding(const Texture& texture);

    InstanceId texture() const;

private:
    InstanceId m_texture;
};

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
                                  math::Matrix4x3d,
                                  //
                                  TextureBinding>;

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
