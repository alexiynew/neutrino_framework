hdr = files('x11_server.hpp',
            'x11_window.hpp',
            'x11_utils.hpp')

src = files('x11_server.cpp',
            'x11_window.cpp',
            'x11_utils.cpp')

framework_sources += hdr
framework_sources += src

x11 = dependency('x11', required: true)

framework_dependencies += x11
