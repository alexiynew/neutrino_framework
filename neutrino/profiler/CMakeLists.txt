set_sources(PUBLIC_SOURCES
    profiler.hpp
)

set_sources(PRIVATE_SOURCES
    src/profiler.cpp
)

target_sources(${PROJECT_NAME}
    PUBLIC
        ${PUBLIC_SOURCES}
    PRIVATE
        ${PRIVATE_SOURCES}
)

make_install_files_target(include/${MODULE} ${PUBLIC_SOURCES})
