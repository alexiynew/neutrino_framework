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

#include <system/src/osx/osx_context.hpp>

namespace framework::system::details
{

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"

OsxContext::OsxContext(NSView* view, const ContextSettings& settings)
    : Context(settings)
    , m_view(view)
{
    auto get_profile = [](const Version& version) {
        if (version.major_version >= 4) {
            return NSOpenGLProfileVersion4_1Core;
        }

        return NSOpenGLProfileVersion3_2Core;
    };

    // clang-format off
    // TODO: Do nit apply settings if dont care
    NSOpenGLPixelFormatAttribute attribs[] =
    {
        NSOpenGLPFAAccelerated,
        NSOpenGLPFAClosestPolicy,
        NSOpenGLPFADoubleBuffer,
        NSOpenGLPFAOpenGLProfile, get_profile(settings.version()),
        NSOpenGLPFAColorSize, 24,
        NSOpenGLPFAAlphaSize, 8,
        NSOpenGLPFADepthSize, static_cast<NSOpenGLPixelFormatAttribute>(settings.depth_bits()),
        NSOpenGLPFAStencilSize, static_cast<NSOpenGLPixelFormatAttribute>(settings.stencil_bits()),
        // TODO: apply samples 
        0
    };
    // clang-format on

    NSOpenGLPixelFormat* pixelFormat = [[NSOpenGLPixelFormat alloc] initWithAttributes:attribs];
    if (pixelFormat == nullptr) {
        throw std::runtime_error("Can't get a suitable pixel format");
    }

    NSOpenGLContext* share = nil;
    m_context              = [[NSOpenGLContext alloc] initWithFormat:pixelFormat shareContext:share];
    if (m_context == nullptr) {
        throw std::runtime_error("Failed to create OpenGL context");
    }

    [m_view setWantsBestResolutionOpenGLSurface:true];
    [m_context setView:m_view];
}

OsxContext::~OsxContext()
{
    [m_context release];
    m_context = nullptr;

    [NSOpenGLContext clearCurrentContext];
}

bool OsxContext::valid() const
{
    return m_context != nullptr;
}

bool OsxContext::is_current() const
{
    NSOpenGLContext* current = [NSOpenGLContext currentContext];
    return current != nullptr && current == m_context;
}

Context::Api OsxContext::api_type() const
{
    return Context::Api::opengl;
}

Context::VoidFunctionPtr OsxContext::get_function(const char* function_name) const
{
    CFStringRef symbolName = CFStringCreateWithCString(kCFAllocatorDefault, function_name, kCFStringEncodingASCII);

    VoidFunctionPtr function = reinterpret_cast<VoidFunctionPtr>(
    CFBundleGetFunctionPointerForName(CFBundleGetBundleWithIdentifier(CFSTR("com.apple.opengl")), symbolName));
    CFRelease(symbolName);

    return function;
}

void OsxContext::make_current()
{
    if (m_context) {
        [m_context makeCurrentContext];
    }
}

void OsxContext::swap_buffers()
{
    if (m_context) {
        [m_context flushBuffer];
    }
}

#pragma clang diagnostic pop
} // namespace framework::system::details
