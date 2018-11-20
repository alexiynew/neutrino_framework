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
                           'default_library=static'])

required_versions = {
    'gcc': '7.3.0',
    'clang': '6.0.1'
}

compiler = meson.get_compiler('cpp')
required_compiler_version = required_versions[compiler.get_id()]


if compiler.version() < required_compiler_version
    error(compiler.get_id() + ' ' + required_compiler_version + ' or higher required.')
endif


if compiler.get_id() == 'gcc' or compiler.get_id() == 'clang'
    add_project_arguments('-Wno-unknown-pragmas', language : 'cpp')
elif compiler.get_id() == 'msvc'
    add_project_arguments('/std:c++17', language : 'cpp')
endif

framework_source_dir = 'src'
framework_test_dir   = 'test'

docs_source_dir  = 'docs'
docs_output_dir  = 'docs'

thread_dependency = dependency('threads')

framework_include = include_directories(framework_source_dir, 'dependencies')

framework_sources = []
framework_definitions = []
framework_dependencies = [thread_dependency]

system_name = build_machine.system()

if (system_name == 'windows')
    framework_definitions += '-DUNICODE'
endif

# Add sources
subdir(framework_source_dir)

framework_lib = library(meson.project_name(), framework_sources,
                        version : meson.project_version(),
                        include_directories : framework_include,
                        dependencies: framework_dependencies,
                        cpp_args : framework_definitions,
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

clang_format = find_program('clang-format', 'clang-format.exe',  'clang-format.py')

if clang_format.found()
    message(run_command(clang_format, '--version').stdout())
    run_target('format',
               command : [clang_format, '-style=file', '-i', framework_sources])
endif