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
    set(TEST_NAME ${TEST})
    set(TEST_DIR ${GROUP_DIR}/${TEST})

    include(${TEST_DIR}/CMakeLists.txt)
endforeach(TEST)
