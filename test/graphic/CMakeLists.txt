get_filename_component(TEST_PACK_NAME ${CMAKE_CURRENT_LIST_DIR} NAME)

message("\tAdd tests: ${TEST_PACK_NAME}")

include(${CMAKE_CURRENT_LIST_DIR}/window_open/CMakeLists.txt)
include(${CMAKE_CURRENT_LIST_DIR}/window_focus/CMakeLists.txt)
include(${CMAKE_CURRENT_LIST_DIR}/window_properties/CMakeLists.txt)
include(${CMAKE_CURRENT_LIST_DIR}/window_state/CMakeLists.txt)
include(${CMAKE_CURRENT_LIST_DIR}/renderer/CMakeLists.txt)
