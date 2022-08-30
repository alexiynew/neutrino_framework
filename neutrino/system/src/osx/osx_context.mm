#include <stdexcept>
#include <vector>

#include <graphics/src/opengl/opengl.hpp>
#include <system/src/osx/osx_autorelease_pool.hpp>
#include <system/src/osx/osx_context.hpp>

#import <mach-o/dyld.h>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"

namespace
{

int get_attribute_value(NSOpenGLPixelFormat* pixel_format, NSOpenGLPixelFormatAttribute attrib)
{
    const int screen_number = 0;
    std::int32_t value      = 0;

    [pixel_format getValues:&value forAttribute:attrib forVirtualScreen:screen_number];

    return value;
};

framework::system::ContextSettings get_actual_context_settings(NSOpenGLPixelFormat* pixel_format)
{
    using framework::system::ContextSettings;
    using framework::Version;

    if (pixel_format == nullptr) {
        return ContextSettings().version(Version(0, 0)).depth_bits(0).stencil_bits(0).samples_count(0);
    }

    const auto profile       = get_attribute_value(pixel_format, NSOpenGLPFAOpenGLProfile);
    const auto depth_bits    = get_attribute_value(pixel_format, NSOpenGLPFADepthSize);
    const auto stencil_bits  = get_attribute_value(pixel_format, NSOpenGLPFAStencilSize);
    const auto samples_count = get_attribute_value(pixel_format, NSOpenGLPFASamples);

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
    settings.samples_count(samples_count);

    return settings;
}

} // namespace

namespace framework::system::details
{

OsxContext::OsxContext(NSView* view, const ContextSettings& settings)
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
    if (settings.depth_bits() != ContextSettings::dont_care) {
        attribs.push_back(NSOpenGLPFADepthSize);
        attribs.push_back(settings.depth_bits());
    }

    // Stencil buffer size
    if (settings.stencil_bits() != ContextSettings::dont_care) {
        attribs.push_back(NSOpenGLPFAStencilSize);
        //attribs.push_back(settings.stencil_bits());
        // Implementation can't get pixel format with maximum available stencil buffer size. Need to specify size exactly.
        // Looks like any positive number returns format with maximum stencil size.
        attribs.push_back(2);
    }

    // Multisampling
    if (settings.samples_count() != ContextSettings::dont_care) {
        attribs.push_back(NSOpenGLPFAMultisample);

        // Only one buffer is currently available
        attribs.push_back(NSOpenGLPFASampleBuffers);
        attribs.push_back(1);

        // Samples count
        attribs.push_back(NSOpenGLPFASamples);
        attribs.push_back(settings.samples_count());
    }

    // End of attributes
    attribs.push_back(0);

    NSOpenGLPixelFormat* pixel_format = [[NSOpenGLPixelFormat alloc] initWithAttributes:attribs.data()];
    if (pixel_format == nullptr) {
        throw std::runtime_error("Can't get a suitable pixel format");
    }

    NSOpenGLContext* share = nullptr;

    m_context = [[NSOpenGLContext alloc] initWithFormat:pixel_format shareContext:share];
    if (m_context == nullptr) {
        throw std::runtime_error("Failed to create OpenGL context");
    }

    // 1 pixel per point framebuffer regardless of the backing scale factor for the display the view occupies.
    [m_view setWantsBestResolutionOpenGLSurface:NO];
    [m_context setView:m_view];

    framework::graphics::details::opengl::init_opengl([this](const char* f) { return get_function(f); });

    update_settings(get_actual_context_settings(pixel_format));
}

OsxContext::~OsxContext()
{
    AutoreleasePool pool;

    [m_context clearDrawable];

    if (m_context == [NSOpenGLContext currentContext]) {
        [NSOpenGLContext clearCurrentContext];
    }

    [m_context release];

    m_context = nullptr;
}

bool OsxContext::valid() const
{
    return m_context != nullptr && m_view != nullptr;
}

bool OsxContext::is_current() const
{
    AutoreleasePool pool;

    return m_context == [NSOpenGLContext currentContext];
}

Context::Api OsxContext::api_type() const
{
    return Context::Api::opengl;
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

void OsxContext::update()
{
    if (m_context) {
        [m_context update];
    }
}

OsxContext::VoidFunctionPtr OsxContext::get_function(const char* function_name) const
{
    std::string name = std::string("_") + std::string(function_name);
    NSSymbol symbol  = nullptr;
    if (NSIsSymbolNameDefined(name.c_str())) {
        symbol = NSLookupAndBindSymbol(name.c_str());
    }

    return reinterpret_cast<VoidFunctionPtr>(symbol ? NSAddressOfSymbol(symbol) : nullptr);
}


} // namespace framework::system::details

#pragma clang diagnostic pop
