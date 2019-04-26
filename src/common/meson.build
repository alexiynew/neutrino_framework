headers = files('types.hpp',
                'color_type.hpp',
                'utils.hpp',
                'utils_details.hpp',
                'crc.hpp',
                'crc_details.hpp',
                'version.hpp')

sources = files('utils_details.cpp',
                'color_type.cpp',
                'version.cpp')

install_headers(headers, subdir: module_name)

framework_sources += headers
framework_sources += sources