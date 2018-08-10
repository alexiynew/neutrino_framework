set(PRIVATE_SOURCES
    ${CMAKE_CURRENT_LIST_DIR}/x11_server.cpp
    ${CMAKE_CURRENT_LIST_DIR}/x11_server.hpp
    ${CMAKE_CURRENT_LIST_DIR}/x11_utils.cpp
    ${CMAKE_CURRENT_LIST_DIR}/x11_utils.hpp
    ${CMAKE_CURRENT_LIST_DIR}/x11_window.cpp
    ${CMAKE_CURRENT_LIST_DIR}/x11_window.hpp
)

target_sources(${PROJECT_NAME} 
    PRIVATE
        ${PRIVATE_SOURCES}
)

source_group(${GROUP_PATH} FILES ${PRIVATE_SOURCES})

target_link_libraries(${PROJECT_NAME}
    PRIVATE
        X11
)
