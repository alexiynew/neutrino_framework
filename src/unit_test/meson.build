module_name = meson.current_source_dir().split('/').get(-1)

message('\tAdd module: ' + module_name)

public = files('suite.hpp')
private = files('suite.cpp')


framework_sources += public
framework_sources += private

