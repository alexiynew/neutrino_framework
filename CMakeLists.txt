cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(framework LANGUAGES CXX VERSION 0.0.2)

# Settings
option(BUILD_SHARED_LIBS "Would the framework library be shared(ON) or a static(OFF) one" OFF)
option(BUILD_TESTING "Should we build tests" OFF)
option(ENABLE_TEST_COVERAGE "Include test coverage scan in build" OFF)

# Framework sources
set(FRAMEWORK_SOURCE_DIR ${CMAKE_SOURCE_DIR}/src)
set(FRAMEWORK_TEST_DIR ${CMAKE_SOURCE_DIR}/test)

# Output pathes
set(OUTPUT_PATH_BASE ${CMAKE_SOURCE_DIR}/output)
set(DOCS_SOURCE_DIR ${CMAKE_SOURCE_DIR}/docs)
set(DOCS_BINARY_DIR ${CMAKE_BINARY_DIR}/docs)
set(DOCS_OUTPUT_DIR ${OUTPUT_PATH_BASE}/docs)

# Test modules to run
if(NOT INCLUDED_TEST_MODULES)
    set(INCLUDED_TEST_MODULES ".*" CACHE STRING "Test modules that will be launched in the test command. An empty string means all modules." FORCE)
endif()

# Install path
if(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
    set(CMAKE_INSTALL_PREFIX ${OUTPUT_PATH_BASE}/${CMAKE_BUILD_TYPE} CACHE PATH "Set default install path." FORCE)
endif()

set(CMAKE_CXX_FLAGS_COVERAGE
    "-g -O0 --coverage -fprofile-arcs -ftest-coverage"
    CACHE STRING "Flags used by the C++ compiler during coverage builds." FORCE)

set(CMAKE_VERBOSE_MAKEFILE OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# Import usefull macros
set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)
include(Macros)
include(CompillerSettings)

# Compiller flags
set_compiller_flags()
# Add coverage flags to the Debug build if needed
if(ENABLE_TEST_COVERAGE AND (CMAKE_BUILD_TYPE STREQUAL "Debug"))
    set(CMAKE_CXX_FLAGS_DEBUG ${CMAKE_CXX_FLAGS_COVERAGE})
endif()

# Get platform
detect_platform_name(PLATFORM_NAME)
message("platform name: ${PLATFORM_NAME}")

# The framework library itself
add_library(${PROJECT_NAME} "")

# Add sources to the framework
include(${FRAMEWORK_SOURCE_DIR}/CMakeLists.txt)

# Add tests
if(BUILD_TESTING)
    include(${FRAMEWORK_TEST_DIR}/CMakeLists.txt)
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
