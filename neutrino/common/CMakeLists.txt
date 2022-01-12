set_sources(PUBLIC_SOURCES
    types.hpp
    utils.hpp
    crc.hpp
    version.hpp
    zlib.hpp
    inc/utils_details.hpp
    inc/crc_details.hpp
    signal.hpp
    size.hpp
    position.hpp
    instance_id.hpp
    utf.hpp
)

set_sources(PRIVATE_SOURCES
    src/version.cpp
    src/zlib.cpp
    src/size.cpp
    src/position.cpp
    src/instance_id.cpp
    src/utf.cpp
)

target_sources(${PROJECT_NAME}
    PUBLIC
        ${PUBLIC_SOURCES}
    PRIVATE
        ${PRIVATE_SOURCES}
)

make_install_files_target(include/${MODULE_NAME} ${PUBLIC_SOURCES})
