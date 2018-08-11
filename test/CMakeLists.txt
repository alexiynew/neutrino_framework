include(CTest)
enable_testing()

message("Add tests...")

get_filename_component(TEST_FOLDER_NAME ${CMAKE_CURRENT_LIST_DIR} NAME)
set(TESTS_TARGET_NAME framework_tests)

add_custom_target(${TESTS_TARGET_NAME} DEPENDS ${PROJECT_NAME})

include(${CMAKE_CURRENT_LIST_DIR}/unit_test/CMakeLists.txt)
include(${CMAKE_CURRENT_LIST_DIR}/common/CMakeLists.txt)
include(${CMAKE_CURRENT_LIST_DIR}/log/CMakeLists.txt)
include(${CMAKE_CURRENT_LIST_DIR}/math/CMakeLists.txt)
include(${CMAKE_CURRENT_LIST_DIR}/graphic/CMakeLists.txt)

add_custom_target(run_all_tests
    COMMAND ${CMAKE_CTEST_COMMAND} --build-config ${CMAKE_BUILD_TYPE} --output-on-failure --label-regex \"${INCLUDED_TEST_MODULES}\"
    DEPENDS ${TESTS_TARGET_NAME}
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
)

add_custom_target(run_all_tests_verbose
    COMMAND ${CMAKE_CTEST_COMMAND} --build-config ${CMAKE_BUILD_TYPE} --output-on-failure --label-regex \"${INCLUDED_TEST_MODULES}\" --verbose
    DEPENDS ${TESTS_TARGET_NAME}
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
)
