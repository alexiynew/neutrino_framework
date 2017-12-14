set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(LIB_NAME "shared_lib")

add_library(${LIB_NAME} SHARED shared_lib.cpp)

target_link_libraries(${LIB_NAME} log)

target_include_directories(${LIB_NAME} PRIVATE ${FRAMEWORK_SOURCES} ${TEST_SOURCE_DIR})