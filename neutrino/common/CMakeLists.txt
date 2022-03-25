set_sources(PUBLIC_SOURCES
    crc.hpp
    exceptions.hpp
    instance_id.hpp
    position.hpp
    signal.hpp
    size.hpp
    types.hpp
    utf.hpp
    utils.hpp
    version.hpp
    zlib.hpp
    
    inc/crc_details.hpp
    inc/utils_details.hpp
)

set_sources(PRIVATE_SOURCES
    src/instance_id.cpp
    src/position.cpp
    src/size.cpp
    src/utf.cpp
    src/version.cpp
    src/zlib.cpp
)

target_sources(${PROJECT_NAME}
    PUBLIC
        ${PUBLIC_SOURCES}
    PRIVATE
        ${PRIVATE_SOURCES}
)

make_install_files_target(include/${MODULE_NAME} ${PUBLIC_SOURCES})
