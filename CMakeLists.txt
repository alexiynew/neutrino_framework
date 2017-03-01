cmake_minimum_required(VERSION 3.0)

project(framework VERSION 0.0.1)

# Settings
set(CMAKE_INSTALL_PREFIX ${CMAKE_SOURCE_DIR}/output/${CMAKE_BUILD_TYPE})
set(DOCS_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/output/doc)

set(COMPILE_FLAGS "-Wall -Wextra -Wfloat-equal -Wshadow -Wpedantic -Wconversion -Wno-unknown-pragmas -Werror -std=c++14")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${COMPILE_FLAGS}")

set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -DNDEBUG")
set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "-O3 -DNDEBUG -DFORCE_ASSERT")

set(CMAKE_VERBOSE_MAKEFILE OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Import usefull macros
include(${CMAKE_SOURCE_DIR}/cmake/Macros.cmake)

# Assemble framework
add_subdirectory(${CMAKE_SOURCE_DIR}/src)

# Add tests
add_subdirectory(${CMAKE_SOURCE_DIR}/test)

# Generate Doxyfile
file(MAKE_DIRECTORY ${DOCS_OUTPUT_PATH})
configure_file(Doxyfile.in Doxyfile @ONLY)
