project('framework', 'cpp', 
        version : '0.0.2', 
        license : 'MIT',
        default_options : ['cpp_std=c++17', 
                           'buildtype=release',
                           'warning_level=3',
                           'werror=true',
                           'b_pch=false'])

add_project_arguments('-Wno-unknown-pragmas', language : 'cpp')

install_prefix = '' # TODO

#TODO documentation 
#TODO test coverage
#TODO instalation

framework_source_dir = 'src'
framework_test_dir   = 'test'

thread_dependency = dependency('threads')

framework_include = include_directories(framework_source_dir)

framework_sources = []
framework_definitions = []
framework_dependencies = [thread_dependency]

system_name = build_machine.system()

subdir(framework_source_dir)

framework_lib = library(meson.project_name(), framework_sources, 
                        version : meson.project_version(),
                        include_directories : framework_include,
                        dependencies: framework_dependencies)

if get_option('build_tests')
    subdir(framework_test_dir)
endif
