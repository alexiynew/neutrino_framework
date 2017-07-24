macro(choose_compiller_flags)
    if("${CMAKE_CXX_COMPILER_ID}" MATCHES "(Apple)?[Cc]lang")
        message("Using Clang compiller settings")
        set(CMAKE_CXX_FLAGS "-Weverything -Werror -std=c++14 -Wno-c++98-compat -Wno-padded -Wno-c++11-extensions -Wno-covered-switch-default -Wno-missing-prototypes -Wno-weak-vtables -Wno-exit-time-destructors")
        set(CMAKE_CXX_FLAGS_DEBUG "-g")
        set(CMAKE_CXX_FLAGS_RELEASE "-O3 -DNDEBUG")
        set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "-O3 -DNDEBUG -DFORCE_ASSERT")
    elseif("${CMAKE_CXX_COMPILER_ID}" MATCHES "GNU")
        message("Using GNU compiller settings")
        set(CMAKE_CXX_FLAGS "-std=c++14 -Wall -Wextra -Wfloat-equal -Wshadow -Wpedantic -Wconversion -Wno-unknown-pragmas -Werror")
        set(CMAKE_CXX_FLAGS_DEBUG "-g")
        set(CMAKE_CXX_FLAGS_RELEASE "-O3 -DNDEBUG")
        set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "-O3 -DNDEBUG -DFORCE_ASSERT")
    elseif("${CMAKE_CXX_COMPILER_ID}" MATCHES "MSVC")
        message("Using Visual Studio C++ compiller settings")
        set(CMAKE_CXX_FLAGS "/std:c++14 /Wall /wd4514 /wd4710 /wd4711")
        set(CMAKE_CXX_FLAGS_DEBUG "/Od")
        set(CMAKE_CXX_FLAGS_RELEASE "/O2 /DNDEBUG")
        set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "/O2 /DNDEBUG -DFORCE_ASSERT")
    endif()
endmacro()
