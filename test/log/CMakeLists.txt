get_filename_component(TEST_PACK_NAME ${CMAKE_CURRENT_LIST_DIR} NAME)

message("\tAdd tests: ${TEST_PACK_NAME}")

include(${CMAKE_CURRENT_LIST_DIR}/interface_test/CMakeLists.txt)
#include(${CMAKE_CURRENT_LIST_DIR}/one_instance_test/CMakeLists.txt)