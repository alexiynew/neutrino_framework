cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(framework VERSION 0.0.1)

# Settings
option(BUILD_SHARED_LIBS "Build the shared or static libraries" OFF)
option(BUILD_TESTS "Build test programs" OFF)
option(ENABLE_TEST_COVERAGE "Include test coverage scan in build" OFF)

# Test modules to run
if(INCLUDED_TEST_MODULES STREQUAL "")
    set(INCLUDED_TEST_MODULES ".*" CACHE STRING "Tests that will be included in the build. An empty string means all modules." FORCE)
endif()

# Install path
if(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
  set(CMAKE_INSTALL_PREFIX ${OUTPUT_PATH_BASE}/${CMAKE_BUILD_TYPE} CACHE PATH "Set default install path." FORCE)
endif(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)

set(OUTPUT_PATH_BASE ${CMAKE_SOURCE_DIR}/output)
set(DOCS_SOURCE_DIR ${CMAKE_SOURCE_DIR}/docs)
set(DOCS_BINARY_DIR ${CMAKE_BINARY_DIR}/docs)
set(DOCS_OUTPUT_DIR ${OUTPUT_PATH_BASE}/docs)

set(CMAKE_CXX_FLAGS_COVERAGE
    "-g -O0 --coverage -fprofile-arcs -ftest-coverage"
    CACHE STRING "Flags used by the C++ compiler during coverage builds." FORCE)

set(CMAKE_VERBOSE_MAKEFILE OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(FRAMEWORK_SOURCES ${CMAKE_SOURCE_DIR}/src)
get_filename_component(SOURCE_PARENT_DIR ${CMAKE_SOURCE_DIR} DIRECTORY)

# Import usefull macros
set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)
include(Macros)
include(CompillerSettings)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# Set compiller flags
choose_compiller_flags()
if(ENABLE_TEST_COVERAGE AND (CMAKE_BUILD_TYPE STREQUAL "Debug"))
    set(CMAKE_CXX_FLAGS_DEBUG ${CMAKE_CXX_FLAGS_COVERAGE})
endif()

# Get platform
detect_platform_name(PLATFORM_NAME)
message("platform name: ${PLATFORM_NAME}")

# Assemble framework
add_subdirectory(${CMAKE_SOURCE_DIR}/src)

# Add tests
if(BUILD_TESTS)
    add_subdirectory(${CMAKE_SOURCE_DIR}/test)
endif()

# Generate documentation
configure_file(${DOCS_SOURCE_DIR}/Doxyfile.in ${DOCS_BINARY_DIR}/Doxyfile @ONLY)

add_custom_target(documentation
    COMMAND ${CMAKE_COMMAND} -E make_directory ${DOCS_OUTPUT_DIR}
    COMMAND doxygen ${DOCS_BINARY_DIR}/Doxyfile
)

# Install target
add_custom_target(install_${PROJECT_NAME}
    COMMAND ${CMAKE_COMMAND} -P ${CMAKE_BINARY_DIR}/cmake_install.cmake
    DEPENDS ${PROJECT_NAME}
    COMMENT "Installing ${PROJECT_NAME}")
