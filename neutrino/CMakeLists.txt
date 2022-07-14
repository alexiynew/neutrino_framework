add_library(${PROJECT_NAME} STATIC "")

target_include_directories(${PROJECT_NAME}
    PRIVATE
        ${FRAMEWORK_SOURCE_DIR}
        ${FRAMEWORK_DEPENDENCIES_DIR}
)

set(GCC_OPTIONS "-Wall;-Wextra;-Wpedantic;-Wshadow;-Wunused;-pedantic-errors;-Werror;-Wno-unknown-pragmas;-pthread;-fPIC")
set(MSVC_OPTIONS "-W4;-WX;-DNOMINMAX;-DUNICODE;-MT")

if(ENABLE_TEST_COVERAGE AND (CMAKE_BUILD_TYPE STREQUAL "Debug"))
    set(TEST_COVERAGE_OPTIONS "-O0;--coverage;-fprofile-arcs;-ftest-coverage")
    target_compile_options(${PROJECT_NAME} PUBLIC ${TEST_COVERAGE_OPTIONS})
endif()

if(USE_SANITIZER)
    if(USE_SANITIZER MATCHES "([Uu]ndefined)")
        message(STATUS "Build with Undefined Behaviour sanitizer")
        set(GCC_OPTIONS ${GCC_OPTIONS};-fsanitize=undefined)
        set(MSVC_OPTIONS ${MSVC_OPTIONS};-fsanitize=address)
    endif()
    if(USE_SANITIZER MATCHES "([As]ddress)")
        message(STATUS "Build with Address sanitizer")
        set(GCC_OPTIONS ${GCC_OPTIONS};-fsanitize=address)
        set(MSVC_OPTIONS ${MSVC_OPTIONS};-fsanitize=address)
    endif()
    if(USE_SANITIZER MATCHES "([Mm]emory)")
        message(STATUS "Build with Address sanitizer")
        set(GCC_OPTIONS ${GCC_OPTIONS};-fsanitize=memory) # -fno-optimize-sibling-calls -fsanitize-memory-track-origins=2
    endif()
    if(USE_SANITIZER MATCHES "([Tt]thread)")
        message(STATUS "Build with Address sanitizer")
        set(GCC_OPTIONS ${GCC_OPTIONS};-fsanitize=thread)
    endif()
    if(USE_SANITIZER MATCHES "([Ll]eak)")
        message(STATUS "Build with Address sanitizer")
        set(GCC_OPTIONS ${GCC_OPTIONS};-fsanitize=leak)
    endif()
    if(USE_SANITIZER MATCHES "([Cc]fi)")
        message(STATUS "Build with Address sanitizer")
        set(GCC_OPTIONS ${GCC_OPTIONS};-fsanitize=cfi)
    endif()
endif()

set(GCC_LIKE_CXX "$<COMPILE_LANG_AND_ID:CXX,ARMClang,AppleClang,Clang,GNU,LCC>")
set(MSVC_LIKE_CXX "$<COMPILE_LANG_AND_ID:CXX,MSVC>")

target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)
target_compile_options(${PROJECT_NAME} PUBLIC
  "$<${GCC_LIKE_CXX}:${GCC_OPTIONS}>"
  "$<${MSVC_LIKE_CXX}:${MSVC_OPTIONS}>"
)

message(STATUS "Add modules...")

set(MODULES
    common
    game_core
    graphics
    log
    math
    system
    unit_test
    profiler
)

foreach(MODULE ${MODULES})
    set(MODULE_NAME ${MODULE})
    set(MODULE_DIR ${FRAMEWORK_SOURCE_DIR}/${MODULE})

    message(STATUS "\t${MODULE_NAME}")
    include(${MODULE_DIR}/CMakeLists.txt)
endforeach()

set_property(TARGET ${PROJECT_NAME} PROPERTY POSITION_INDEPENDENT_CODE 1)

get_target_property(${PROJECT_NAME}_SOURCES ${PROJECT_NAME} SOURCES)
source_group(TREE ${FRAMEWORK_SOURCE_DIR} FILES ${${PROJECT_NAME}_SOURCES})

install(TARGETS ${PROJECT_NAME} DESTINATION lib)


message(VERBOSE "-----------------------------------------")

message(VERBOSE "CMAKE_CXX_FLAGS: ${CMAKE_CXX_FLAGS}")
message(VERBOSE "CMAKE_CXX_FLAGS_DEBUG: ${CMAKE_CXX_FLAGS_DEBUG}")        
message(VERBOSE "CMAKE_CXX_FLAGS_RELEASE: ${CMAKE_CXX_FLAGS_RELEASE}")      
message(VERBOSE "CMAKE_CXX_FLAGS_RELWITHDEBINFO: ${CMAKE_CXX_FLAGS_RELWITHDEBINFO}")

get_target_property(${PROJECT_NAME}_COMPILE_OPTIONS ${PROJECT_NAME} COMPILE_OPTIONS)
get_target_property(${PROJECT_NAME}_COMPILE_FEATURES ${PROJECT_NAME} COMPILE_FEATURES)
get_target_property(${PROJECT_NAME}_CXX_STANDARD ${PROJECT_NAME} CXX_STANDARD)

message(VERBOSE "NEUTRINO COMPILE_OPTIONS: ${${PROJECT_NAME}_COMPILE_OPTIONS}")
message(VERBOSE "NEUTRINO COMPILE_FEATURES: ${${PROJECT_NAME}_COMPILE_FEATURES}")
message(VERBOSE "NEUTRINO CXX_STANDARD: ${${PROJECT_NAME}_CXX_STANDARD}")

message(VERBOSE "-----------------------------------------")