set_sources(PRIVATE_SOURCES
    main.cpp
)

configure_file(${EXAMPLE_DIR}/data/UbuntuMono-Regular.ttf ${EXAMPLES_BINARY_DIR}/${EXAMPLE_NAME}/data/UbuntuMono-Regular.ttf COPYONLY)
