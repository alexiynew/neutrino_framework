project(framework_tests)

set(TESTS_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(TEST_OUTPUT_PATH ${CMAKE_INSTALL_PREFIX}/test)

set(FRAMEWORK_TESTS_DEPENDENCIES "")

message("Search tests...")
subdirlist(TEST_PACK_LIST ${TESTS_DIR})
list(SORT TEST_PACK_LIST)

foreach (TEST_PACK_NAME ${TEST_PACK_LIST})
    set(TEST_PACK_DIR ${TESTS_DIR}/${TEST_PACK_NAME})

    message("Search tests in ${TEST_PACK_DIR}")

    subdirlist(TEST_LIST ${TEST_PACK_DIR})
    list(SORT TEST_LIST)

    foreach (TEST_DIR ${TEST_LIST})
        set(TEST_DIR ${TEST_PACK_DIR}/${TEST_DIR})

        get_filename_component(TEST_NAME ${TEST_DIR} NAME)
        string(REPLACE " " "_" TEST_NAME ${TEST_NAME})

        if (EXISTS ${TEST_DIR}/CMakeLists.txt)
            message("\tAdd test: ${TEST_NAME}")

            set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${TEST_OUTPUT_PATH}/${TEST_PACK_NAME}/${TEST_NAME})
            add_subdirectory(${TEST_DIR})
            set(FRAMEWORK_TESTS_DEPENDENCIES ${FRAMEWORK_TESTS_DEPENDENCIES} ${TEST_NAME})

        else ()
            message(FATAL_ERROR "There is no CMakeLists.txt in ${TEST_DIR}")
        endif ()

    endforeach ()
endforeach ()

message("Add custom commnad to run all tests")
set(TESTSUITE_EXECUTABLE ${TEST_OUTPUT_PATH}/run_all_tests.py)
set(TESTSUITE_EXECUTABLE_SRC ${CMAKE_CURRENT_SOURCE_DIR}/run_all_tests.py)

add_custom_command(OUTPUT ${TESTSUITE_EXECUTABLE}
                   COMMAND ${CMAKE_COMMAND} -E copy ${TESTSUITE_EXECUTABLE_SRC} ${TESTSUITE_EXECUTABLE}
                   DEPENDS ${TESTSUITE_EXECUTABLE_SRC}
                   COMMENT "Create ${TESTSUITE_EXECUTABLE}")


message("Add custom targets to run all tests")
add_custom_target(run_all_tests
   COMMAND ${TESTSUITE_EXECUTABLE}
   DEPENDS ${PROJECT_NAME}
)

add_custom_target(run_all_tests_verbose
   COMMAND ${TESTSUITE_EXECUTABLE} -v
   DEPENDS ${PROJECT_NAME}
)

add_custom_target(${PROJECT_NAME} DEPENDS ${FRAMEWORK_TESTS_DEPENDENCIES} ${TESTSUITE_EXECUTABLE})
