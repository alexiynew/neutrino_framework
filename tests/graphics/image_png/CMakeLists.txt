set_sources(PRIVATE_SOURCES
    main.cpp
)

file(GLOB PNG_GOOD "${TEST_SOURCE_DIR}/png/*.png")
file(COPY ${PNG_GOOD} DESTINATION ${TEST_BINARY_DIR}/png)
