cmake_minimum_required(VERSION 3.0)

project(framework VERSION 0.0.1)

option(BUILD_SHARED_LIBS "Build the shared or static libraries" OFF)
option(BUILD_TESTS "Build test programs" OFF)

# Settings
set(OUTPUT_PATH_BASE ${CMAKE_SOURCE_DIR}/output/)
set(DOCS_OUTPUT_PATH $${OUTPUT_PATH_BASE}/doc)

if(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
  set(CMAKE_INSTALL_PREFIX ${OUTPUT_PATH_BASE}/${CMAKE_BUILD_TYPE} CACHE PATH "Set default install path." FORCE)
endif(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)

set(FRAMEWORK_SOURCES ${CMAKE_SOURCE_DIR}/src)
get_filename_component(SOURCE_PARENT_DIR ${CMAKE_SOURCE_DIR} DIRECTORY)

if(CMAKE_CXX_COMPILER_ID MATCHES "Clang")
	message("Using Clang compiller settings")
	set(COMPILE_FLAGS "-Weverything -Werror -std=c++14 -Wno-c++98-compat -Wno-padded -Wno-c++11-extensions -Wno-covered-switch-default -Wno-missing-prototypes -Wno-weak-vtables -Wno-exit-time-destructors")
    set(CMAKE_CXX_FLAGS_DEBUG "-g")
elseif(CMAKE_CXX_COMPILER_ID MATCHES "GNU")
	message("Using GNU compiller settings")
	set(COMPILE_FLAGS "-Wall -Wextra -Wfloat-equal -Wshadow -Wpedantic -Wconversion -Wno-unknown-pragmas -Werror -std=c++14")
	set(CMAKE_CXX_FLAGS_DEBUG "-g")
elseif(MAKE_CXX_COMPILER_ID MATCHES "MSVC")
	message("Using Visual Studio C++ compiller settings")
	set(COMPILE_FLAGS "/Wall /wd4514")
	# function' : unreferenced inline function has been removed
	set(CMAKE_CXX_FLAGS_DEBUG "/Od")
endif()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${COMPILE_FLAGS}")

set(CMAKE_CXX_FLAGS_RELEASE "-O3 -DNDEBUG")
set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "-O3 -DNDEBUG -DFORCE_ASSERT")

set(CMAKE_VERBOSE_MAKEFILE OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Import usefull macros
include(${CMAKE_SOURCE_DIR}/cmake/Macros.cmake)

# Get platform
detect_platform_name(PLATFORM_NAME)
message("platform name: ${PLATFORM_NAME}")

# Assemble framework
add_subdirectory(${CMAKE_SOURCE_DIR}/src)

# Add tests
if(BUILD_TESTS) 
	add_subdirectory(${CMAKE_SOURCE_DIR}/test)
endif()

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
