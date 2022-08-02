set_sources(PRIVATE_SOURCES
    main.cpp
)

file(GLOB PNG_GOOD "${TEST_DIR}/png/*.png")
file(COPY ${PNG_GOOD} DESTINATION ${CMAKE_BINARY_DIR}/${TESTS_DIR_NAME}/png)
