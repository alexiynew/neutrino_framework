set(EXAMPLES_TARGET ${PROJECT_NAME}_examples)
get_filename_component(EXAMPLES_FOLDER ${CMAKE_CURRENT_LIST_DIR} NAME)

add_custom_target(${EXAMPLES_TARGET} ALL
    DEPENDS ${PROJECT_NAME}
    COMMENT "Build examples."
)
set_target_properties(${EXAMPLES_TARGET} PROPERTIES FOLDER ${EXAMPLES_FOLDER})

message(STATUS "Add examples...")

set(EXAMPLES
    image
    light
    window_events
)

foreach(EXAMPLE ${EXAMPLES})
    set(EXAMPLE_SOURCE_DIR ${FRAMEWORK_EXAMPLES_DIR}/${EXAMPLE})
    set(EXAMPLE_BINARY_DIR ${EXAMPLES_BINARY_DIR}/${EXAMPLE})
    set(EXAMPLE_FOLDER ${EXAMPLES_FOLDER}/${EXAMPLE}) 

    message(STATUS "\t${EXAMPLE}")
    include(${EXAMPLE_SOURCE_DIR}/CMakeLists.txt)

    add_executable(${EXAMPLE} EXCLUDE_FROM_ALL "")

    target_sources(${EXAMPLE} PRIVATE ${PRIVATE_SOURCES})

    target_link_libraries(${EXAMPLE} ${PROJECT_NAME})
    target_include_directories(${EXAMPLE} PRIVATE $<TARGET_PROPERTY:${PROJECT_NAME},INCLUDE_DIRECTORIES>)

    set_target_properties(${EXAMPLE} PROPERTIES FOLDER ${EXAMPLE_FOLDER})
    set_target_properties(${EXAMPLE} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${EXAMPLE_BINARY_DIR})
    set_target_properties(${EXAMPLE} PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY ${EXAMPLE_BINARY_DIR})

    add_dependencies(${EXAMPLES_TARGET} ${EXAMPLE})

endforeach(EXAMPLE)
