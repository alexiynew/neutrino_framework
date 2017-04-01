file(GLOB_RECURSE TEST_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

add_executable(${TEST_NAME} EXCLUDE_FROM_ALL ${TEST_SOURCES})

target_link_libraries(${TEST_NAME} math unit_test log)

target_include_directories(${TEST_NAME} PRIVATE ${CMAKE_INSTALL_PREFIX}/lib)
