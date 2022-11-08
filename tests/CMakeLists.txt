include(CTest)
enable_testing()

set(TESTS_TARGET ${PROJECT_NAME}_tests)
get_filename_component(TESTS_FOLDER ${CMAKE_CURRENT_LIST_DIR} NAME)

add_custom_target(${TESTS_TARGET} ALL 
    DEPENDS ${PROJECT_NAME}
    COMMENT "Build tests."
)
set_target_properties(${TESTS_TARGET} PROPERTIES FOLDER ${TESTS_FOLDER})

message(STATUS "Add tests...")

set(TEST_GROUPS
    common
    graphics
    log
    math
    system
    unit_test
)

foreach(GROUP ${TEST_GROUPS})
    set(GROUP_SOURCE_DIR ${FRAMEWORK_TESTS_DIR}/${GROUP})
    set(GROUP_BINARY_DIR ${TESTS_BINARY_DIR}/${GROUP})

    message(STATUS "\t${GROUP}")
    include(${GROUP_SOURCE_DIR}/CMakeLists.txt)
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

set_target_properties(check PROPERTIES FOLDER ${TESTS_FOLDER})
set_target_properties(check_verbose PROPERTIES FOLDER ${TESTS_FOLDER})

set_target_properties(check PROPERTIES XCODE_GENERATE_SCHEME TRUE)
set_target_properties(check_verbose PROPERTIES XCODE_GENERATE_SCHEME TRUE)
