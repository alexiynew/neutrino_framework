hdr = files('x11_server.hpp',
            'x11_window.hpp',
            'x11_utils.hpp',
            'x11_keyboard.hpp',
            'x11_mouse.hpp')

src = files('x11_server.cpp',
            'x11_window.cpp',
            'x11_utils.cpp',
            'x11_implementation.cpp',
            'x11_keyboard.cpp',
            'x11_mouse.cpp')

framework_sources += hdr
framework_sources += src

x11 = dependency('x11', required: true)

framework_dependencies += x11
