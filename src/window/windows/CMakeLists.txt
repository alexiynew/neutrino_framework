set(PRIVATE_SOURCES
    ${CMAKE_CURRENT_LIST_DIR}/win32_window.cpp
    ${CMAKE_CURRENT_LIST_DIR}/win32_window.hpp
)

target_sources(${MODULE_NAME} 
    PRIVATE
        ${PRIVATE_SOURCES}
)

source_group(${MODULE_NAME} FILES ${PRIVATE_SOURCES})
