add_library(${PROJECT_NAME} STATIC "")

target_include_directories(${PROJECT_NAME}
    PRIVATE
        ${FRAMEWORK_SOURCE_DIR}
        ${FRAMEWORK_DEPENDENCIES_DIR}
)

# Set cpp standart
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)
set_target_properties(${PROJECT_NAME} PROPERTIES CXX_EXTENSIONS OFF)

# Set common options
set(GCC_OPTIONS "-Wall;-Wextra;-Wpedantic;-Wshadow;-Wunused;-pedantic-errors;-Werror;-Wno-unknown-pragmas;-Wno-language-extension-token;-pthread")
set(MSVC_OPTIONS "-W4;-WX;-DNOMINMAX;-DUNICODE;-MT")

set(GCC_LIKE_CXX "$<COMPILE_LANG_AND_ID:CXX,ARMClang,AppleClang,Clang,GNU,LCC>")
set(MSVC_LIKE_CXX "$<COMPILE_LANG_AND_ID:CXX,MSVC>")

target_compile_options(${PROJECT_NAME} PUBLIC
  "$<${GCC_LIKE_CXX}:${GCC_OPTIONS}>"
  "$<${MSVC_LIKE_CXX}:${MSVC_OPTIONS}>"
)

# Patform specific options
if(${PLATFORM_NAME} MATCHES "window") 
    # Support unicode and no min\min macros
    target_compile_options(${PROJECT_NAME} PUBLIC "-DNOMINMAX;-DUNICODE")
elseif(${PLATFORM_NAME} MATCHES "linux") 
    target_compile_options(${PROJECT_NAME} PUBLIC "-fPIC")
elseif(${PLATFORM_NAME} MATCHES "osx") 
    target_compile_options(${PROJECT_NAME} PUBLIC "-fPIC")
endif()

# Test covarage
if(TEST_COVERAGE AND (CMAKE_BUILD_TYPE STREQUAL "Debug"))
    set(TEST_COVERAGE_OPTIONS "-O0;--coverage;-fprofile-arcs;-ftest-coverage")
    target_compile_options(${PROJECT_NAME} PUBLIC ${TEST_COVERAGE_OPTIONS})
endif()

# Sanitizers
if(USE_SANITIZER)
    if(USE_SANITIZER MATCHES "([Uu]ndefined)")
        message(STATUS "Build with Undefined Behaviour sanitizer")
        target_compile_options(${PROJECT_NAME} PUBLIC "$<${GCC_OPTIONS}:-fsanitize=undefined>")
    endif()
    if(USE_SANITIZER MATCHES "([As]ddress)")
        message(STATUS "Build with Address sanitizer")
        target_compile_options(${PROJECT_NAME} PUBLIC -fsanitize=address)
        target_link_options(${PROJECT_NAME} PUBLIC "$<${MSVC_LIKE_CXX}:-INCREMENTAL:NO>")
    endif()
    if(USE_SANITIZER MATCHES "([Mm]emory)")
        message(STATUS "Build with Address sanitizer")
        # -fno-optimize-sibling-calls -fsanitize-memory-track-origins=2
        target_compile_options(${PROJECT_NAME} PUBLIC "$<${GCC_OPTIONS}:-fsanitize=memory>")
    endif()
    if(USE_SANITIZER MATCHES "([Tt]thread)")
        message(STATUS "Build with Address sanitizer")
        target_compile_options(${PROJECT_NAME} PUBLIC "$<${GCC_OPTIONS}:-fsanitize=thread>")
    endif()
    if(USE_SANITIZER MATCHES "([Ll]eak)")
        message(STATUS "Build with Address sanitizer")
        target_compile_options(${PROJECT_NAME} PUBLIC "$<${GCC_OPTIONS}:-fsanitize=leak>")
    endif()
    if(USE_SANITIZER MATCHES "([Cc]fi)")
        message(STATUS "Build with Address sanitizer")
        target_compile_options(${PROJECT_NAME} PUBLIC "$<${GCC_OPTIONS}:-fsanitize=cfi>")
    endif()
endif()

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
    set(MODULE_SOURCE_DIR ${FRAMEWORK_SOURCE_DIR}/${MODULE})

    message(STATUS "\t${MODULE}")
    include(${MODULE_SOURCE_DIR}/CMakeLists.txt)
endforeach()

set_property(TARGET ${PROJECT_NAME} PROPERTY POSITION_INDEPENDENT_CODE 1)

get_target_property(${PROJECT_NAME}_SOURCES ${PROJECT_NAME} SOURCES)
source_group(TREE ${FRAMEWORK_SOURCE_DIR} FILES ${${PROJECT_NAME}_SOURCES})

install(TARGETS ${PROJECT_NAME} DESTINATION lib)
