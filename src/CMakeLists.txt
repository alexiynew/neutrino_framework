message("Add modules...")

get_filename_component(SOURCE_FOLDER_NAME ${CMAKE_CURRENT_LIST_DIR} NAME)

# Add source files
include(${CMAKE_CURRENT_LIST_DIR}/common/CMakeLists.txt)
include(${CMAKE_CURRENT_LIST_DIR}/math/CMakeLists.txt)
include(${CMAKE_CURRENT_LIST_DIR}/log/CMakeLists.txt)
include(${CMAKE_CURRENT_LIST_DIR}/unit_test/CMakeLists.txt)
include(${CMAKE_CURRENT_LIST_DIR}/window/CMakeLists.txt)

target_include_directories(${PROJECT_NAME} PRIVATE ${FRAMEWORK_SOURCE_DIR})
