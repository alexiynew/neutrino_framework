set(PRIVATE_SOURCES
    ${CMAKE_CURRENT_LIST_DIR}/cocoa_window.hpp
    ${CMAKE_CURRENT_LIST_DIR}/cocoa_window.mm
)

target_sources(${PROJECT_NAME} 
    PRIVATE
        ${PRIVATE_SOURCES}
)

source_group(${GROUP_PATH} FILES ${PRIVATE_SOURCES})
