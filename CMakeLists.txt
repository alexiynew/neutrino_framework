
# =============================================================================
# MIT License
#
# Copyright (c) 2017-2019 Fedorov Alexey
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in all
# copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
# SOFTWARE.
# =============================================================================

cmake_minimum_required(VERSION 3.10 FATAL_ERROR)

project(neutrino LANGUAGES CXX VERSION 0.0.3)

# Settings
option(BUILD_TESTS "Should tests be inculuded in build." ON)
option(BUILD_DOCS "Should generate documentation." ON)
option(ENABLE_TEST_COVERAGE "Include test coverage scan in build" OFF)

# Test modules to run
if(NOT INCLUDED_TEST_MODULES)
    set(INCLUDED_TEST_MODULES ".*" CACHE STRING "Test modules that will be launched in the test command. An empty string means all modules." FORCE)
endif()

# Directories
set(FRAMEWORK_DIR ${CMAKE_SOURCE_DIR})
set(FRAMEWORK_SOURCE_DIR ${CMAKE_SOURCE_DIR}/neutrino)
set(FRAMEWORK_TEST_DIR ${CMAKE_SOURCE_DIR}/test)
set(FRAMEWORK_DEPENDENCIES_DIR ${CMAKE_SOURCE_DIR}/dependencies)

# Output pathes
set(OUTPUT_PATH_BASE ${CMAKE_SOURCE_DIR}/output)
set(DOCS_SOURCE_DIR ${CMAKE_SOURCE_DIR}/docs)
set(DOCS_BINARY_DIR ${CMAKE_BINARY_DIR}/docs)
set(DOCS_OUTPUT_DIR ${OUTPUT_PATH_BASE}/docs)

# Install path
if(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
    set(CMAKE_INSTALL_PREFIX ${OUTPUT_PATH_BASE}/${CMAKE_BUILD_TYPE} CACHE PATH "Set default install path." FORCE)
endif()

# Misk settings
set(CMAKE_VERBOSE_MAKEFILE OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# Import usefull macros
set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)
include(Macros)
include(CompillerSettings)

# Get platform
detect_platform_name(PLATFORM_NAME)
message("platform name: ${PLATFORM_NAME}")

# Set compiller flags
set_compiller_flags()

# Assemble framework
include(${FRAMEWORK_SOURCE_DIR}/CMakeLists.txt)

# Add tests
if(BUILD_TESTS)
    add_subdirectory(${FRAMEWORK_TEST_DIR})
endif()

# Generate documentation
configure_file(${DOCS_SOURCE_DIR}/Doxyfile.in ${DOCS_BINARY_DIR}/Doxyfile @ONLY)
configure_file(${DOCS_SOURCE_DIR}/DoxygenLayout.xml ${DOCS_BINARY_DIR}/DoxygenLayout.xml COPYONLY)

add_custom_target(documentation
    COMMAND ${CMAKE_COMMAND} -E make_directory ${DOCS_OUTPUT_DIR}
    COMMAND doxygen ${DOCS_BINARY_DIR}/Doxyfile
)
