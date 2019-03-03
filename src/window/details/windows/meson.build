hdr = files('win32_window.hpp',
            'win32_application.hpp')

src = files('win32_window.cpp',
            'win32_application.cpp',
            'win32_implementation.cpp')

framework_sources += hdr
framework_sources += src

user32_lib = compiler.find_library('user32')
user32 = declare_dependency(dependencies: user32_lib)

framework_dependencies += user32
