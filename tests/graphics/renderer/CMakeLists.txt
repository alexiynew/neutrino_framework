set_sources(PRIVATE_SOURCES
    main.cpp
)

configure_file(${TEST_SOURCE_DIR}/data/lena_1024.png ${TEST_BINARY_DIR}/data/lena_1024.png COPYONLY)
configure_file(${TEST_SOURCE_DIR}/data/lena_32.png ${TEST_BINARY_DIR}/data/lena_32.png COPYONLY)