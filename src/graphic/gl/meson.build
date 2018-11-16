private = files('gl.hpp',
                'gl.cpp',
                'gl_core.hpp',
                'gl_core.cpp',
                'gl_utils.hpp')

framework_sources += private

gl = dependency('GL', required: true)

framework_dependencies += gl

subdir(system_name)
