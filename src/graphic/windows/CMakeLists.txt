set(PRIVATE_SOURCES
    ${CMAKE_CURRENT_LIST_DIR}/win32_window.cpp
    ${CMAKE_CURRENT_LIST_DIR}/win32_window.hpp
)

target_sources(${PROJECT_NAME} 
    PRIVATE
        ${PRIVATE_SOURCES}
)

target_compile_definitions(${PROJECT_NAME} PRIVATE UNICODE)

source_group(${MODULE_NAME} FILES ${PRIVATE_SOURCES})
