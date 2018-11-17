module_name = meson.current_source_dir().split('/').get(-1)

message('\tAdd module: ' + module_name)

public = files('types.hpp',
               'utils.hpp',
               'utils_details.hpp',
               'crc.hpp',
               'crc_details.hpp')

private = files('utils_details.cpp')

install_headers(public, subdir: module_name)

framework_sources += public
framework_sources += private