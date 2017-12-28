set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(LIB_NAME "shared_lib")

add_library(${LIB_NAME} SHARED shared_lib.cpp shared_lib.hpp)

target_link_libraries(${LIB_NAME} logger)
target_include_directories(${LIB_NAME} PRIVATE ${FRAMEWORK_SOURCES} ${TEST_SOURCE_DIR})
set_target_properties(${LIB_NAME} PROPERTIES FOLDER ${TARGET_PROJECT_FOLDER}/${TEST_PACK_NAME}/${TEST_NAME})
