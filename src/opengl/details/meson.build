subdir_name = meson.current_source_dir().split('/').get(-1).split('\\').get(-1)

public = files('gl_wrapper.hpp')

headers = files('gl_details.hpp')

sources = files('gl_wrapper.cpp')

install_headers(public, subdir: join_paths(module_name, subdir_name))

framework_sources += public
framework_sources += headers
framework_sources += sources

subdir(system_name)
