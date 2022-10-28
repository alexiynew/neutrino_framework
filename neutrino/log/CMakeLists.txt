set_sources(PUBLIC_SOURCES
    log.hpp
    logger.hpp
    stream_logger.hpp

    inc/log_stream.hpp
)

set_sources(PRIVATE_SOURCES
    src/log_stream.cpp
    src/log.cpp
    src/stream_logger.cpp
)

target_sources(${PROJECT_NAME}
    PUBLIC
        ${PUBLIC_SOURCES}
    PRIVATE
        ${PRIVATE_SOURCES}
)

make_install_files_target(include/${MODULE} ${PUBLIC_SOURCES})
