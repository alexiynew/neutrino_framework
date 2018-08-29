/// @file
/// @brief OpneGL canvas implementation.
/// @author Fedorov Alexey
/// @date 02.06.2018

#ifndef FRAMEWORK_GRAPHIC_OPENGL_CANVAS_HPP
#define FRAMEWORK_GRAPHIC_OPENGL_CANVAS_HPP

#include <graphic/canvas.hpp>
#include <graphic/window.hpp>

namespace framework
{
namespace graphic
{
class opengl_canvas final : public canvas
{
public:
    explicit opengl_canvas(std::unique_ptr<window::graphic_context> context);

    ~opengl_canvas() override;

    opengl_canvas(const opengl_canvas&) = delete;
    opengl_canvas& operator=(const opengl_canvas&) = delete;

    opengl_canvas(opengl_canvas&&) = default;
    opengl_canvas& operator=(opengl_canvas&&) = default;

    /// Returns the company responsible for this GL implementation.
    /// This name does not change from release to release.
    std::string vendor_name();

    /// Returns the name of the renderer. This name is typically specific to a particular configuration of a hardware
    /// platform. It does not change from release to release.
    std::string renderer_name();

    /// Returns a version or release number.
    std::string version();

    /// Returns a version or release number for the shading language.
    std::string shading_language_version();

    void clear(float red, float green, float blue, float alpha) override;

    // int load_mesh(const std::vector<vector4f>&);
    // void load_texture_coordinates(int mesh_id, const std::vector<vector2f>&);
    // void load_texture(const std::vector<uint8>& rgba_bitmap);

    // void use_shader(int id);
    // void draw(int mesh_id, int texture_id, matrix4f transform);

    void swap_buffers() override;

private:
    std::unique_ptr<window::graphic_context> m_context;
};

} // namespace graphic

} // namespace framework

#endif
