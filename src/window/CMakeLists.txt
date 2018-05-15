get_filename_component(MODULE_NAME ${CMAKE_CURRENT_LIST_DIR} NAME)

message("\tAdd module: ${MODULE_NAME}")

set(PUBLIC_SOURCES 
    ${CMAKE_CURRENT_LIST_DIR}/window.hpp
)

set(PRIVATE_SOURCES
    ${CMAKE_CURRENT_LIST_DIR}/implementation.hpp
    ${CMAKE_CURRENT_LIST_DIR}/window.cpp
)

target_sources(${PROJECT_NAME} 
    PUBLIC
        ${PUBLIC_SOURCES}
    PRIVATE
        ${PRIVATE_SOURCES}
)

source_group(${MODULE_NAME} FILES ${PUBLIC_SOURCES} ${PRIVATE_SOURCES})

# Add platform dependent sources and libraries
include(${CMAKE_CURRENT_LIST_DIR}/${PLATFORM_NAME}/CMakeLists.txt)
