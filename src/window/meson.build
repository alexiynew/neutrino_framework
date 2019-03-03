public = files('window.hpp', 'window_size.hpp', 'window_position.hpp', 'window_callback_types.hpp')
private = files('window.cpp', 'window_size.cpp', 'window_position.cpp')

install_headers(public, subdir: module_name)

framework_sources += public
framework_sources += private

subdir('details')
