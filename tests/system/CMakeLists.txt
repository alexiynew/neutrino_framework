set(TESTS
    context
    window_open
    window_focus
    window_properties
    window_state
    window_resize
    window_cursor
)

foreach(TEST ${TESTS})
    include(${GROUP_SOURCE_DIR}/${TEST}/CMakeLists.txt)
    set(TEST_FOLDER ${TESTS_DIR_NAME}/${GROUP})

    add_executable(${TEST} EXCLUDE_FROM_ALL "")
    target_sources(${TEST} PRIVATE ${PRIVATE_SOURCES})

    target_link_libraries(${TEST} ${PROJECT_NAME})
    target_include_directories(${TEST} PRIVATE $<TARGET_PROPERTY:${PROJECT_NAME},INCLUDE_DIRECTORIES>)

    set_target_properties(${TEST} PROPERTIES FOLDER ${TEST_FOLDER})

    add_test(NAME "${GROUP}/${TEST}" COMMAND ${TEST})
    set_tests_properties("${GROUP}/${TEST}" PROPERTIES LABELS ${GROUP})

    add_dependencies(${TESTS_TARGET} ${TEST})
endforeach(TEST)
