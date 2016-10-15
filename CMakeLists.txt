CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

SET(CMAKE_CXX_COMPILER clang++-4.0)

PROJECT(framework)

SET(CMAKE_CTEST_COMMAND ctest -V)

SET(SOURCE_DIR ${CMAKE_SOURCE_DIR}/src)
SET(TESTS_DIR ${CMAKE_SOURCE_DIR}/test)
SET(COMPILE_FLAGS "-Weverything -std=c++14 -Wno-c++98-compat -Wno-padded")

FILE(GLOB_RECURSE SOURCES ${SOURCE_DIR}/*.cpp)
FILE(GLOB_RECURSE HEADERS ${SOURCE_DIR}/*.h)
FILE(GLOB_RECURSE TEST_SOURCES ${TESTS_DIR}/*.cpp ${TESTS_DIR}/*.h)

SET(ALL_SOURCES ${SOURCES} ${HEADERS} ${TEST_SOURCES})

SET(INCLUDE_DIR ${SOURCE_DIR})

SET(LIBRARIES "")

SET(CMAKE_VERBOSE_MAKEFILE OFF)

SET(CMAKE_CXX_FLAGS_DEBUG "-g")
SET(CMAKE_CXX_FLAGS_RELEASE "-O3 -DNDEBUG")
SET(CMAKE_CXX_FLAGS_RELWITHDEBINFO "-O3 -DNDEBUG -DFORCE_ASSERT")

SET(CMAKE_BUILD_TYPE Release)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${COMPILE_FLAGS}")
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/${CMAKE_BUILD_TYPE})

INCLUDE_DIRECTORIES(${INCLUDE_DIR})

#add_executable (${PROJECT_NAME} ${SOURCES})
#target_link_libraries (${PROJECT_NAME} ${LIBRARIES})

ENABLE_TESTING()
ADD_SUBDIRECTORY(${TESTS_DIR})

ADD_CUSTOM_TARGET(test_verbose COMMAND ${CMAKE_CTEST_COMMAND})

ADD_CUSTOM_TARGET(clangformat
                  COMMAND clang-format-4.0 -style=file -i ${ALL_SOURCES})


ADD_CUSTOM_TARGET(cppcheck
                  COMMAND cppcheck
                  --force
                  --enable=warning,performance,portability,information
                  --suppress=missingIncludeSystem
                  --std=c++14
                  --quiet
                  --template="{file}:{line}:\\n[{severity}:{id}]:{message}\\n\\t{callstack}"
                  ${ALL_SOURCES}
                  COMMENT "Run cppcheck")

