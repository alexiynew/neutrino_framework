set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(LIB_NAME "static_lib")

add_library(${LIB_NAME} STATIC static_lib.cpp static_lib.hpp)

set_target_properties(${LIB_NAME} PROPERTIES FOLDER ${TARGET_PROJECT_FOLDER}/${TEST_PACK_NAME}/${TEST_NAME})
target_include_directories(${LIB_NAME} PRIVATE ${FRAMEWORK_SOURCES} ${TEST_SOURCE_DIR})
