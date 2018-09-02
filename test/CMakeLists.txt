
# =============================================================================
# MIT License
#
# Copyright (c) 2017-2018 Fedorov Alexey
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

message("Add tests...")

get_filename_component(TEST_FOLDER_NAME ${CMAKE_CURRENT_LIST_DIR} NAME)
set(TESTS_TARGET_NAME framework_tests)

add_custom_target(${TESTS_TARGET_NAME} DEPENDS ${PROJECT_NAME})

include(${CMAKE_CURRENT_LIST_DIR}/unit_test/CMakeLists.txt)
include(${CMAKE_CURRENT_LIST_DIR}/common/CMakeLists.txt)
include(${CMAKE_CURRENT_LIST_DIR}/log/CMakeLists.txt)
include(${CMAKE_CURRENT_LIST_DIR}/math/CMakeLists.txt)
include(${CMAKE_CURRENT_LIST_DIR}/graphic/CMakeLists.txt)

add_custom_target(run_all_tests
    COMMAND ${CMAKE_CTEST_COMMAND} --build-config ${CMAKE_BUILD_TYPE} --output-on-failure --label-regex \"${INCLUDED_TEST_MODULES}\"
    DEPENDS ${TESTS_TARGET_NAME}
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
)

add_custom_target(run_all_tests_verbose
    COMMAND ${CMAKE_CTEST_COMMAND} --build-config ${CMAKE_BUILD_TYPE} --output-on-failure --label-regex \"${INCLUDED_TEST_MODULES}\" --verbose
    DEPENDS ${TESTS_TARGET_NAME}
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
)
