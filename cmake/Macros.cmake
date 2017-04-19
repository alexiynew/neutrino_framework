# TODO add documentation

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

# TODO Add platform detection
macro(detect_platform_name PLATFORM_NAME)
    set(PLATFORM_NAME "linux")
    # set(PLATFORM_NAME "osx")
    # set(PLATFORM_NAME "windows")
endmacro()
