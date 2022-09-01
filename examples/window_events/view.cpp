#include "view.hpp"

#include <common/position.hpp>
#include <common/size.hpp>
#include <graphics/font.hpp>
#include <graphics/shader.hpp>
#include <math/math.hpp>

#include "data_context.hpp"

using namespace framework;
using namespace framework::graphics;

using framework::system::Window;

namespace
{
const std::string vertex_shader =
"#version 330 core\n\
\n\
layout(location = 0) in vec3 position;\n\
\n\
uniform mat4 modelMatrix;\n\
uniform mat4 projectionMatrix;\n\
\n\
out vec4 fragColor;\n\
\n\
void main()\n\
{\n\
    gl_Position = projectionMatrix * modelMatrix * vec4(position, 1.0);\n\
    fragColor = vec4(0.9, 0.5, 0.6, 1.0);\n\
}\n\
";

const std::string fragment_shader =
"#version 330 core\n\
\n\
in vec4 fragColor;\n\
\n\
out vec4 color;\n\
\n\
void main()\n\
{\n\
    color = fragColor;\n\
}\n\
";

constexpr int LogOffset                    = 50;
constexpr math::Vector3f normal_text_scale = {15, 15, 1};

constexpr math::Vector3f SizeTextOffset     = {-300, -25, 0};
constexpr math::Vector3f PositionTextOffset = {-150, -25, 0};
constexpr math::Vector3f CursorTextOffset   = {-300, -50, 0};
constexpr math::Vector3f StateTextOffset    = {-300, -75, 0};

std::string get_state_name(Window::State state)
{
    switch (state) {
        case Window::State::fullscreen: return "Fullscreen";
        case Window::State::maximized: return "Maximized";
        case Window::State::iconified: return "Iconified";
        case Window::State::normal: return "Normal";
    }
    return "";
}

} // namespace

View::View(Window& window)
    : m_renderer(window.context())
{
    if (m_font.load("data/UbuntuMono-Regular.ttf") != Font::LoadResult::Success) {
        throw std::runtime_error("Can't load font.");
    }

    Shader shader;
    shader.set_vertex_source(vertex_shader);
    shader.set_fragment_source(fragment_shader);
    if (!m_renderer.load(m_shader_id, shader)) {
        throw std::runtime_error("Can't load shader.");
    }

    m_renderer.set_clear_color(Color(0x2F2F2FFFU));
}

View::~View()
{}

void View::render(const DataContext& data)
{
    render_size_position(data);
    render_cursor_position(data);
    render_state(data);
    render_log(data);

    m_renderer.display();
}

void View::on_resize(framework::Size size)
{
    m_renderer.set_uniform("projectionMatrix",
                           math::ortho2d<float>(0, static_cast<float>(size.width), -static_cast<float>(size.height), 0));
    m_renderer.set_viewport(size);

    m_top_log_offset  = -(size.height - LogOffset);
    m_left_log_offset = LogOffset;
}

void View::render_size_position(const DataContext& data)
{
    const auto size = data.window_size();
    const auto pos  = data.window_position();

    const std::string size_text = "Size: " + std::to_string(size.width) + ", " + std::to_string(size.height);
    const std::string pos_text  = "Position: " + std::to_string(pos.x) + ", " + std::to_string(pos.y);

    const math::Vector3f size_text_pos     = math::Vector3f{size.width, 0, 0} - SizeTextOffset;
    const math::Vector3f position_text_pos = math::Vector3f{size.width, 0, 0} - PositionTextOffset;

    m_renderer.load(TextName::SizeText, m_font.create_text_mesh(size_text));
    m_renderer.load(TextName::PositionText, m_font.create_text_mesh(pos_text));

    render_normal_text(TextName::SizeText, size_text_pos);
    render_normal_text(TextName::PositionText, position_text_pos);
}

void View::render_cursor_position(const DataContext& data)
{
    const auto size = data.window_size();
    const auto pos  = data.window_cursor_position();

    const std::string text = "Cursor: " + std::to_string(pos.x) + ", " + std::to_string(pos.y);

    const math::Vector3f text_pos = math::Vector3f{size.width, 0, 0} - CursorTextOffset;

    m_renderer.load(TextName::CursorPositionText, m_font.create_text_mesh(text));
    render_normal_text(TextName::CursorPositionText, text_pos);
}

void View::render_state(const DataContext& data)
{
    const auto size = data.window_size();

    const std::string text        = "State: " + get_state_name(data.window_state());
    const math::Vector3f text_pos = math::Vector3f{size.width, 0, 0} - StateTextOffset;

    m_renderer.load(TextName::WindowStateText, m_font.create_text_mesh(text));
    render_normal_text(TextName::WindowStateText, text_pos);
}

void View::render_log(const DataContext& data)
{
    int offset                   = m_top_log_offset;
    Renderer::ResourceId mesh_id = TextName::LogTextBegin;

    for (const auto& message : data.last_callback_events()) {
        m_renderer.load(mesh_id, m_font.create_text_mesh(message));
        render_normal_text(static_cast<TextName>(mesh_id), {LogOffset, offset, 0});

        offset += 15;
        mesh_id++;

        if (offset > -LogOffset) {
            break;
        }
    }
}

void View::render_normal_text(TextName id, math::Vector3f position)
{
    const math::Matrix4f transform = scale(translate(math::Matrix4f(), position), normal_text_scale);
    m_renderer.render(id, m_shader_id, {Uniform{"modelMatrix", transform}});
}
