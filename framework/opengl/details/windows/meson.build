headers = files('wgl_context.hpp',
                'wglext_wrapper.hpp',
                'wglext.hpp')

sources = files('gl_details.cpp',
                'wgl_context.cpp',
                'wglext_wrapper.cpp',
                'wglext.cpp')

framework_sources += headers
framework_sources += sources

gdi32_lib = compiler.find_library('Gdi32')
gdi32 = declare_dependency(dependencies: gdi32_lib)

framework_dependencies += gdi32