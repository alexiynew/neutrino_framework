get_filename_component(MODULE_NAME ${CMAKE_CURRENT_LIST_DIR} NAME)

message("\tAdd module: ${MODULE_NAME}")

set(PUBLIC_SOURCES 
    ${CMAKE_CURRENT_LIST_DIR}/log.hpp
    ${CMAKE_CURRENT_LIST_DIR}/stream_logger.hpp
)

set(PRIVATE_SOURCES
    ${CMAKE_CURRENT_LIST_DIR}/log.cpp
    ${CMAKE_CURRENT_LIST_DIR}/log_details.cpp
    ${CMAKE_CURRENT_LIST_DIR}/log_details.hpp

    ${CMAKE_CURRENT_LIST_DIR}/stream_logger.cpp
)

target_sources(${PROJECT_NAME} 
    PUBLIC
        ${PUBLIC_SOURCES}
    PRIVATE
        ${PRIVATE_SOURCES}
)

source_group(${MODULE_NAME} FILES ${PUBLIC_SOURCES} ${PRIVATE_SOURCES})
