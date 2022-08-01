set_sources(PRIVATE_SOURCES
    main.cpp
)

configure_file(${EXAMPLE_DIR}/shaders/phong_light.frag ${EXAMPLES_BINARY_DIR}/${EXAMPLE_NAME}/shaders/phong_light.frag COPYONLY)
configure_file(${EXAMPLE_DIR}/shaders/phong_light.vert ${EXAMPLES_BINARY_DIR}/${EXAMPLE_NAME}/shaders/phong_light.vert COPYONLY)
configure_file(${EXAMPLE_DIR}/shaders/white_light_lamp.frag ${EXAMPLES_BINARY_DIR}/${EXAMPLE_NAME}/shaders/white_light_lamp.frag COPYONLY)
configure_file(${EXAMPLE_DIR}/shaders/white_light_lamp.vert ${EXAMPLES_BINARY_DIR}/${EXAMPLE_NAME}/shaders/white_light_lamp.vert COPYONLY)