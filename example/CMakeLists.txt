set(EXAMPLES_TARGET ${PROJECT_NAME}_examples)
set(EXAMPLE_DIR_NAME example)

add_custom_target(${EXAMPLES_TARGET} ALL
    DEPENDS ${PROJECT_NAME}
    COMMENT "Build examples."
)

message(STATUS "Add examples...")

set(EXAMPLES
    "image"
)

foreach(EXAMPLE ${EXAMPLES})
    set(EXAMPLE_NAME ${EXAMPLE})
    set(EXAMPLE_DIR ${FRAMEWORK_EXAMPLE_DIR}/${EXAMPLE})

    message(STATUS "\t${EXAMPLE_NAME}")
    include(${EXAMPLE_DIR}/CMakeLists.txt)
endforeach(EXAMPLE)

set_target_properties(${EXAMPLES_TARGET} PROPERTIES FOLDER ${EXAMPLE_DIR_NAME})

