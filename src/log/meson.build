module_name = meson.current_source_dir().split('/').get(-1)

message('\tAdd module: ' + module_name)

public = files('log.hpp',
               'logger.hpp',
               'stream_logger.hpp')

private = files('log.cpp',
                'log_details.cpp',
                'log_details.hpp',
                'stream_logger.cpp')

framework_sources += public
framework_sources += private
