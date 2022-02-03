set_sources(PRIVATE_SOURCES
    main.cpp
)

add_executable(${EXAMPLE_NAME} EXCLUDE_FROM_ALL "")

target_sources(${EXAMPLE_NAME} PRIVATE ${PRIVATE_SOURCES})

target_link_libraries(${EXAMPLE_NAME} ${PROJECT_NAME})
target_include_directories(${EXAMPLE_NAME} PRIVATE $<TARGET_PROPERTY:${PROJECT_NAME},INCLUDE_DIRECTORIES>)

set_target_properties(${EXAMPLE_NAME} PROPERTIES FOLDER ${EXAMPLE_DIR_NAME}/${EXAMPLE_NAME})

add_dependencies(${EXAMPLES_TARGET} ${EXAMPLE_NAME})

file(GLOB BMP_GOOD "${EXAMPLE_DIR}/bmp/good/*.bmp")
file(COPY ${BMP_GOOD} DESTINATION ${CMAKE_BINARY_DIR}/example/bmp/good)

file(GLOB BMP_BAD "${EXAMPLE_DIR}/bmp/bad/*.bmp")
file(COPY ${BMP_BAD} DESTINATION ${CMAKE_BINARY_DIR}/example/bmp/bad)

file(GLOB BMP_QUESTIONABLE "${EXAMPLE_DIR}/bmp/questionable/*.bmp")
file(COPY ${BMP_QUESTIONABLE} DESTINATION ${CMAKE_BINARY_DIR}/example/bmp/questionable)

file(GLOB PNG_GOOD "${EXAMPLE_DIR}/png/*.png")
file(COPY ${PNG_GOOD} DESTINATION ${CMAKE_BINARY_DIR}/example/png)
