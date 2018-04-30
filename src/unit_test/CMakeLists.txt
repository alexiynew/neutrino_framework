get_filename_component(MODULE_NAME ${CMAKE_CURRENT_LIST_DIR} NAME)

message("\tAdd module: ${MODULE_NAME}")

set(PUBLIC_SOURCES 
    ${CMAKE_CURRENT_LIST_DIR}/suite.hpp
)

set(PRIVATE_SOURCES
    ${CMAKE_CURRENT_LIST_DIR}/suite.cpp
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
