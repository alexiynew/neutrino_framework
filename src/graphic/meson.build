module_name = meson.current_source_dir().split('/').get(-1).split('\\').get(-1)

message('\tAdd module: ' + module_name)

public = files('window.hpp',
               'canvas.hpp',
               'opengl_canvas.hpp')

private = files('window.cpp',
                'opengl_canvas.cpp')

framework_sources += public
framework_sources += private

subdir('window')
