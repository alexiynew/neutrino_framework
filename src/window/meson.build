module_name = meson.current_source_dir().split('/').get(-1).split('\\').get(-1)

message('\tAdd module: ' + module_name)

public = files('window.hpp')
private = files('window.cpp')

install_headers(public, subdir: module_name)

framework_sources += public
framework_sources += private

subdir('details')
