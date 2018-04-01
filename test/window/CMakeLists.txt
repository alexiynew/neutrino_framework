project(window_tests)

get_filename_component(TEST_PACK_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)

message("\tAdd tests: ${TEST_PACK_NAME}")

add_subdirectory(window_open)
add_subdirectory(window_focus)

add_custom_target(${PROJECT_NAME}
    DEPENDS window_open window_focus
)

set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER ${TARGET_PROJECT_FOLDER}/${TEST_PACK_NAME})
