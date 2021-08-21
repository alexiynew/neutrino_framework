
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

set(EXAMPLES_TARGET ${PROJECT_NAME}_examples)
set(EXAMPLES_DIR_NAME example)

add_custom_target(${EXAMPLES_TARGET} ALL
    DEPENDS ${PROJECT_NAME}
    COMMENT "Build examples."
)

message(STATUS "Add examples...")

set(EXAMPLES
    "image"
)

foreach(EXAMPLE ${EXAMPLES})
    set(EXAMPLE_NAME ${EXAMPLE})
    set(EXAMPLE_DIR ${FRAMEWORK_EXAMPLE_DIR}/${EXAMPLE})

    message(STATUS "\t${EXAMPLE_NAME}")
    include(${EXAMPLE_DIR}/CMakeLists.txt)
endforeach(EXAMPLE)

set_target_properties(${EXAMPLES_TARGET} PROPERTIES FOLDER ${EXAMPLES_DIR_NAME})

