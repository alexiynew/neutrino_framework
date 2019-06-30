
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
    gl.hpp
)

set_sources(PRIVATE_SOURCES
    gl.cpp
    context.cpp
    context_settings.cpp
)

target_sources(${PROJECT_NAME}
    PUBLIC
        ${PUBLIC_SOURCES}
    PRIVATE
        ${PRIVATE_SOURCES}
)

make_install_files_target(include/${MODULE_NAME}/opengl ${PUBLIC_SOURCES})

install(FILES ${FRAMEWORK_DEPENDENCIES_DIR}/GL/glcorearb.h DESTINATION dependencies/GL)
install(FILES ${FRAMEWORK_DEPENDENCIES_DIR}/KHR/khrplatform.h DESTINATION dependencies/KHR)

include(${MODULE_DIR}/opengl/details/CMakeLists.txt)

# Link with OpenGL
find_package(OpenGL REQUIRED)

target_include_directories(${PROJECT_NAME} SYSTEM PRIVATE ${OPENGL_INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME}_static ${OPENGL_LIBRARIES})
target_link_libraries(${PROJECT_NAME}_shared ${OPENGL_LIBRARIES})
