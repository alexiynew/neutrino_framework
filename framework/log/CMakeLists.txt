
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

message("${MODULE_NAME}")

set(MODULE_PUBLIC_SOURCES 
    ${CMAKE_CURRENT_LIST_DIR}/log.hpp 
    ${CMAKE_CURRENT_LIST_DIR}/logger.hpp 
    ${CMAKE_CURRENT_LIST_DIR}/stream_logger.hpp
    ${CMAKE_CURRENT_LIST_DIR}/hdr/log_details.hpp
)

set(MODULE_PRIVATE_SOURCES 
    ${CMAKE_CURRENT_LIST_DIR}/src/log.cpp 
    ${CMAKE_CURRENT_LIST_DIR}/src/stream_logger.cpp 
    ${CMAKE_CURRENT_LIST_DIR}/src/log_details.cpp
)

target_sources(${PROJECT_NAME}
    PUBLIC 
        ${MODULE_PUBLIC_SOURCES}
    PRIVATE 
        ${MODULE_PRIVATE_SOURCES}
)

source_group(${MODULE_NAME} FILES ${MODULE_PUBLIC_SOURCES} ${MODULE_PRIVATE_SOURCES})
