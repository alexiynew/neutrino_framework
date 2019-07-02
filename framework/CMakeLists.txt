
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

add_library(${PROJECT_NAME} OBJECT "")

add_library(${PROJECT_NAME}_shared SHARED $<TARGET_OBJECTS:${PROJECT_NAME}>)
add_library(${PROJECT_NAME}_static STATIC $<TARGET_OBJECTS:${PROJECT_NAME}>)

target_include_directories(${PROJECT_NAME}
    PRIVATE
        ${FRAMEWORK_SOURCE_DIR}
        ${FRAMEWORK_DEPENDENCIES_DIR}
)

message(STATUS "Add modules...")

set(MODULES
    "common"
    "log"
    "math"
    "window"
    "graphics"
    "unit_test"
)

foreach(MODULE ${MODULES})
    set(MODULE_NAME ${MODULE})
    set(MODULE_DIR ${FRAMEWORK_SOURCE_DIR}/${MODULE})

    message(STATUS "\t${MODULE_NAME}")
    include(${MODULE_DIR}/CMakeLists.txt)
endforeach(MODULE)


set_property(TARGET ${PROJECT_NAME} PROPERTY POSITION_INDEPENDENT_CODE 1)

get_target_property(${PROJECT_NAME}_SOURCES ${PROJECT_NAME} SOURCES)
source_group(TREE ${FRAMEWORK_SOURCE_DIR} FILES ${${PROJECT_NAME}_SOURCES})

install(TARGETS ${PROJECT_NAME}_shared ${PROJECT_NAME}_static DESTINATION lib)
