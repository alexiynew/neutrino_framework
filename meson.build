# Project setup
project('framework', 'cpp', 
        version : '0.0.2', 
        license : 'MIT',
        default_options : ['cpp_std=c++17', 
                           'buildtype=release',
                           'warning_level=3',
                           'werror=true',
                           'b_pch=false',
                           'prefix=' + join_paths(meson.source_root(), 'output'),
                           'default_library=both'])

add_project_arguments('-Wno-unknown-pragmas', language : 'cpp')

framework_source_dir = 'src'
framework_test_dir   = 'test'

docs_source_dir  = 'docs'
docs_output_dir  = 'docs'
docs_install_dir = docs_output_dir

thread_dependency = dependency('threads')

framework_include = include_directories(framework_source_dir)

framework_sources = []
framework_definitions = []
framework_dependencies = [thread_dependency]

system_name = build_machine.system()

# Add sources
subdir(framework_source_dir)

framework_lib = library(meson.project_name(), framework_sources, 
                        version : meson.project_version(),
                        include_directories : framework_include,
                        dependencies: framework_dependencies,
                        install: true)

# Add tests
if get_option('build_tests')
    subdir(framework_test_dir)
endif

# Docs
if get_option('build_docs')
    subdir(docs_source_dir)
    if is_variable('doxygen') and is_variable('doxyfile')
        custom_target('docs',
                      input: doxyfile,
                      output: docs_output_dir,
                      command: [doxygen, doxyfile])
    endif
endif
