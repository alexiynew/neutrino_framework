
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

macro(set_compiller_flags)
    message("${CMAKE_CXX_COMPILER_ID} ${CMAKE_CXX_COMPILER_VERSION}")

    if("${CMAKE_CXX_COMPILER_ID}" MATCHES "(Apple)?[Cc]lang")
        set(COMPILER_FLAGS -std=c++17
                           -Weverything
                           -Werror
                           -Wno-c++98-compat
                           -Wno-c++98-compat-pedantic
                           -Wno-c++11-extensions
                           -Wno-c++2a-compat
                           -Wno-padded
                           -Wno-weak-vtables
                           -Wno-exit-time-destructors
                           -Wno-global-constructors
                           -Wno-unknown-pragmas
                           -Wno-reserved-id-macro
                           -Wno-documentation-unknown-command
                           -Wno-switch-enum
                           -Wno-double-promotion
                           -pthread
                           -fPIC)

        set(DEBUG_FLAGS -g)

        set(RELEASE_FLAGS -O3 -DNDEBUG)

    elseif("${CMAKE_CXX_COMPILER_ID}" MATCHES "GNU")
        set(COMPILER_FLAGS -std=c++17
                           -Wall
                           -Wextra
                           -Wpedantic
                           -Werror
                           -Wfloat-equal
                           -Wshadow
                           -Wconversion
                           -Wno-unknown-pragmas
                           -pthread
                           -fPIC)

        set(DEBUG_FLAGS -g)

        set(RELEASE_FLAGS -O3 -DNDEBUG)

    elseif("${CMAKE_CXX_COMPILER_ID}" MATCHES "MSVC")
        set(COMPILER_FLAGS /std:c++17
                           /EHsc
                           /W4
                           /WX)

        set(DEBUG_FLAGS /Od /ZI)

        set(RELEASE_FLAGS /O2 /DNDEBUG)

    endif()

    if("${PLATFORM_NAME}" STREQUAL "windows")
        if("${CMAKE_CXX_COMPILER_ID}" MATCHES "MSVC")
            list(APPEND COMPILER_FLAGS /DNOMINMAX /DUNICODE)
        else()
            list(APPEND COMPILER_FLAGS -DNOMINMAX -DUNICODE)
        endif()
    endif()

    if(ENABLE_TEST_COVERAGE AND (CMAKE_BUILD_TYPE STREQUAL "Debug"))
        list(APPEND COMPILER_FLAGS -O0
                                   --coverage
                                   -fprofile-arcs
                                   -ftest-coverage)
    endif()

    list(JOIN COMPILER_FLAGS " " CMAKE_CXX_FLAGS)
    list(JOIN DEBUG_FLAGS " " CMAKE_CXX_FLAGS_DEBUG)
    list(JOIN RELEASE_FLAGS " " CMAKE_CXX_FLAGS_RELEASE)
    list(JOIN RELEASE_FLAGS " " CMAKE_CXX_FLAGS_RELWITHDEBINFO)

endmacro()
