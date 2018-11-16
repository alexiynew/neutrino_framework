test_name = meson.current_source_dir().split('/').get(-1)

test_sources = files('main.cpp')

test = executable(test_name, test_sources, 
                  include_directories: framework_include,
                  link_with: framework_lib,
                  dependencies: thread_dependency)

test(test_name, test, 
     suite: test_pack_name,
     timeout: 60)
