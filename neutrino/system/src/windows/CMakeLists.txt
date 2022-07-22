set_sources(PRIVATE_SOURCES
    wglext.cpp
    wglext.hpp
    win32_application.cpp
    win32_application.hpp
    win32_keyboard.cpp
    win32_keyboard.hpp
    win32_platform_window.cpp
    win32_wgl_context.cpp
    win32_wgl_context.hpp
    win32_window.cpp
    win32_window.hpp
)

target_sources(${PROJECT_NAME}
    PRIVATE
        ${PRIVATE_SOURCES}
)

# Link with OpenGL
find_package(OpenGL REQUIRED)

target_link_libraries(${PROJECT_NAME} PRIVATE ${OPENGL_LIBRARIES})

