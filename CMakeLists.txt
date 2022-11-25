cmake_minimum_required(VERSION 3.18 FATAL_ERROR)

project(neutrino LANGUAGES CXX VERSION 0.0.4)

# Settings
option(BUILD_TESTS "Should tests be inculuded in build." ON)
option(BUILD_DOCS "Should generate documentation." ON)
option(TEST_COVERAGE "Include test coverage scan in build." OFF)

# Sanitizers
set(USE_SANITIZER "" CACHE STRING "Compile with a sanitizer. Options are: Undefined, Address, Memory, Thread, Leak, Cfi")

# Test modules to run
if(NOT INCLUDED_TEST_MODULES)
    set(INCLUDED_TEST_MODULES ".*" 
        CACHE STRING "Test modules that will be launched in the test command. An empty string means all modules." FORCE)
endif()

# Directories
set(FRAMEWORK_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(FRAMEWORK_SOURCE_DIR ${FRAMEWORK_DIR}/neutrino)
set(FRAMEWORK_TESTS_DIR ${FRAMEWORK_DIR}/tests)
set(FRAMEWORK_DEPENDENCIES_DIR ${FRAMEWORK_DIR}/dependencies)

# Output pathes
set(OUTPUT_PATH_BASE ${FRAMEWORK_DIR}/output)
set(DOCS_SOURCE_DIR ${FRAMEWORK_DIR}/docs)
set(DOCS_BINARY_DIR ${CMAKE_CURRENT_BINARY_DIR}/docs)
set(DOCS_OUTPUT_DIR ${OUTPUT_PATH_BASE}/docs)
set(TESTS_BINARY_DIR ${CMAKE_CURRENT_BINARY_DIR}/tests)

# Install path
if(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
    set(CMAKE_INSTALL_PREFIX ${OUTPUT_PATH_BASE}/${CMAKE_BUILD_TYPE} CACHE PATH "Set default install path." FORCE)
endif()

# Misk settings
set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Import usefull macros
set(CMAKE_MODULE_PATH ${FRAMEWORK_DIR}/cmake)
include(Macros)

# Get platform
detect_platform_name(PLATFORM_NAME)
message(STATUS "Platform: ${PLATFORM_NAME}")

# Get compiler
detect_compiler_name(COMPILER_NAME)
message(STATUS "Compiler: ${COMPILER_NAME} - ${CMAKE_CXX_COMPILER_ID} ${CMAKE_CXX_COMPILER_VERSION}")

# Set compiler helpers
set(GCC_LIKE_COMPILER "$<COMPILE_LANG_AND_ID:CXX,ARMClang,AppleClang,Clang,GNU,LCC>")
set(MSVC_LIKE_COMPILER "$<COMPILE_LANG_AND_ID:CXX,MSVC>")

# Assemble framework
include(${FRAMEWORK_SOURCE_DIR}/CMakeLists.txt)

# Add tests
if(BUILD_TESTS)
    add_subdirectory(${FRAMEWORK_TESTS_DIR})
endif()

# Generate documentation
if(BUILD_DOCS)
    include(${DOCS_SOURCE_DIR}/CMakeLists.txt)
endif()
