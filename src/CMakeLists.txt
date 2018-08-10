message("Add modules...")

target_include_directories(${PROJECT_NAME} PRIVATE ${FRAMEWORK_SOURCE_DIR})

# Add source files
include(${CMAKE_CURRENT_LIST_DIR}/common/CMakeLists.txt)
include(${CMAKE_CURRENT_LIST_DIR}/graphic/CMakeLists.txt)
include(${CMAKE_CURRENT_LIST_DIR}/math/CMakeLists.txt)
include(${CMAKE_CURRENT_LIST_DIR}/log/CMakeLists.txt)
include(${CMAKE_CURRENT_LIST_DIR}/unit_test/CMakeLists.txt)

