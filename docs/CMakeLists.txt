
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

find_package(Doxygen REQUIRED)
find_package(Sphinx REQUIRED)

set(DOCS_INPUT_HEADERS $<TARGET_PROPERTY:${PROJECT_NAME},INTERFACE_SOURCES>)

set(DOCS_INPUT_DOX ${FRAMEWORK_SOURCE_DIR}/neutrino.dox)

configure_file(${DOCS_SOURCE_DIR}/Doxyfile.in ${DOCS_BINARY_DIR}/Doxyfile @ONLY)
configure_file(${DOCS_SOURCE_DIR}/DoxygenLayout.xml ${DOCS_BINARY_DIR}/DoxygenLayout.xml COPYONLY)

add_custom_target(doxygenxml ALL
    COMMAND ${CMAKE_COMMAND} -E make_directory ${DOCS_OUTPUT_DIR}
    COMMAND ${DOXYGEN_EXECUTABLE} ${DOCS_BINARY_DIR}/Doxyfile
    DEPENDS ${DOCS_INPUT_HEADERS} ${DOCS_INPUT_DOX}
    COMMENT "Generating xml documentation"
)

set(SPHINX_SOURCE ${DOCS_SOURCE_DIR}/source)
set(SPHINX_BUILD ${DOCS_OUTPUT_DIR}/sphinx)
 
add_custom_target(docs ALL
    COMMAND ${SPHINX_EXECUTABLE} -b html
            -Dbreathe_projects.neutrino=${DOCS_OUTPUT_DIR}/doxyxml
            ${SPHINX_SOURCE} ${SPHINX_BUILD}
    COMMENT "Generating documentation"
)
