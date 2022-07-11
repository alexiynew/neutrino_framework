set(TESTS_TARGET ${PROJECT_NAME}_manual_tests)
set(TESTS_DIR_NAME manual_tests)

add_custom_target(${TESTS_TARGET} ALL 
    DEPENDS ${PROJECT_NAME}
    COMMENT "Build manual tests."
)

message(STATUS "Add manual tests...")

set(TESTS
    window_events
)

foreach(TEST ${TESTS})
    set(TEST_NAME ${TEST})
    set(TEST_DIR ${TEST})

    message(STATUS "\t${TEST_NAME}")
    include(${TEST_DIR}/CMakeLists.txt)
endforeach(TEST)

set_target_properties(${TESTS_TARGET} PROPERTIES FOLDER ${TESTS_DIR_NAME})
