get_filename_component(MODULE_NAME ${CMAKE_CURRENT_LIST_DIR} NAME)

set(GROUP_PATH ${MODULE_NAME})

message("\tAdd module: ${MODULE_NAME}")

set(PUBLIC_SOURCES 
    ${CMAKE_CURRENT_LIST_DIR}/window.hpp
    ${CMAKE_CURRENT_LIST_DIR}/renderer.hpp
    ${CMAKE_CURRENT_LIST_DIR}/canvas_base.hpp
)

set(PRIVATE_SOURCES
    ${CMAKE_CURRENT_LIST_DIR}/window.cpp
    ${CMAKE_CURRENT_LIST_DIR}/renderer.cpp
)

target_sources(${PROJECT_NAME} 
    PUBLIC
        ${PUBLIC_SOURCES}
    PRIVATE
        ${PRIVATE_SOURCES}
)

source_group(${GROUP_PATH} FILES ${PUBLIC_SOURCES} ${PRIVATE_SOURCES})

include(${CMAKE_CURRENT_LIST_DIR}/window/CMakeLists.txt)
include(${CMAKE_CURRENT_LIST_DIR}/opengl/CMakeLists.txt)

