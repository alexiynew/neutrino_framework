#ifndef GRAPHICS_UNIFORM_HPP
#define GRAPHICS_UNIFORM_HPP

#include <string>
#include <variant>

#include <common/instance_id.hpp>
#include <math/math.hpp>

namespace framework::graphics
{
class Texture;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @addtogroup graphics_renderer_module
/// @{
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @brief Wrapper class to represent texture value in uniforms.
class TextureBinding
{
public:
    TextureBinding(const Texture& texture);

    InstanceId texture() const;

private:
    InstanceId m_texture;
};

/// @brief Alias to all possible value types in uniform.

// clang-format off
using UniformValue = std::variant<float, math::Vector2f, math::Vector3f, math::Vector4f,
                                  double, math::Vector2d, math::Vector3d, math::Vector4d,
                                  int, math::Vector2i, math::Vector3i, math::Vector4i,
                                  unsigned int, math::Vector2u, math::Vector3u, math::Vector4u,
                                  bool, math::Vector2b, math::Vector3b, math::Vector4b,

                                  math::Matrix2f, math::Matrix3f, math::Matrix4f,
                                  math::Matrix2x3f, math::Matrix2x4f, math::Matrix3x2f,
                                  math::Matrix3x4f, math::Matrix4x2f, math::Matrix4x3f,

                                  math::Matrix2d, math::Matrix3d, math::Matrix4d,
                                  math::Matrix2x3d, math::Matrix2x4d, math::Matrix3x2d,
                                  math::Matrix3x4d, math::Matrix4x2d, math::Matrix4x3d,

                                  TextureBinding>;
// clang-format on

/// @brief Represents uniform value for shaders.
class Uniform
{
public:
    /// @brief Creates uniform with a copy of the value.
    ///
    /// @param name Uniform name.
    /// @param value Uniform value.
    template <typename T>
    Uniform(std::string name, const T& value) noexcept
        : m_name(std::move(name))
        , m_value(value)
    {}

    /// @brief Creates uniform with a value.
    ///
    /// @param name Uniform name.
    /// @param value Uniform value.
    template <typename T>
    Uniform(std::string name, T&& value) noexcept
        : m_name(std::move(name))
        , m_value(std::forward<T>(value))
    {}

    Uniform() = default;

    Uniform(const Uniform&) = default;
    Uniform(Uniform&&)      = default;

    Uniform& operator=(const Uniform&) = default;
    Uniform& operator=(Uniform&&) = default;

    /// @brief Uniform name
    ///
    /// @return Uniform name.
    const std::string& name() const;

    /// @brief Uniform value
    ///
    /// @return Uniform value.
    const UniformValue& value() const;

private:
    std::string m_name;
    UniformValue m_value;
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

} // namespace framework::graphics

#endif
