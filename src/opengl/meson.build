headers = files('gl.hpp',
                'shader.hpp',
                'texture.hpp',
                'mesh.hpp',
                'context.hpp',
                'context_settings.hpp')

sources = files('gl.cpp',
                'shader.cpp',
                'texture.cpp',
                'mesh.cpp',
                'context.cpp',
                'context_settings.cpp')

install_headers(headers, subdir: module_name)
install_headers(files(join_paths(meson.source_root(), 'dependencies', 'GL', 'glcorearb.h')), subdir: 'GL')
install_headers(files(join_paths(meson.source_root(), 'dependencies', 'KHR', 'khrplatform.h')), subdir: 'KHR')

framework_sources += headers
framework_sources += sources

gl = dependency('GL', required: true)

framework_dependencies += gl

subdir('details')
