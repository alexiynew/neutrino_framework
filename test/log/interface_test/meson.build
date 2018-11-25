test_sources = files('main.cpp')

test = executable(test_name, test_sources,
                  include_directories: framework_include,
                  link_with: framework_lib,
                  dependencies: thread_dependency)

test(test_name, test,
     suite: group,
     timeout: 60)
