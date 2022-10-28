set_sources(PRIVATE_SOURCES
    glxext.cpp
    glxext.hpp
    x11_types.hpp
    x11_glx_get_function.cpp
    x11_glx_get_function.hpp
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

# Find x11
find_package(X11 REQUIRED)

# Check for XInput extension
if (NOT X11_Xi_INCLUDE_PATH)
    message(FATAL_ERROR "The XInput headers were not found")
endif()

 # Check for Xkb (X keyboard extension)
if (NOT X11_Xkb_INCLUDE_PATH)
    message(FATAL_ERROR "The X keyboard extension headers were not found")
endif()

target_include_directories(${PROJECT_NAME} SYSTEM PRIVATE ${X11_INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME} PRIVATE ${X11_LIBRARIES} ${X11_Xi_LIB})
