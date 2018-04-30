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

add_library(${MODULE_NAME} OBJECT EXCLUDE_FROM_ALL "")

target_sources(${MODULE_NAME} 
    PUBLIC
        ${PUBLIC_SOURCES}
    PRIVATE
        ${PRIVATE_SOURCES}
)

add_dependencies(${PROJECT_NAME} ${MODULE_NAME})

set_target_properties(${MODULE_NAME} PROPERTIES FOLDER ${SOURCE_FOLDER_NAME})
target_include_directories(${MODULE_NAME} PRIVATE ${FRAMEWORK_SOURCE_DIR})

source_group(${MODULE_NAME} FILES ${PUBLIC_SOURCES} ${PRIVATE_SOURCES})
