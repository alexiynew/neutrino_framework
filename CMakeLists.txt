cmake_minimum_required (VERSION 2.8)

set(CMAKE_CXX_COMPILER clang++)

project (framework)

set (CMAKE_CTEST_COMMAND ctest -V)

set (SOURCE_DIR ${CMAKE_SOURCE_DIR}/src)
set (TESTS_DIR ${CMAKE_SOURCE_DIR}/test)
set (COMPILE_FLAGS "-Weverything -std=c++11 -Wno-c++98-compat -Wno-padded")

file (GLOB_RECURSE SOURCES ${SOURCE_DIR}/*.cpp)
file (GLOB_RECURSE HEADERS ${SOURCE_DIR}/*.h)
file (GLOB_RECURSE TEST_SOURCES ${TESTS_DIR}/*.cpp ${TESTS_DIR}/*.h)

set (ALL_SOURCES ${SOURCES} ${HEADERS} ${TEST_SOURCES})

set (INCLUDE_DIR ${SOURCE_DIR})

set (LIBRARIES "")

set (CMAKE_VERBOSE_MAKEFILE OFF)

set (CMAKE_BUILD_TYPE Debug)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${COMPILE_FLAGS}")
set (EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin/${CMAKE_BUILD_TYPE})

include_directories (${INCLUDE_DIR})

#add_executable (${PROJECT_NAME} ${SOURCES})
#target_link_libraries (${PROJECT_NAME} ${LIBRARIES})

enable_testing ()
add_subdirectory (${TESTS_DIR})

add_custom_target(test_verbose COMMAND ${CMAKE_CTEST_COMMAND})

add_custom_target (clangformat
    COMMAND clang-format-3.7 -style=file -i ${ALL_SOURCES} )


add_custom_target (cppcheck
    COMMAND cppcheck
    --force
    --enable=warning,performance,portability,information
    --suppress=missingIncludeSystem
    --std=c++11
    --quiet
    --template="{file}:{line}:\\n[{severity}:{id}]:{message}\\n\\t{callstack}"
    ${ALL_SOURCES}
    COMMENT "Run cppcheck")

