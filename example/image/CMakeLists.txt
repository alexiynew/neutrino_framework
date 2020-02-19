
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

set_sources(PRIVATE_SOURCES
    main.cpp
)

add_executable(${EXAMPLE_NAME} EXCLUDE_FROM_ALL "")

target_sources(${EXAMPLE_NAME} PRIVATE ${PRIVATE_SOURCES})

target_link_libraries(${EXAMPLE_NAME} ${PROJECT_NAME}_static)
target_include_directories(${EXAMPLE_NAME} PRIVATE $<TARGET_PROPERTY:${PROJECT_NAME},INCLUDE_DIRECTORIES>)

set_target_properties(${EXAMPLE_NAME} PROPERTIES FOLDER ${EXAMPLE_DIR_NAME}/${EXAMPLE_NAME})

add_dependencies(${EXAMPLES_TARGET} ${EXAMPLE_NAME})

file(GLOB BMP_GOOD "${EXAMPLE_DIR}/bmp/good/*.bmp")
file(COPY ${BMP_GOOD} DESTINATION ${CMAKE_BINARY_DIR}/example/bmp/good)

file(GLOB BMP_BAD "${EXAMPLE_DIR}/bmp/bad/*.bmp")
file(COPY ${BMP_BAD} DESTINATION ${CMAKE_BINARY_DIR}/example/bmp/bad)

file(GLOB BMP_QUESTIONABLE "${EXAMPLE_DIR}/bmp/questionable/*.bmp")
file(COPY ${BMP_QUESTIONABLE} DESTINATION ${CMAKE_BINARY_DIR}/example/bmp/questionable)

file(GLOB PNG_GOOD "${EXAMPLE_DIR}/png/*.png")
file(COPY ${PNG_GOOD} DESTINATION ${CMAKE_BINARY_DIR}/example/png)

file(GLOB TGA "${EXAMPLE_DIR}/tga/*.tga")
file(COPY ${TGA} DESTINATION ${CMAKE_BINARY_DIR}/example/tga)
