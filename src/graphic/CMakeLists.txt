get_filename_component(MODULE_NAME ${CMAKE_CURRENT_LIST_DIR} NAME)

message("\tAdd module: ${MODULE_NAME}")

set(PUBLIC_SOURCES 
    ${CMAKE_CURRENT_LIST_DIR}/window.hpp
    ${CMAKE_CURRENT_LIST_DIR}/context.hpp
)

set(PRIVATE_SOURCES
    ${CMAKE_CURRENT_LIST_DIR}/window_implementation.hpp
    ${CMAKE_CURRENT_LIST_DIR}/window.cpp

    ${CMAKE_CURRENT_LIST_DIR}/context_implementation.hpp
    ${CMAKE_CURRENT_LIST_DIR}/context.cpp
)

target_sources(${PROJECT_NAME} 
    PUBLIC
        ${PUBLIC_SOURCES}
    PRIVATE
        ${PRIVATE_SOURCES}
)

source_group(${MODULE_NAME} FILES ${PUBLIC_SOURCES} ${PRIVATE_SOURCES})

# Add platform dependent sources
include(${CMAKE_CURRENT_LIST_DIR}/${PLATFORM_NAME}/CMakeLists.txt)

