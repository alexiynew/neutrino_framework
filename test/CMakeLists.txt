set (ROOT_DIR ${CMAKE_CURRENT_SOURCE_DIR})

set (TEST_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin/test)
set (EXECUTABLE_OUTPUT_PATH ${TEST_OUTPUT_PATH})

set (CMAKE_BUILD_TYPE Release)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DFORCE_ASSERT")

include_directories (${ROOT_DIR})

file (GLOB_RECURSE UNITTEST_SOURCES ${SOURCE_DIR}/unittest/*.cpp)

file (GLOB SUBDIR_LIST RELATIVE ${ROOT_DIR} ${ROOT_DIR}/*)
list (SORT SUBDIR_LIST)

foreach (SUBDIR ${SUBDIR_LIST})
    set (TEST_DIR ${ROOT_DIR}/${SUBDIR})
    if (IS_DIRECTORY ${TEST_DIR})
        get_filename_component (TEST_NAME ${TEST_DIR} NAME)
        string (REPLACE " " "_" TEST_NAME ${TEST_NAME})

        if (EXISTS ${TEST_DIR}/CMakeLists.txt)
            add_subdirectory (${TEST_DIR})
        else ()
            add_executable (${TEST_NAME} ${TEST_DIR}/main.cpp ${UNITTEST_SOURCES})
            add_test (${TEST_NAME} ${EXECUTABLE_OUTPUT_PATH}/${TEST_NAME})
        endif ()
    endif ()
endforeach ()

