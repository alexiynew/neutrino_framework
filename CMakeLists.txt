cmake_minimum_required(VERSION 3.0)

project(framework)

# Settings
set(FRAMEWORK_SOURCES ${CMAKE_SOURCE_DIR}/src)

set(CMAKE_INSTALL_PREFIX ${CMAKE_SOURCE_DIR}/output/${CMAKE_BUILD_TYPE})

set(COMPILE_FLAGS "-Wall -Wextra -Wfloat-equal -Wshadow -Wpedantic -Wconversion -Wno-unknown-pragmas -Werror -std=c++14")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${COMPILE_FLAGS}")

set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -DNDEBUG")
set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "-O3 -DNDEBUG -DFORCE_ASSERT")

set(CMAKE_VERBOSE_MAKEFILE OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


macro(subdirlist RESULT_LIST CURDIR)
    file(GLOB CHILDREN RELATIVE ${CURDIR} ${CURDIR}/*)
    set(DIRLIST "")
    foreach(CHILD ${CHILDREN})
        if(IS_DIRECTORY ${CURDIR}/${CHILD})
            list(APPEND DIRLIST ${CHILD})
        endif()
    endforeach()
    set(${RESULT_LIST} ${DIRLIST})
endmacro()

message("Add libraries...")
add_subdirectory(${FRAMEWORK_SOURCES}/log)
add_subdirectory(${FRAMEWORK_SOURCES}/math)
add_subdirectory(${FRAMEWORK_SOURCES}/unit_test)

add_custom_target(${PROJECT_NAME} ALL DEPENDS log math unit_test)

# Add tests
add_subdirectory(${CMAKE_SOURCE_DIR}/test)
