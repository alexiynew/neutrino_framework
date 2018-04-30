message("Add modules...")

get_filename_component(SOURCE_FOLDER_NAME ${CMAKE_CURRENT_LIST_DIR} NAME)

# Include the header only modules as a source files
include(${CMAKE_CURRENT_LIST_DIR}/common/CMakeLists.txt)
include(${CMAKE_CURRENT_LIST_DIR}/math/CMakeLists.txt)

# Normal libraries as subprojects
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/log)
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/unit_test)
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/window)

set(DUMMY_SOURCE_FILE ${CMAKE_CURRENT_BINARY_DIR}/generated/framework_dummy.cpp)

file(WRITE ${DUMMY_SOURCE_FILE}
    "//generated file"
)

target_sources(${PROJECT_NAME} PRIVATE ${DUMMY_SOURCE_FILE})

source_group("generated" FILES ${DUMMY_SOURCE_FILE})

# Linking all modules into one library
target_link_libraries(${PROJECT_NAME} $<TARGET_OBJECTS:log> $<TARGET_OBJECTS:unit_test> $<TARGET_OBJECTS:window>)

