set_sources(PRIVATE_SOURCES
    main.cpp
)

configure_file(${TEST_SOURCE_DIR}/data/Amethysta-Regular.ttf ${TEST_BINARY_DIR}/data/Amethysta-Regular.ttf COPYONLY)
configure_file(${TEST_SOURCE_DIR}/data/Cookie-Regular.ttf ${TEST_BINARY_DIR}/data/Cookie-Regular.ttf COPYONLY)
configure_file(${TEST_SOURCE_DIR}/data/FrederickatheGreat-Regular.ttf ${TEST_BINARY_DIR}/data/FrederickatheGreat-Regular.ttf COPYONLY)
configure_file(${TEST_SOURCE_DIR}/data/PressStart2P-Regular.ttf ${TEST_BINARY_DIR}/data/PressStart2P-Regular.ttf COPYONLY)
configure_file(${TEST_SOURCE_DIR}/data/UbuntuMono-Regular.ttf ${TEST_BINARY_DIR}/data/UbuntuMono-Regular.ttf COPYONLY)