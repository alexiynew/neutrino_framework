/// @file
/// @brief Render.
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

#include <stdexcept>

#include <graphics/render.hpp>
#include <graphics/src/render/opengl_render.hpp>
#include <graphics/src/render/render_impl.hpp>

using namespace framework;

namespace
{
std::unique_ptr<graphics::RenderImpl> create_impl(system::Context& context)
{
    if (!context.valid()) {
        throw std::runtime_error("Context is not valid.");
    }

    switch (context.api_type()) {
        case system::Context::Api::opengl: return std::make_unique<graphics::OpenglRender>(context);
    }

    throw std::runtime_error("Unsupported graphic api.");
}

} // namespace

namespace framework::graphics
{
Render::Render(system::Context& context) : m_impl(create_impl(context))
{}

Render::Render(Render&& other) = default;

Render& Render::operator=(Render&& other) = default;

Render::~Render() = default;

void Render::set_clear_color(Color color)
{
    m_impl->set_clear_color(color);
}

void Render::display()
{
    m_impl->display();
}

} // namespace framework::graphics
