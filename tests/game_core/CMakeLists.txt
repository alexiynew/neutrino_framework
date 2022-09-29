set(TESTS 
    fps_counter
)

foreach(TEST ${TESTS})
    set(TEST_SOURCE_DIR ${GROUP_SOURCE_DIR}/${TEST})
    set(TEST_BINARY_DIR ${GROUP_BINARY_DIR}/${TEST})
    set(TEST_FOLDER ${TESTS_FOLDER}/${GROUP})

    include(${TEST_SOURCE_DIR}/CMakeLists.txt)

    add_executable(${TEST} EXCLUDE_FROM_ALL "")
    target_sources(${TEST} PRIVATE ${PRIVATE_SOURCES})

    target_compile_options(${TEST} PRIVATE "$<${GCC_LIKE_COMPILER}:-pthread>")
    
    target_link_libraries(${TEST} ${PROJECT_NAME})
    target_include_directories(${TEST} PRIVATE $<TARGET_PROPERTY:${PROJECT_NAME},INCLUDE_DIRECTORIES>)

    set_target_properties(${TEST} PROPERTIES FOLDER ${TEST_FOLDER})
    set_target_properties(${TEST} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${TEST_BINARY_DIR})
    set_target_properties(${TEST} PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY ${TEST_BINARY_DIR})

    set_target_properties(${TEST} PROPERTIES XCODE_GENERATE_SCHEME TRUE)
    set_target_properties(${TEST} PROPERTIES XCODE_SCHEME_WORKING_DIRECTORY ${TEST_BINARY_DIR})

    add_test(NAME "${GROUP}/${TEST}" COMMAND ${TEST})
    set_tests_properties("${GROUP}/${TEST}" PROPERTIES LABELS ${GROUP})
    set_tests_properties("${GROUP}/${TEST}" PROPERTIES WORKING_DIRECTORY ${TEST_BINARY_DIR})

    add_dependencies(${TESTS_TARGET} ${TEST})
endforeach(TEST)
