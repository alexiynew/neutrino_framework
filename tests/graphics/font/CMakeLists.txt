set_sources(PRIVATE_SOURCES
    main.cpp
)

file(GLOB IMAGES "${TEST_DIR}/fonts/*.ttf")
file(COPY ${IMAGES} DESTINATION ${CMAKE_BINARY_DIR}/${TESTS_DIR_NAME}/fonts)