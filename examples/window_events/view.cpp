#include "view.hpp"

#include <iomanip>
#include <sstream>

#include <common/position.hpp>
#include <common/size.hpp>
#include <graphics/font.hpp>
#include <graphics/shader.hpp>
#include <math/math.hpp>

#include "data_context.hpp"

using namespace neutrino;
using namespace neutrino::graphics;

using neutrino::system::Window;

namespace
{
const std::string vertex_shader =
"#version 330 core\n\
\n\
layout(location = 0) in vec3 position;\n\
\n\
uniform mat4 modelMatrix;\n\
uniform mat4 projectionMatrix;\n\
uniform vec4 color;\n\
\n\
out vec4 fragColor;\n\
\n\
void main()\n\
{\n\
    gl_Position = projectionMatrix * modelMatrix * vec4(position, 1.0);\n\
    fragColor = color;\n\
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

constexpr math::Vector3f WindowTextTopLeftOffset = {-300, -50, 0};
constexpr math::Vector3f CursorTextTopLeftOffset = {-300, -150, 0};

constexpr math::Vector3f CatTextBottomRightOffset = {80, -63, 0};
constexpr math::Vector3f FpsTextBottomRightOffset = {120, -50, 0};

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
    render_window_state(data);
    render_cursor_state(data);
    render_log(data);
    render_cat(data);
    render_fps(data);

    render_cursor_marker(data);

    m_renderer.display();
}

void View::on_resize(neutrino::Size size)
{
    m_renderer.set_uniform("projectionMatrix",
                           math::ortho2d<float>(0, static_cast<float>(size.width), 0, static_cast<float>(size.height)));
    m_renderer.set_viewport(size);
}

void View::render_window_state(const DataContext& data)
{
    const auto size         = data.window_size();
    math::Vector3f text_pos = math::Vector3f{size.width, size.height, 0} + WindowTextTopLeftOffset;

    render_normal_text(TextName::WindowTitleText, "Window  v ", text_pos);
    text_pos.y -= 15;

    std::stringstream ss;

    ss << "        +-> Size:      " << data.window_size();
    render_normal_text(TextName::WindowSizeText, ss.str(), text_pos);
    text_pos.y -= 15;
    ss.str("");

    ss << "        +-> Position:  " << data.window_position();
    render_normal_text(TextName::WindowPositionText, ss.str(), text_pos);
    text_pos.y -= 15;
    ss.str("");

    ss << "        +-> State:     " << get_state_name(data.window_state());
    render_normal_text(TextName::WindowStateText, ss.str(), text_pos);
    text_pos.y -= 15;
    ss.str("");

    ss << "        +-> Resizable: " << (data.window_resizable() ? "[x]" : "[ ]");
    render_normal_text(TextName::WindowResizableText, ss.str(), text_pos);
    text_pos.y -= 15;
    ss.str("");

    ss << "        +-> Input:     " << (data.window_has_input_focus() ? "[x]" : "[ ]");
    render_normal_text(TextName::WindowHasInputFocusText, ss.str(), text_pos);
    text_pos.y -= 15;
    ss.str("");
}

void View::render_cursor_state(const DataContext& data)
{
    const auto size = data.window_size();
    const auto pos  = data.window_cursor_position();

    math::Vector3f text_pos = math::Vector3f{size.width, size.height, 0} + CursorTextTopLeftOffset;

    render_normal_text(TextName::CursorTitleText, "Mouse   v ", text_pos);
    text_pos.y -= 15;

    std::stringstream ss;

    ss << "        +-> Position: " << pos;
    render_normal_text(TextName::CursorPositionText, ss.str(), text_pos);
    text_pos.y -= 15;
    ss.str("");

    ss << "        +-> Captured: " << (data.cursor_captured() ? "[x]" : "[ ]");
    render_normal_text(TextName::CursorCapturedText, ss.str(), text_pos);
    text_pos.y -= 15;
    ss.str("");

    ss << "        +-> Visible:  " << (data.cursor_visible() ? "[x]" : "[ ]");
    render_normal_text(TextName::CursorVisibleText, ss.str(), text_pos);
    text_pos.y -= 15;
    ss.str("");

    ss << "        +-> Hover:    " << (data.cursor_hover() ? "[x]" : "[ ]");
    render_normal_text(TextName::MouseHoverText, ss.str(), text_pos);
    text_pos.y -= 15;
    ss.str("");
}

void View::render_log(const DataContext& data)
{
    int offset                   = LogOffset;
    Renderer::ResourceId mesh_id = TextName::LogTextBegin;

    for (const auto& message : data.last_callback_events()) {
        render_normal_text(static_cast<TextName>(mesh_id), message, {LogOffset, offset, 0});

        offset += 15;
        mesh_id++;

        if (offset > data.window_size().height - LogOffset) {
            break;
        }
    }
}

void View::render_cat(const DataContext& data)
{
    static int time = 1000;

    const auto size = data.window_size();

    std::string text  = " ^  ^";
    std::string text1 = "(*.* )";

    time -= 16;
    if (time > 0) {
        text1 += "/";
    } else {
        text1 += "_";
    }

    if (time < -1000) {
        time = 1000;
    }

    math::Vector3f text_pos = math::Vector3f{size.width, 0, 0} - CatTextBottomRightOffset;
    render_normal_text(TextName::CatText, text, text_pos);
    render_normal_text(TextName::CatText1, text1, text_pos + math::Vector3f{0, -10, 0});
}

void View::render_fps(const DataContext& data)
{
    const auto size = data.window_size();

    math::Vector3f text_pos = math::Vector3f{size.width, 0, 0} - FpsTextBottomRightOffset;
    render_normal_text(TextName::FpsText, std::to_string(data.fps()), text_pos);
}

void View::render_cursor_marker(const DataContext& data)
{
    const auto size = data.window_size();

    const Mesh::VertexData vertices = {{-0.5, -0.5, 0.0}, {0.5, -0.5, 0.0}, {0.5, 0.5, 0.0}, {-0.5, 0.5, 0.0}};
    Mesh::IndicesData indices       = {0, 1, 2, 0, 2, 3};

    Mesh mesh;
    mesh.set_vertices(vertices);
    mesh.add_submesh(indices);

    m_renderer.load(TextName::CursorMarker, mesh);

    const auto p = data.window_cursor_position();

    math::Vector3f pos(p.x, p.y, 0.1);
    if (data.cursor_captured()) {
        pos += math::Vector3f(size.width / 2, size.height / 2, 0);
    }

    pos = math::Vector3f(pos.x, size.height - pos.y, 0.1);

    const math::Matrix4f transform = scale(translate(math::Matrix4f(), pos), {2, 2, 1});
    m_renderer.render(TextName::CursorMarker,
                      m_shader_id,
                      {Uniform{"modelMatrix", transform}, Uniform{"color", math::Vector4f(0.5f, 0.9f, 0.6f, 1.0f)}});
}

void View::render_normal_text(TextName id, const std::string& text, math::Vector3f position)
{
    m_renderer.load(id, m_font.create_text_mesh(text));
    const math::Matrix4f transform = scale(translate(math::Matrix4f(), position), normal_text_scale);
    m_renderer.render(id,
                      m_shader_id,
                      {Uniform{"modelMatrix", transform}, Uniform{"color", math::Vector4f(0.9f, 0.5f, 0.6f, 1.0f)}});
}
