set_sources(PUBLIC_SOURCES
    keyboard.hpp
    mouse.hpp
    window.hpp
    context_settings.hpp
    context.hpp
)

set_sources(PRIVATE_SOURCES
    src/keyboard.cpp
    src/window.cpp
    src/context_settings.cpp
    src/context.cpp
    src/platform_window.hpp
    src/platform_window.cpp
)

target_sources(${PROJECT_NAME}
    PUBLIC
        ${PUBLIC_SOURCES}
    PRIVATE
        ${PRIVATE_SOURCES}
)

make_install_files_target(include/${MODULE_NAME} ${PUBLIC_SOURCES})

include(${MODULE_DIR}/src/${PLATFORM_NAME}/CMakeLists.txt)
