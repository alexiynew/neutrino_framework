cmake_minimum_required(VERSION 3.0)

project(framework VERSION 0.0.1)

# Settings
set(CMAKE_INSTALL_PREFIX ${CMAKE_SOURCE_DIR}/output/${CMAKE_BUILD_TYPE})
set(DOCS_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/output/doc)

set(FRAMEWORK_SOURCES ${CMAKE_SOURCE_DIR}/src)
get_filename_component(SOURCE_PARENT_DIR ${CMAKE_SOURCE_DIR} DIRECTORY)

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
  # using Clang
  set(COMPILE_FLAGS "-Wall -Wextra -Wfloat-equal -Wshadow -Wpedantic -Wconversion -Wno-unknown-pragmas -Werror -std=c++14")
  set(CMAKE_CXX_FLAGS_DEBUG "-g")
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
  # using GCC
  set(COMPILE_FLAGS "-Wall -Wextra -Wfloat-equal -Wshadow -Wpedantic -Wconversion -Wno-unknown-pragmas -Werror -std=c++14")
  set(CMAKE_CXX_FLAGS_DEBUG "-g")
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Intel")
  # using Intel C++
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
  # using Visual Studio C++
  set(COMPILE_FLAGS "-Wall -std=c++14")
  set(CMAKE_CXX_FLAGS_DEBUG "/Od")
endif()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${COMPILE_FLAGS}")

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
configure_file(Doxyfile.in Doxyfile @ONLY)

add_custom_target(install_${PROJECT_NAME}
        $(MAKE) install
        DEPENDS ${PROJECT_NAME}
        COMMENT "Installing ${PROJECT_NAME}")

add_custom_target(documentation
    COMMAND mkdir -p ${DOCS_OUTPUT_PATH}
    COMMAND doxygen ${CMAKE_BINARY_DIR}/Doxyfile
)
