project(framework_tests)

set(TESTS_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(TEST_OUTPUT_PATH ${OUTPUT_PATH_BASE}/${CMAKE_BUILD_TYPE}/test)

include(CTest)
enable_testing()

message("Add tests...")

add_subdirectory(unit_test)
add_subdirectory(log)
add_subdirectory(math)
add_subdirectory(window)

add_custom_target(${PROJECT_NAME}
    DEPENDS unit_test_tests log_tests math_tests window_tests
)

message("Add custom targets to run all tests")
add_custom_target(run_all_tests
    COMMAND ${CMAKE_CTEST_COMMAND} --build-config ${CMAKE_BUILD_TYPE} --output-on-failure --label-regex \"${INCLUDED_TEST_MODULES}\"
    DEPENDS ${PROJECT_NAME}
)

add_custom_target(run_all_tests_verbose
    COMMAND ${CMAKE_CTEST_COMMAND} --build-config ${CMAKE_BUILD_TYPE} --output-on-failure --label-regex \"${INCLUDED_TEST_MODULES}\" --verbose
    DEPENDS ${PROJECT_NAME}
)

