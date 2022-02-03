include(CTest)
enable_testing()

set(TESTS_TARGET ${PROJECT_NAME}_tests)
set(TEST_DIR_NAME test)

add_custom_target(${TESTS_TARGET} ALL 
    DEPENDS ${PROJECT_NAME}
    COMMENT "Build tests."
)

message(STATUS "Add tests...")

set(TEST_GROUPS
    common
    game_core
    graphics
    log
    math
    system
    unit_test
)

foreach(GROUP ${TEST_GROUPS})
    set(GROUP_NAME ${GROUP})
    set(GROUP_DIR ${FRAMEWORK_TEST_DIR}/${GROUP})

    message(STATUS "\t${GROUP_NAME}")
    include(${GROUP_DIR}/CMakeLists.txt)
endforeach(GROUP)

add_custom_target(check
    COMMAND ${CMAKE_CTEST_COMMAND} --build-config $<CONFIG> --output-on-failure --label-regex \"${INCLUDED_TEST_MODULES}\"
    DEPENDS ${TESTS_TARGET}
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
)

add_custom_target(check_verbose
    COMMAND ${CMAKE_CTEST_COMMAND} --build-config $<CONFIG> --output-on-failure --label-regex \"${INCLUDED_TEST_MODULES}\" --verbose
    DEPENDS ${TESTS_TARGET}
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
)

set_target_properties(${TESTS_TARGET} PROPERTIES FOLDER ${TEST_DIR_NAME})
set_target_properties(check PROPERTIES FOLDER ${TEST_DIR_NAME})
set_target_properties(check_verbose PROPERTIES FOLDER ${TEST_DIR_NAME})

