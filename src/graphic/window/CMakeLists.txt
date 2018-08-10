get_filename_component(DIR_NAME ${CMAKE_CURRENT_LIST_DIR} NAME)

set(GROUP_PATH ${GROUP_PATH}/${DIR_NAME})

set(PRIVATE_SOURCES
    ${CMAKE_CURRENT_LIST_DIR}/implementation.hpp
)

target_sources(${PROJECT_NAME} 
    PRIVATE
        ${PRIVATE_SOURCES}
)

source_group(${GROUP_PATH} FILES ${PRIVATE_SOURCES})

# Add platform dependent sources
include(${CMAKE_CURRENT_LIST_DIR}/${PLATFORM_NAME}/CMakeLists.txt)

