#ifndef GRAPHICS_SHADER_HPP
#define GRAPHICS_SHADER_HPP

#include <filesystem>
#include <string>

#include <common/global_defines.hpp>
#include <math/math.hpp>

namespace neutrino::graphics
{
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @addtogroup graphics_renderer_module
/// @{
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @brief Shader.
///
/// Each Shader consists of two parts: vertex program and fragment program.
///
/// TODO: Remove predefined attributes. Add set_attribute_location(Attribute attr, int index) in Mesh.
/// #### For OpenGL:
///
/// Shader has predefined vertex attribute locations listed below:
///  - position              - 0
///  - normal                - 1
///  - tangent               - 2
///  - color                 - 3
///  - texture coordinate0-7 - 4-11
///
/// They can be used as follows:
/// @code
/// layout(location = 0) in vec3 vertexPosition;
/// @endcode
///
/// @see Mesh, Renderer
class Shader
{
public:
    Shader() = default;

    LIBRARY_API Shader(const Shader& other);
    LIBRARY_API Shader(Shader&& other) noexcept;

    ~Shader() = default;

    LIBRARY_API Shader& operator=(const Shader& other);
    LIBRARY_API Shader& operator=(Shader&& other) noexcept;

    /// @brief Load vertex shader source form file.
    ///
    /// @param filepath Path to vertex shader source file.
    ///
    /// @return `true` if loadint successful.
    LIBRARY_API bool set_vertex_source(const std::filesystem::path& filepath);

    /// @brief Set fragment shader source form file.
    ///
    /// @param filepath Path to fragment shader source file.
    ///
    /// @return `true` if loadint successful.
    LIBRARY_API bool set_fragment_source(const std::filesystem::path& filepath);

    /// @brief Set vertex shader source.
    ///
    /// @param source Vertex shader source.
    LIBRARY_API void set_vertex_source(const std::string& source);

    /// @brief Set fragment shader source.
    ///
    /// @param source Fragment shader source.
    LIBRARY_API void set_fragment_source(const std::string& source);

    /// @brief Remove all sources from Shader.
    ///
    /// If Shader loaded to Renderer, it's can be freely cleaned.
    ///
    /// @see Renderer::load.
    LIBRARY_API void clear();

    /// @brief Get vertex shader source.
    ///
    /// @return Vertex shader source.
    LIBRARY_API const std::string& vertex_source() const;

    /// @brief Get fragment shader source.
    ///
    /// @return Fragment shader source.
    LIBRARY_API const std::string& fragment_source() const;

private:
    LIBRARY_API friend void swap(Shader& lhs, Shader& rhs) noexcept;

    std::string m_vertex_source;
    std::string m_fragment_source;
};

/// @brief Swaps two Shaders.
///
/// @param lhs Shader to swap.
/// @param rhs Shader to swap.
LIBRARY_API void swap(Shader& lhs, Shader& rhs) noexcept;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
} // namespace neutrino::graphics

#endif
