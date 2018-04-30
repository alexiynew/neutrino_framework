get_filename_component(MODULE_NAME ${CMAKE_CURRENT_LIST_DIR} NAME)

message("\tAdd module: ${MODULE_NAME}")

set(PUBLIC_SOURCES 
    ${CMAKE_CURRENT_LIST_DIR}/types.hpp
    ${CMAKE_CURRENT_LIST_DIR}/utils.hpp
)

target_sources(${PROJECT_NAME} 
    PUBLIC 
        ${PUBLIC_SOURCES}
)

source_group(${MODULE_NAME} FILES ${PUBLIC_SOURCES} ${PRIVATE_SOURCES})
