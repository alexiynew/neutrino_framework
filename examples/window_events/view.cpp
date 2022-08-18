#include "view.hpp"

#include <graphics/font.hpp>
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

} // namespace

View::View(Window& window)
    : m_renderer(window.context())
{
    if (m_font.load("data/UbuntuMono-Regular.ttf") != Font::LoadResult::Success) {
        throw std::runtime_error("Can't load font.");
    }

    m_shader.set_vertex_source(vertex_shader);
    m_shader.set_fragment_source(fragment_shader);
    if (!m_renderer.load(m_shader)) {
        throw std::runtime_error("Can't load shader.");
    }

    m_renderer.set_clear_color(Color(0x2F2F2FFFU));
}

View::~View()
{}

void View::render(const DataContext& data)
{
    int offset = -500;
    for (const auto& message : data.last_callback_events()) {
        const auto text = m_font.create_text_mesh(message);
        m_renderer.load(text);

        const math::Matrix4f transform = scale(translate(math::Matrix4f(), {100, offset, 0}), {15, 15, 1});
        m_renderer.render(text, m_shader, {Uniform{"modelMatrix", transform}});

        offset += 15;
    }

    m_renderer.display();
}

void View::on_resize(framework::Size size)
{
    m_renderer.set_uniform("projectionMatrix",
                           math::ortho2d<float>(0, static_cast<float>(size.width), -static_cast<float>(size.height), 0));
    m_renderer.set_viewport(size);
}
