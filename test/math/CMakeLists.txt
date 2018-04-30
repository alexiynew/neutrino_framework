get_filename_component(TEST_PACK_NAME ${CMAKE_CURRENT_LIST_DIR} NAME)

message("\tAdd tests: ${TEST_PACK_NAME}")

include(${CMAKE_CURRENT_LIST_DIR}/vector_constructor/CMakeLists.txt)
include(${CMAKE_CURRENT_LIST_DIR}/vector_operators/CMakeLists.txt)
include(${CMAKE_CURRENT_LIST_DIR}/vector_common/CMakeLists.txt)
include(${CMAKE_CURRENT_LIST_DIR}/vector_exponential/CMakeLists.txt)
include(${CMAKE_CURRENT_LIST_DIR}/vector_geometric/CMakeLists.txt)
include(${CMAKE_CURRENT_LIST_DIR}/vector_relational/CMakeLists.txt)
include(${CMAKE_CURRENT_LIST_DIR}/vector_trigonometric/CMakeLists.txt)

include(${CMAKE_CURRENT_LIST_DIR}/matrix_constructor/CMakeLists.txt)
include(${CMAKE_CURRENT_LIST_DIR}/matrix_math_operators/CMakeLists.txt)
include(${CMAKE_CURRENT_LIST_DIR}/matrix_access/CMakeLists.txt)
include(${CMAKE_CURRENT_LIST_DIR}/matrix_assign/CMakeLists.txt)
include(${CMAKE_CURRENT_LIST_DIR}/matrix_func/CMakeLists.txt)
include(${CMAKE_CURRENT_LIST_DIR}/matrix_transform/CMakeLists.txt)
