set_sources(PRIVATE_SOURCES
    main.cpp
)

file(GLOB BMP_GOOD "${TEST_DIR}/good/*.bmp")
file(COPY ${BMP_GOOD} DESTINATION ${CMAKE_BINARY_DIR}/${TESTS_DIR_NAME}/bmp/good)

file(GLOB BMP_BAD "${TEST_DIR}/bad/*.bmp")
file(COPY ${BMP_BAD} DESTINATION ${CMAKE_BINARY_DIR}/${TESTS_DIR_NAME}/bmp/bad)

file(GLOB BMP_QUESTIONABLE "${TEST_DIR}/questionable/*.bmp")
file(COPY ${BMP_QUESTIONABLE} DESTINATION ${CMAKE_BINARY_DIR}/${TESTS_DIR_NAME}/bmp/questionable)
