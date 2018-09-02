
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

get_filename_component(MODULE_NAME ${CMAKE_CURRENT_LIST_DIR} NAME)

message("\tAdd module: ${MODULE_NAME}")

set(PUBLIC_SOURCES
    ${CMAKE_CURRENT_LIST_DIR}/math.hpp

    ${CMAKE_CURRENT_LIST_DIR}/details/matrix_type.hpp
    ${CMAKE_CURRENT_LIST_DIR}/details/vector_type.hpp

    ${CMAKE_CURRENT_LIST_DIR}/details/constants.hpp
    ${CMAKE_CURRENT_LIST_DIR}/details/common_functions.hpp
    ${CMAKE_CURRENT_LIST_DIR}/details/exponential_functions.hpp
    ${CMAKE_CURRENT_LIST_DIR}/details/geometric_functions.hpp
    ${CMAKE_CURRENT_LIST_DIR}/details/matrix_functions.hpp
    ${CMAKE_CURRENT_LIST_DIR}/details/relational_functions.hpp
    ${CMAKE_CURRENT_LIST_DIR}/details/transform_functions.hpp

    ${CMAKE_CURRENT_LIST_DIR}/details/vector_type_details.hpp
    ${CMAKE_CURRENT_LIST_DIR}/details/matrix_type_details.hpp

    ${CMAKE_CURRENT_LIST_DIR}/details/common_functions_details.hpp
    ${CMAKE_CURRENT_LIST_DIR}/details/geometric_functions_details.hpp
    ${CMAKE_CURRENT_LIST_DIR}/details/matrix_functions_details.hpp
    ${CMAKE_CURRENT_LIST_DIR}/details/relational_functions_details.hpp
    ${CMAKE_CURRENT_LIST_DIR}/details/trigonometric_functions.hpp
)

target_sources(${PROJECT_NAME} 
    PUBLIC 
        ${PUBLIC_SOURCES}
)

source_group(${MODULE_NAME} FILES ${PUBLIC_SOURCES})
