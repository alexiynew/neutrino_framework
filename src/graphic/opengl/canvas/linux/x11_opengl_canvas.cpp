/// @file
/// @brief OpneGL canvas implementation.
/// @author Fedorov Alexey
/// @date 02.06.2018

#include <GL/glx.h>

#include <graphic/opengl/canvas/linux/x11_opengl_canvas.hpp>
#include <graphic/window/linux/x11_server.hpp>

//#define GLX_CONTEXT_MAJOR_VERSION_ARB 0x2091
//#define GLX_CONTEXT_MINOR_VERSION_ARB 0x2092
// typedef GLXContext (*glXCreateContextAttribsARBProc)(Display*, GLXFBConfig, GLXContext, Bool, const int*);

// Helper to check for extension string presence.  Adapted from:
//   http://www.opengl.org/resources/features/OGLextensions/
// static bool isExtensionSupported(const char* extList, const char* extension)
//{
//    const char* start;
//    const char *where, *terminator;
//
//    /* Extension names should not have spaces. */
//    where = strchr(extension, ' ');
//    if (where || *extension == '\0')
//        return false;
//
//    /* It takes a bit of care to be fool-proof about parsing the
//       OpenGL extensions string. Don't be fooled by sub-strings,
//       etc. */
//    for (start = extList;;) {
//        where = strstr(start, extension);
//
//        if (!where)
//            break;
//
//        terminator = where + strlen(extension);
//
//        if (where == start || *(where - 1) == ' ')
//            if (*terminator == ' ' || *terminator == '\0')
//                return true;
//
//        start = terminator;
//    }
//
//    return false;
//}

namespace
{
using namespace framework;

void check_glx_version(Display* display)
{
    int32 glx_major = 0;
    int32 glx_minor = 0;

    glXQueryVersion(display, &glx_major, &glx_minor);

    if (((glx_major == 1) && (glx_minor < 4)) || (glx_major < 1)) {
        throw std::runtime_error("Wrong GLX version.");
    }
}

GLXFBConfig choose_framebuffer_config(Display* display)
{
    // clang-format off
    static int32 visual_attribs[] = {
        GLX_X_RENDERABLE,  True,
        GLX_DRAWABLE_TYPE, GLX_WINDOW_BIT,
        GLX_RENDER_TYPE,   GLX_RGBA_BIT,
        GLX_X_VISUAL_TYPE, GLX_TRUE_COLOR,
        GLX_RED_SIZE,      8,
        GLX_GREEN_SIZE,    8,
        GLX_BLUE_SIZE,     8,
        GLX_ALPHA_SIZE,    8,
        GLX_DEPTH_SIZE,    24,
        GLX_STENCIL_SIZE,  8,
        GLX_DOUBLEBUFFER,  True,
        None};
    // clang-format on

    int32 count;
    GLXFBConfig* configs = glXChooseFBConfig(display, DefaultScreen(display), visual_attribs, &count);
    if (!configs) {
        throw std::runtime_error("Can't get framebuffer config.");
    }

    int32 best               = -1;
    int32 best_samples_count = -1;

    for (int32 i = 0; i < count; ++i) {
        int32 sample_buffer;
        int32 samples;
        glXGetFBConfigAttrib(display, configs[i], GLX_SAMPLE_BUFFERS, &sample_buffer);
        glXGetFBConfigAttrib(display, configs[i], GLX_SAMPLES, &samples);

        if (best < 0 || (sample_buffer && samples > best_samples_count)) {
            best               = i;
            best_samples_count = samples;
        }
    }

    GLXFBConfig best_config = configs[best];

    XFree(configs);

    return best_config;
}

void set_colormap(Display* display, Window& window)
{
    GLXFBConfig framebuffer_config = choose_framebuffer_config(display);
    XVisualInfo* visual_info       = glXGetVisualFromFBConfig(display, framebuffer_config);

    if (!visual_info) {
        throw std::runtime_error("Can't get visual info for framebuffer config.");
    }

    Colormap colormap = XCreateColormap(display, window, visual_info->visual, AllocNone);
    XSetWindowColormap(display, window, colormap);

    XFree(visual_info);
}

} // namespace

namespace framework
{
namespace graphic
{
std::unique_ptr<opengl_canvas::implementation> opengl_canvas::implementation::create(
const ::framework::graphic::window& window)
{
    Display* display      = x11_server::connect()->display();
    Window window_handler = static_cast<Window>(window.native_handler());

    return std::make_unique<x11_opengl_canvas>(display, window_handler);
}

x11_opengl_canvas::x11_opengl_canvas(Display* display, const Window& window) : m_display(display), m_window(window)
{
    check_glx_version(m_display);

    set_colormap(m_display, m_window);

    // init gl
    /*
        // Get the default screen's GLX extension list
        const char* glxExts = glXQueryExtensionsString(display, DefaultScreen(display));

        // NOTE: It is not necessary to create or make current to a context before
        // calling glXGetProcAddressARB
        glXCreateContextAttribsARBProc glXCreateContextAttribsARB = 0;
        glXCreateContextAttribsARB                                =
       (glXCreateContextAttribsARBProc)glXGetProcAddressARB( (const GLubyte*)"glXCreateContextAttribsARB");

        GLXContext ctx = 0;

        // Check for the GLX_ARB_create_context extension string and the function.
        // If either is not present, use GLX 1.3 context creation method.
        if (!isExtensionSupported(glxExts, "GLX_ARB_create_context") || !glXCreateContextAttribsARB) {
            printf("glXCreateContextAttribsARB() not found"
                   " ... using old-style GLX context\n");
            ctx = glXCreateNewContext(display, bestFbc, GLX_RGBA_TYPE, 0, True);
        }

        // If it does, try to get a GL 3.0 context!
        else {
            int context_attribs[] = {GLX_CONTEXT_MAJOR_VERSION_ARB,
                                     3,
                                     GLX_CONTEXT_MINOR_VERSION_ARB,
                                     0,
                                     // GLX_CONTEXT_FLAGS_ARB        , GLX_CONTEXT_FORWARD_COMPATIBLE_BIT_ARB,
                                     None};

            printf("Creating context\n");
            ctx = glXCreateContextAttribsARB(display, bestFbc, 0, True, context_attribs);

            // Sync to ensure any errors generated are processed.
            XSync(display, False);
            if (!ctxErrorOccurred && ctx)
                printf("Created GL 3.0 context\n");
            else {
                // Couldn't create GL 3.0 context.  Fall back to old-style 2.x context.
                // When a context version below 3.0 is requested, implementations will
                // return the newest context version compatible with OpenGL versions less
                // than version 3.0.
                // GLX_CONTEXT_MAJOR_VERSION_ARB = 1
                context_attribs[1] = 1;
                // GLX_CONTEXT_MINOR_VERSION_ARB = 0
                context_attribs[3] = 0;

                ctxErrorOccurred = false;

                printf("Failed to create GL 3.0 context"
                       " ... using old-style GLX context\n");
                ctx = glXCreateContextAttribsARB(display, bestFbc, 0, True, context_attribs);
            }
        }

        // Sync to ensure any errors generated are processed.
        XSync(display, False);

        // Verifying that context is a direct context
        if (!glXIsDirect(display, ctx)) {
            printf("Indirect GLX rendering context obtained\n");
        } else {
            printf("Direct GLX rendering context obtained\n");
        }

        printf("Making context current\n");
        glXMakeCurrent(display, win, ctx);

        glClearColor(0, 0.5, 1, 1);
        glClear(GL_COLOR_BUFFER_BIT);
        glXSwapBuffers(display, win);

        sleep(1);

        glClearColor(1, 0.5, 0, 1);
        glClear(GL_COLOR_BUFFER_BIT);
        glXSwapBuffers(display, win);

        sleep(1);

        glXDestroyContext(display, ctx);

        XDestroyWindow(display, win);
        XFreeColormap(display, cmap);
        XCloseDisplay(display);
    */
}

x11_opengl_canvas::~x11_opengl_canvas() = default;

void x11_opengl_canvas::make_current()
{
    //   glXMakeCurrent(m_display, m_window, m_context);
}

void x11_opengl_canvas::swap_buffers()
{}

} // namespace graphic

} // namespace framework
