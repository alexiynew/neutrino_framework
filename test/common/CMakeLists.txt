get_filename_component(TEST_PACK_NAME ${CMAKE_CURRENT_LIST_DIR} NAME)

message("\tAdd tests: ${TEST_PACK_NAME}")

include(${CMAKE_CURRENT_LIST_DIR}/utils/CMakeLists.txt)
