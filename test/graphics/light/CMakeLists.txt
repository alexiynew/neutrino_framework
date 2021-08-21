
# =============================================================================
# MIT License
#
# Copyright (c) 2017-2021 Fedorov Alexey
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

set_sources(PRIVATE_SOURCES
    main.cpp
)

add_executable(${TEST_NAME} EXCLUDE_FROM_ALL "")

target_sources(${TEST_NAME} PRIVATE ${PRIVATE_SOURCES})

target_link_libraries(${TEST_NAME} ${PROJECT_NAME})
target_include_directories(${TEST_NAME} PRIVATE $<TARGET_PROPERTY:${PROJECT_NAME},INCLUDE_DIRECTORIES>)

set_target_properties(${TEST_NAME} PROPERTIES FOLDER ${TEST_DIR_NAME}/${GROUP_NAME})

add_test(NAME "${GROUP_NAME}/${TEST_NAME}" COMMAND ${TEST_NAME})
set_tests_properties("${GROUP_NAME}/${TEST_NAME}" PROPERTIES LABELS ${GROUP_NAME})

add_dependencies(${TESTS_TARGET} ${TEST_NAME})

configure_file(${TEST_DIR}/shaders/phong_light.frag ${CMAKE_BINARY_DIR}/test/shaders/phong_light.frag COPYONLY)
configure_file(${TEST_DIR}/shaders/phong_light.vert ${CMAKE_BINARY_DIR}/test/shaders/phong_light.vert COPYONLY)
configure_file(${TEST_DIR}/shaders/white_light_lamp.frag ${CMAKE_BINARY_DIR}/test/shaders/white_light_lamp.frag COPYONLY)
configure_file(${TEST_DIR}/shaders/white_light_lamp.vert ${CMAKE_BINARY_DIR}/test/shaders/white_light_lamp.vert COPYONLY)