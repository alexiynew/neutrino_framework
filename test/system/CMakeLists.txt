set(TESTS
    context
    window_cursor
    window_events
    window_focus
    window_open
    window_properties
    window_state
)

foreach(TEST ${TESTS})
    set(TEST_NAME ${TEST})
    set(TEST_DIR ${GROUP_DIR}/${TEST})

    include(${TEST_DIR}/CMakeLists.txt)
endforeach(TEST)
