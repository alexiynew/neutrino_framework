
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

macro(set_compiller_flags)
    if("${CMAKE_CXX_COMPILER_ID}" MATCHES "(Apple)?[Cc]lang")
        message("Using Clang compiller settings")
        set(CMAKE_CXX_FLAGS "-std=c++1z \
                             -Weverything \
                             -Werror \
                             -Wno-c++98-compat \
                             -Wno-c++11-extensions \
                             -Wno-padded \
                             -Wno-weak-vtables \
                             -Wno-exit-time-destructors \
                             -Wno-unknown-pragmas \
                             -pthread \
                             -fPIC")
        set(CMAKE_CXX_FLAGS_DEBUG "-g")
        set(CMAKE_CXX_FLAGS_RELEASE "-O3 -DNDEBUG")
        set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "-O3 -DNDEBUG")
    elseif("${CMAKE_CXX_COMPILER_ID}" MATCHES "GNU")
        message("Using GNU compiller settings")
        set(CMAKE_CXX_FLAGS "-std=c++17 \
                             -Wall \
                             -Wextra \
                             -Wpedantic \
                             -Werror \
                             -Wfloat-equal \
                             -Wshadow \
                             -Wconversion \
                             -Wno-unknown-pragmas \
                             -pthread \
                             -fPIC")
        set(CMAKE_CXX_FLAGS_DEBUG "-g")
        set(CMAKE_CXX_FLAGS_RELEASE "-O3 -DNDEBUG")
        set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "-O3 -DNDEBUG")
    elseif("${CMAKE_CXX_COMPILER_ID}" MATCHES "MSVC")
        message("Using Visual Studio C++ compiller settings")
        set(CMAKE_CXX_FLAGS "/std:c++17 \
                             /EHsc \
                             /W4 \
                             /WX")
        set(CMAKE_CXX_FLAGS_DEBUG "/Od /ZI")
        set(CMAKE_CXX_FLAGS_RELEASE "/O2 /DNDEBUG")
        set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "/O2 /DNDEBUG")
    endif()
endmacro()

