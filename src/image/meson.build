public = files('image.hpp')

details = files('details/format_converter.hpp',
                'details/bmp.hpp',
                'details/tga.hpp',
                'details/png.hpp')

install_headers(public, subdir: module_name)
install_headers(details, subdir: join_paths(module_name, 'details'))

framework_sources += public
framework_sources += details

