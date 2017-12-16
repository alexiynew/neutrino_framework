project(window_tests)

get_filename_component(TEST_PACK_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)

message("\tAdd tests: ${TEST_PACK_NAME}")

add_subdirectory(open_window)

add_custom_target(${PROJECT_NAME}
    DEPENDS open_window
)
