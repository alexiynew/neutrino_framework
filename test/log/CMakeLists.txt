project(log_tests)

get_filename_component(TEST_PACK_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)

message("\tAdd tests: ${TEST_PACK_NAME}")

add_subdirectory(interface_test)
add_subdirectory(one_instance_test)


add_custom_target(${PROJECT_NAME}
    DEPENDS interface_test one_instance_test
)


