// =============================================================================
// MIT License
//
// Copyright (c) 2017-2021 Fedorov Alexey
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
#include <vector>

#include <system/src/osx/osx_autorelease_pool.hpp>
#include <system/src/osx/osx_context.hpp>

#include <dlfcn.h>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"

namespace
{

NSOpenGLPixelFormatAttribute get_attribute(NSOpenGLPixelFormat* pixel_format, NSOpenGLPixelFormatAttribute attrib)
{
    const int screen_number = 0;
    std::int32_t value      = 0;

    [pixel_format getValues:&value forAttribute:attrib forVirtualScreen:screen_number];

    return static_cast<NSOpenGLPixelFormatAttribute>(value);
};

framework::system::ContextSettings get_actual_context_settings(NSOpenGLPixelFormat* pixel_format)
{
    using framework::system::ContextSettings;
    using framework::Version;

    if (pixel_format == nullptr) {
        return ContextSettings()
        .version(Version(0, 0))
        .depth_bits(0)
        .stencil_bits(0)
        .antialiasing_level(ContextSettings::Antialiasing::dont_care);
    }

    const auto profile       = get_attribute(pixel_format, NSOpenGLPFAOpenGLProfile);
    const auto depth_bits    = get_attribute(pixel_format, NSOpenGLPFADepthSize);
    const auto stencil_bits  = get_attribute(pixel_format, NSOpenGLPFAStencilSize);
    const auto samples_count = get_attribute(pixel_format, NSOpenGLPFASamples);

    ContextSettings settings;
    if (profile == NSOpenGLProfileVersion3_2Core) {
        settings.version(Version(3, 2));
    } else if (profile == NSOpenGLProfileVersion4_1Core) {
        settings.version(Version(4, 1));
    } else {
        settings.version(Version(0, 0));
    }

    settings.depth_bits(depth_bits);
    settings.stencil_bits(stencil_bits);

    if (samples_count != 0) {
        settings.antialiasing_level(ContextSettings::Antialiasing::best);
    } else {
        settings.antialiasing_level(ContextSettings::Antialiasing::dont_care);
    }

    return settings;
}

} // namespace

namespace framework::system::details
{

OSXContext::OSXContext(NSView* view, const ContextSettings& settings)
    : Context(settings)
    , m_view(view)
{
    AutoreleasePool pool;

    auto get_profile = [](const Version& version) {
        if (version > Version(3, 2)) {
            return NSOpenGLProfileVersion4_1Core;
        }

        return NSOpenGLProfileVersion3_2Core;
    };

    std::vector<NSOpenGLPixelFormatAttribute> attribs;
    attribs.push_back(NSOpenGLPFAAccelerated);
    attribs.push_back(NSOpenGLPFAClosestPolicy);
    attribs.push_back(NSOpenGLPFADoubleBuffer);

    // Profile
    attribs.push_back(NSOpenGLPFAOpenGLProfile);
    attribs.push_back(get_profile(settings.version()));

    // Color
    attribs.push_back(NSOpenGLPFAColorSize);
    attribs.push_back(24);
    attribs.push_back(NSOpenGLPFAAlphaSize);
    attribs.push_back(8);

    // Depth buffer size
    attribs.push_back(NSOpenGLPFADepthSize);
    attribs.push_back(settings.depth_bits());

    // Stencil buffer size
    attribs.push_back(NSOpenGLPFAStencilSize);
    attribs.push_back(settings.stencil_bits());

    // Antialiasing
    if (settings.antialiasing_level() == ContextSettings::Antialiasing::best) {
        attribs.push_back(NSOpenGLPFAMultisample);

        // Only one buffer is currently available
        attribs.push_back(NSOpenGLPFASampleBuffers);
        attribs.push_back(1);

        // Antialiasing level
        attribs.push_back(NSOpenGLPFASamples);
        attribs.push_back(32);
    }

    // End of attributes
    attribs.push_back(0);

    NSOpenGLPixelFormat* pixel_format = [[NSOpenGLPixelFormat alloc] initWithAttributes:attribs.data()];
    if (pixel_format == nullptr) {
        throw std::runtime_error("Can't get a suitable pixel format");
    }

    update_settings(get_actual_context_settings(pixel_format));

    NSOpenGLContext* share = nullptr;

    m_context = [[NSOpenGLContext alloc] initWithFormat:pixel_format shareContext:share];
    if (m_context == nullptr) {
        throw std::runtime_error("Failed to create OpenGL context");
    }

    [m_view setWantsBestResolutionOpenGLSurface:true];
    [m_context setView:m_view];
}

OSXContext::~OSXContext()
{
    AutoreleasePool pool;

    [m_context clearDrawable];

    if (m_context == [NSOpenGLContext currentContext]) {
        [NSOpenGLContext clearCurrentContext];
    }

    [m_context release];

    m_context = nullptr;
}

bool OSXContext::valid() const
{
    return m_context != nullptr && m_view != nullptr;
}

bool OSXContext::is_current() const
{
    AutoreleasePool pool;

    return m_context == [NSOpenGLContext currentContext];
}

Context::Api OSXContext::api_type() const
{
    return Context::Api::opengl;
}

Context::VoidFunctionPtr OSXContext::get_function(const char* function_name) const
{
    static void* gl_lib = nullptr;

    if (!gl_lib) {
        gl_lib = dlopen("/System/Library/Frameworks/OpenGL.framework/Versions/Current/OpenGL", RTLD_LAZY);
    }

    return (gl_lib ? reinterpret_cast<VoidFunctionPtr>(reinterpret_cast<intptr_t>(dlsym(gl_lib, function_name))) :
                     nullptr);
}

void OSXContext::make_current()
{
    if (m_context) {
        [m_context makeCurrentContext];
    }
}

void OSXContext::swap_buffers()
{
    if (m_context) {
        [m_context flushBuffer];
    }
}

void OSXContext::update()
{
    if (m_context) {
        [m_context update];
    }
}

} // namespace framework::system::details

#pragma clang diagnostic pop
