get_filename_component(TEST_NAME ${CMAKE_CURRENT_LIST_DIR} NAME)

set(PRIVATE_SOURCES 
    ${CMAKE_CURRENT_LIST_DIR}/main.cpp
)

add_executable(${TEST_NAME} EXCLUDE_FROM_ALL "")

target_sources(${TEST_NAME} PRIVATE ${PRIVATE_SOURCES})

target_link_libraries(${TEST_NAME} framework)
target_include_directories(${TEST_NAME} PRIVATE ${FRAMEWORK_SOURCE_DIR})

set_target_properties(${TEST_NAME} PROPERTIES FOLDER ${TEST_FOLDER_NAME}/${TEST_PACK_NAME})

add_test(NAME "${TEST_PACK_NAME}/${TEST_NAME}" COMMAND ${TEST_NAME})
set_tests_properties("${TEST_PACK_NAME}/${TEST_NAME}" PROPERTIES LABELS ${TEST_PACK_NAME})

add_dependencies(${TESTS_TARGET_NAME} ${TEST_NAME})
