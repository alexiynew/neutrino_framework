set(PRIVATE_SOURCES
    ${CMAKE_CURRENT_LIST_DIR}/cocoa_window.hpp
    ${CMAKE_CURRENT_LIST_DIR}/cocoa_window.mm
)

target_sources(${MODULE_NAME} 
    PRIVATE
        ${PRIVATE_SOURCES}
)

source_group(${MODULE_NAME} FILES ${PRIVATE_SOURCES})
