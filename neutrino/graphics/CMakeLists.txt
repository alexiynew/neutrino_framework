
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

set_sources(PUBLIC_SOURCES
    color_type.hpp
    image.hpp
    mesh.hpp
    shader.hpp
    texture.hpp
)

set_sources(PRIVATE_SOURCES
    src/color_type.cpp
    src/image.cpp
    src/mesh.cpp
    src/shader.cpp
    src/texture.cpp

    src/image/image_info.hpp
    src/image/bmp.hpp
    src/image/bmp.cpp
    src/image/tga.hpp
    src/image/tga.cpp
    src/image/png.hpp
    src/image/png.cpp
)

target_sources(${PROJECT_NAME}
    PUBLIC
        ${PUBLIC_SOURCES}
    PRIVATE
        ${PRIVATE_SOURCES}
)

make_install_files_target(include/${MODULE_NAME} ${PUBLIC_SOURCES})