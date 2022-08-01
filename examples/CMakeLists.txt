set(EXAMPLES_TARGET ${PROJECT_NAME}_examples)
set(EXAMPLES_DIR_NAME examples)

add_custom_target(${EXAMPLES_TARGET} ALL
    DEPENDS ${PROJECT_NAME}
    COMMENT "Build examples."
)

message(STATUS "Add examples...")

set(EXAMPLES
    image
    light
    window_events
)

foreach(EXAMPLE ${EXAMPLES})
    set(EXAMPLE_NAME ${EXAMPLE})
    set(EXAMPLE_DIR ${FRAMEWORK_EXAMPLES_DIR}/${EXAMPLE})

    message(STATUS "\t${EXAMPLE_NAME}")
    include(${EXAMPLE_DIR}/CMakeLists.txt)

    add_executable(${EXAMPLE_NAME} EXCLUDE_FROM_ALL "")

    target_sources(${EXAMPLE_NAME} PRIVATE ${PRIVATE_SOURCES})

    target_link_libraries(${EXAMPLE_NAME} ${PROJECT_NAME})
    target_include_directories(${EXAMPLE_NAME} PRIVATE $<TARGET_PROPERTY:${PROJECT_NAME},INCLUDE_DIRECTORIES>)

    set_target_properties(${EXAMPLE_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${EXAMPLE_NAME})
    set_target_properties(${EXAMPLE_NAME} PROPERTIES FOLDER ${EXAMPLES_DIR_NAME}/${EXAMPLE_NAME})

    add_dependencies(${EXAMPLES_TARGET} ${EXAMPLE_NAME})

endforeach(EXAMPLE)

set_target_properties(${EXAMPLES_TARGET} PROPERTIES FOLDER ${EXAMPLES_DIR_NAME})
