public = files('image.hpp')

private = files('image.cpp',
                'details/bmp.hpp',
                'details/bmp.cpp',
                'details/tga.hpp',
                'details/tga.cpp',
                'details/png.hpp',
                'details/png.cpp')

details = files('details/image_info.hpp')

install_headers(public, subdir: module_name)
install_headers(details, subdir: join_paths(module_name, 'details'))

framework_sources += public
framework_sources += private
framework_sources += details

