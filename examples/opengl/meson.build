name = meson.current_source_dir().split('/').get(-1).split('\\').get(-1)

sources = files('main.cpp')

executable(name, sources,
           include_directories: framework_include,
           link_with: framework_lib)