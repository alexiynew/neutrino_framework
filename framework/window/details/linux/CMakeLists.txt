
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
    x11_server.hpp
    x11_window.hpp
    x11_utils.hpp
    x11_keyboard.hpp
    x11_mouse.hpp

    x11_server.cpp
    x11_window.cpp
    x11_utils.cpp
    x11_implementation.cpp
    x11_keyboard.cpp
    x11_mouse.cpp
)

target_sources(${PROJECT_NAME}
    PRIVATE
        ${PRIVATE_SOURCES}
)

# Link to x11
find_package(X11 REQUIRED)

target_include_directories(${PROJECT_NAME} SYSTEM PRIVATE ${X11_INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME}_static ${X11_LIBRARIES})
target_link_libraries(${PROJECT_NAME}_shared ${X11_LIBRARIES})
