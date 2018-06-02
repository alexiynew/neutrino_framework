set(PRIVATE_SOURCES
    ${CMAKE_CURRENT_LIST_DIR}/opengl_canvas.cpp
)

target_sources(${PROJECT_NAME} 
    PRIVATE
        ${PRIVATE_SOURCES}
)

source_group(${GROUP_PATH} FILES ${PRIVATE_SOURCES})

target_link_libraries(${PROJECT_NAME}
    PRIVATE
         # TODO add library
)
