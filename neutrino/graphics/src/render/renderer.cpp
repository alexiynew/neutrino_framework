/// @file
/// @brief Renderer.
/// @author Fedorov Alexey
/// @date 29.03.2020

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

#include <cassert>
#include <stdexcept>

#include <graphics/color.hpp>
#include <graphics/mesh.hpp>
#include <graphics/renderer.hpp>
#include <graphics/shader.hpp>
#include <graphics/texture.hpp>

#include <graphics/src/render/opengl/opengl_renderer.hpp>
#include <graphics/src/render/render_command.hpp>
#include <graphics/src/render/renderer_impl.hpp>

using namespace framework;
using namespace framework::graphics;

namespace
{
std::unique_ptr<RendererImpl> create_impl(system::Context& context)
{
    if (!context.valid()) {
        throw std::runtime_error("Context is not valid.");
    }
    context.make_current();

    switch (context.api_type()) {
        case system::Context::Api::opengl: return std::make_unique<OpenglRenderer>(context);
    }

    throw std::runtime_error("Unsupported graphic api.");
}

MatrixCache clear_matrix_cache(const MatrixCache& cache)
{
    return MatrixCache{cache.back()};
}

TextureIds get_texture_ids(const Renderer::TexturesList& textures)
{
    TextureIds ids;
    for (const auto& texture_ref : textures) {
        ids.push_back(texture_ref.get().instance_id());
    }

    return ids;
}

} // namespace

namespace framework::graphics
{
Renderer::Renderer(system::Window& window)
    : m_impl(create_impl(window.context()))
    , m_window(std::ref(window))
{
    set_view(math::Matrix4f{});
    set_projection(math::Matrix4f{});
    m_on_resize_slot_id = m_window.get().on_resize.connect(
    [this](const system::Window&, Size size) { m_impl->set_viewport(size); });
}

Renderer::Renderer(Renderer&& other) noexcept = default;

Renderer& Renderer::operator=(Renderer&& other) noexcept = default;

Renderer::~Renderer() = default;

void Renderer::set_clear_color(const Color& color)
{
    m_window.get().context().make_current();
    m_impl->set_clear_color(color);
}

void Renderer::set_projection(const math::Matrix4f& projection)
{
    m_projection.push_back(projection);
}

void Renderer::set_view(const math::Matrix4f& view)
{
    m_view.push_back(view);
}

bool Renderer::load(const Mesh& mesh)
{
    m_window.get().context().make_current();
    return m_impl->load(mesh);
}

bool Renderer::load(const Shader& shader)
{
    m_window.get().context().make_current();
    return m_impl->load(shader);
}

bool Renderer::load(const Texture& texture)
{
    m_window.get().context().make_current();
    return m_impl->load(texture);
}

bool Renderer::load(const TexturesList& textures)
{
    bool loaded = true;
    for (const auto& texture : textures) {
        loaded &= load(texture);
    }

    return loaded;
}

void Renderer::render(const Mesh& mesh, const Shader& shader)
{
    render(mesh, shader, {}, math::Matrix4f{});
}

void Renderer::render(const Mesh& mesh, const Shader& shader, const TexturesList& textures)
{
    render(mesh, shader, textures, math::Matrix4f{});
}

void Renderer::render(const Mesh& mesh, const Shader& shader, const math::Matrix4f& model_transform)
{
    render(mesh, shader, {}, model_transform);
}

void Renderer::render(const Mesh& mesh,
                      const Shader& shader,
                      const TexturesList& textures,
                      const math::Matrix4f& model_transform)
{
    Uniforms uniforms      = get_uniforms(model_transform);
    TextureIds texture_ids = get_texture_ids(textures);
    m_render_commands.emplace_back(mesh.instance_id(), shader.instance_id(), texture_ids, uniforms);
}

Uniforms Renderer::get_uniforms(const math::Matrix4f& model_transform) const
{
    assert(!m_view.empty());
    assert(!m_projection.empty());

    CachedMatrix view{m_view, m_view.size() - 1};
    CachedMatrix projection{m_projection, m_projection.size() - 1};

    return Uniforms{model_transform, view, projection};
}

void Renderer::display()
{
    m_window.get().context().make_current();

    start_frame();

    for (const auto& command : m_render_commands) {
        m_impl->render(command);
    }

    end_frame();

    m_window.get().context().swap_buffers();
}

void Renderer::start_frame()
{
    m_impl->start_frame();
}

void Renderer::end_frame()
{
    m_render_commands.clear();

    // delete all cached matrices exept last one
    m_view       = clear_matrix_cache(m_view);
    m_projection = clear_matrix_cache(m_projection);

    m_impl->end_frame();
}

} // namespace framework::graphics
