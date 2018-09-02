
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

# Get list of all directories in current directory
macro(subdirlist RESULT_LIST CURDIR)
    file(GLOB CHILDREN RELATIVE ${CURDIR} ${CURDIR}/*)
    set(DIRLIST "")
    foreach(CHILD ${CHILDREN})
        if(IS_DIRECTORY ${CURDIR}/${CHILD})
            list(APPEND DIRLIST ${CHILD})
        endif()
    endforeach()
    set(${RESULT_LIST} ${DIRLIST})
endmacro()

# Detect platform and set platform name
macro(detect_platform_name PLATFORM_NAME)
    if(${UNIX})
        if(${APPLE})
            if(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
                set(PLATFORM_NAME "osx")
            endif()
        else()
            set(PLATFORM_NAME "linux")
        endif()
    elseif(${WIN32})
        set(PLATFORM_NAME "windows")
    endif()
endmacro()
