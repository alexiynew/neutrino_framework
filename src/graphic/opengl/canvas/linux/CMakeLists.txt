
find_package(OpenGL REQUIRED)

target_include_directories(${PROJECT_NAME} 
    PRIVATE
        ${OPENGL_INCLUDE_DIR}
)

set(PRIVATE_SOURCES
    ${CMAKE_CURRENT_LIST_DIR}/x11_opengl_canvas.cpp
    ${CMAKE_CURRENT_LIST_DIR}/x11_opengl_canvas.hpp
)

target_sources(${PROJECT_NAME} 
    PRIVATE
        ${PRIVATE_SOURCES}
)

source_group(${GROUP_PATH} FILES ${PRIVATE_SOURCES})

target_link_libraries(${PROJECT_NAME}
    PRIVATE
        GL
)
