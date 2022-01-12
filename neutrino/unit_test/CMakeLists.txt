set_sources(PUBLIC_SOURCES
    suite.hpp
)

set_sources(PRIVATE_SOURCES
    src/suite.cpp
)

target_sources(${PROJECT_NAME}
    PUBLIC
        ${PUBLIC_SOURCES}
    PRIVATE
        ${PRIVATE_SOURCES}
)

make_install_files_target(include/${MODULE_NAME} ${PUBLIC_SOURCES})
