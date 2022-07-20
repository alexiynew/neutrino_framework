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
endmacro(detect_platform_name)

# Detect compiler and set compiler name
macro(detect_compiler_name COMPILER_NAME)
    if("${CMAKE_CXX_COMPILER_ID}" MATCHES "(Apple)?[Cc]lang")
        set(COMPILER_NAME "clang")
    elseif("${CMAKE_CXX_COMPILER_ID}" MATCHES "GNU")
        set(COMPILER_NAME "gcc")
    elseif("${CMAKE_CXX_COMPILER_ID}" MATCHES "MSVC")
        set(COMPILER_NAME "msvc")
    else()
        set(COMPILER_NAME "unknown")
    endif()
endmacro(detect_compiler_name)

# Make absolute path to source files
macro(set_sources SOURCE_OUTPUT)
    unset(${SOURCE_OUTPUT})
    unset(${SOURCE_OUTPUT} CACHE)
    foreach(ARG ${ARGN})
        list(APPEND ${SOURCE_OUTPUT} "${CMAKE_CURRENT_LIST_DIR}/${ARG}")
    endforeach(ARG)
endmacro(set_sources)

# Make install target for files
macro(make_install_files_target PREFIX)
    foreach(ARG ${ARGN})
        get_filename_component(DIR ${ARG} DIRECTORY)
        string(REGEX REPLACE "^${CMAKE_CURRENT_LIST_DIR}" "" DIR ${DIR})
        install(FILES ${ARG} DESTINATION "${PREFIX}/${DIR}")
    endforeach(ARG)
endmacro(make_install_files_target)
