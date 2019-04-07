test_sources = files('main.cpp')

test = executable(test_name, test_sources,
                  include_directories: framework_include,
                  link_with: framework_lib)

configure_file(input:'rgb.bmp', output:'rgb.bmp', copy: true)
configure_file(input:'256colors.bmp', output:'256colors.bmp', copy: true)
configure_file(input:'16colors.bmp', output:'16colors.bmp', copy: true)
configure_file(input:'mono.bmp', output:'mono.bmp', copy: true)

test(test_name, test,
     suite: group,
     timeout: 60)
