set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR})
get_filename_component(LIB_NAME ${SOURCE_DIR} NAME)

set(LIB_HEADERS window.hpp)

file(GLOB LIB_SOURCES ${SOURCE_DIR}/*.cpp)
file(GLOB_RECURSE PLATFORM_DEPENDENT_SOURCES ${SOURCE_DIR}/${PLATFORM_NAME}/*.cpp)
set(LIB_SOURCES ${LIB_SOURCES} ${PLATFORM_DEPENDENT_SOURCES})

# Get list of platform dependent libraries to link with
include(${SOURCE_DIR}/${PLATFORM_NAME}/libraries.cmake)

message("\tAdd library: ${LIB_NAME}")
add_library(${LIB_NAME} ${LIB_SOURCES})

target_include_directories(${LIB_NAME} PRIVATE ${FRAMEWORK_SOURCES})

target_link_libraries(${LIB_NAME} ${PLATFORM_DEPENDENT_LIBRARIES})

install(TARGETS ${LIB_NAME} DESTINATION ${PROJECT_NAME}/${LIB_NAME})
install(FILES ${LIB_HEADERS} DESTINATION ${PROJECT_NAME}/${LIB_NAME})
