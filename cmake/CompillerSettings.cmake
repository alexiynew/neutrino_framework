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
                           -Wno-float-equal
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
                           -Wshadow
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
