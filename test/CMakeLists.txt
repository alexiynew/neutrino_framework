project(framework_tests)

set(TARGET_PROJECT_FOLDER test)

include(CTest)
enable_testing()

message("Add tests...")

add_subdirectory(unit_test)
add_subdirectory(log)
add_subdirectory(math)
add_subdirectory(window)

add_custom_target(${PROJECT_NAME}
    DEPENDS unit_test_tests 
            log_tests 
            math_tests 
            window_tests
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

set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER ${TARGET_PROJECT_FOLDER})
