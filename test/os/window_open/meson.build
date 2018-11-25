test_sources = files('main.cpp')

test = executable(test_name, test_sources,
                  include_directories: framework_include,
                  link_with: framework_lib)

test(test_name, test,
     suite: group,
     timeout: 300,
     is_parallel: false)
