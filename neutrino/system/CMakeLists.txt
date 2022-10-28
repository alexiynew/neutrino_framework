set_sources(PUBLIC_SOURCES
    application.hpp
    context_settings.hpp
    context.hpp
    keyboard.hpp
    mouse.hpp
    window.hpp
)

set_sources(PRIVATE_SOURCES
    src/application.cpp
    src/context_settings.cpp
    src/context.cpp
    src/keyboard.cpp
    src/platform_window_factory.hpp
    src/platform_window.cpp
    src/platform_window.hpp
    src/callbacks_holder.hpp
    src/callbacks_holder.cpp
    src/window.cpp
)

target_sources(${PROJECT_NAME}
    PUBLIC
        ${PUBLIC_SOURCES}
    PRIVATE
        ${PRIVATE_SOURCES}
)

make_install_files_target(include/${MODULE} ${PUBLIC_SOURCES})

include(${MODULE_SOURCE_DIR}/src/${PLATFORM_NAME}/CMakeLists.txt)
