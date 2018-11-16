# Docs generation target

message('Add docs generation target.')

doxygen = find_program('doxygen', required : false)
if not doxygen.found()
  warning('Doxygen not found.')
  subdir_done()
endif

source_path = join_paths(meson.source_root(), framework_source_dir)

docs_data = configuration_data()

docs_data.set('PROJECT_NAME', meson.project_name())
docs_data.set('PROJECT_VERSION', meson.project_version())
docs_data.set('DOCS_OUTPUT_DIR', docs_output_dir)
docs_data.set('FRAMEWORK_SOURCES', source_path)
docs_data.set('DOCS_SOURCE_DIR', meson.current_source_dir())
docs_data.set('FRAMEWORK_SOURCE_DIR', source_path)

doxyfile_in = 'Doxyfile.in'
doxyfile_out = 'Doxyfile'

doxyfile = configure_file(input: doxyfile_in,
                          output: doxyfile_out,
                          configuration: docs_data,
                          install: false)
