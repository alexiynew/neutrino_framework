
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

include(CTest)
enable_testing()

set(TESTS_TARGET ${PROJECT_NAME}_tests)
set(TEST_DIR_NAME test)

add_custom_target(${TESTS_TARGET} ALL 
    DEPENDS ${PROJECT_NAME}
    COMMENT "Build tests."
)

message(STATUS "Add tests...")

set(TEST_GROUPS
    "unit_test"
    "common"
    "log"
    "math"
    "system"
    "graphics"
    "game_core"
)

foreach(GROUP ${TEST_GROUPS})
    set(GROUP_NAME ${GROUP})
    set(GROUP_DIR ${FRAMEWORK_TEST_DIR}/${GROUP})

    message(STATUS "\t${GROUP_NAME}")
    include(${GROUP_DIR}/CMakeLists.txt)
endforeach(GROUP)

add_custom_target(check
    COMMAND ${CMAKE_CTEST_COMMAND} --build-config $<CONFIG> --output-on-failure --label-regex \"${INCLUDED_TEST_MODULES}\"
    DEPENDS ${TESTS_TARGET}
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
)

add_custom_target(check_verbose
    COMMAND ${CMAKE_CTEST_COMMAND} --build-config $<CONFIG> --output-on-failure --label-regex \"${INCLUDED_TEST_MODULES}\" --verbose
    DEPENDS ${TESTS_TARGET}
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
)

set_target_properties(${TESTS_TARGET} PROPERTIES FOLDER ${TEST_DIR_NAME})
set_target_properties(check PROPERTIES FOLDER ${TEST_DIR_NAME})
set_target_properties(check_verbose PROPERTIES FOLDER ${TEST_DIR_NAME})

