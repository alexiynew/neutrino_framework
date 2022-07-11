set_sources(PRIVATE_SOURCES
    main.cpp
)

add_executable(${TEST_NAME} EXCLUDE_FROM_ALL "")

target_sources(${TEST_NAME} PRIVATE ${PRIVATE_SOURCES})

target_link_libraries(${TEST_NAME} ${PROJECT_NAME})
target_include_directories(${TEST_NAME} PRIVATE $<TARGET_PROPERTY:${PROJECT_NAME},INCLUDE_DIRECTORIES>)

set_target_properties(${TEST_NAME} PROPERTIES FOLDER ${TESTS_DIR_NAME}/${GROUP_NAME})

add_test(NAME "${GROUP_NAME}/${TEST_NAME}" COMMAND ${TEST_NAME})
set_tests_properties("${GROUP_NAME}/${TEST_NAME}" PROPERTIES LABELS ${GROUP_NAME})

add_dependencies(${TESTS_TARGET} ${TEST_NAME})

file(GLOB IMAGES "${TEST_DIR}/fonts/*.ttf")
file(COPY ${IMAGES} DESTINATION ${CMAKE_BINARY_DIR}/${TESTS_DIR_NAME}/fonts)