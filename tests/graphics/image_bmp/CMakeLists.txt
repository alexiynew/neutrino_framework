set_sources(PRIVATE_SOURCES
    main.cpp
)

file(GLOB BMP_GOOD "${TEST_SOURCE_DIR}/good/*.bmp")
file(COPY ${BMP_GOOD} DESTINATION ${TEST_BINARY_DIR}/bmp/good)

file(GLOB BMP_BAD "${TEST_SOURCE_DIR}/bad/*.bmp")
file(COPY ${BMP_BAD} DESTINATION ${TEST_BINARY_DIR}/bmp/bad)

file(GLOB BMP_QUESTIONABLE "${TEST_SOURCE_DIR}/questionable/*.bmp")
file(COPY ${BMP_QUESTIONABLE} DESTINATION ${TEST_BINARY_DIR}/bmp/questionable)
