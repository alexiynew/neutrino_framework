get_filename_component(TEST_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)

file(GLOB_RECURSE TEST_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

set(TEST_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(${TEST_NAME} EXCLUDE_FROM_ALL ${TEST_SOURCES})

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/static_lib)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/shared_lib)

target_link_libraries(${TEST_NAME} unit_test log static_lib shared_lib)

target_include_directories(${TEST_NAME} PRIVATE ${FRAMEWORK_SOURCES} ${TEST_SOURCE_DIR})
set_target_properties(${TEST_NAME} PROPERTIES FOLDER ${TARGET_PROJECT_FOLDER}/${TEST_PACK_NAME})

add_test(NAME "${TEST_PACK_NAME}/${TEST_NAME}" COMMAND ${TEST_NAME})

set_tests_properties("${TEST_PACK_NAME}/${TEST_NAME}" PROPERTIES LABELS ${TEST_PACK_NAME})
