set_sources(PRIVATE_SOURCES
    glxext.cpp
    glxext.hpp
    x11_glx_context.cpp
    x11_glx_context.hpp
    x11_keyboard.cpp
    x11_keyboard.hpp
    x11_mouse.cpp
    x11_mouse.hpp
    x11_platform_window.cpp
    x11_server.cpp
    x11_server.hpp
    x11_utils.cpp
    x11_utils.hpp
    x11_window.cpp
    x11_window.hpp
)

target_sources(${PROJECT_NAME}
    PRIVATE
        ${PRIVATE_SOURCES}
)

# Link to x11
find_package(X11 REQUIRED)

target_include_directories(${PROJECT_NAME} SYSTEM PRIVATE ${X11_INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME} ${X11_LIBRARIES})
