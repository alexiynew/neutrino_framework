set_sources(PRIVATE_SOURCES
    main.cpp
)

configure_file(${EXAMPLE_SOURCE_DIR}/shaders/phong_light.frag ${EXAMPLE_BINARY_DIR}/shaders/phong_light.frag COPYONLY)
configure_file(${EXAMPLE_SOURCE_DIR}/shaders/phong_light.vert ${EXAMPLE_BINARY_DIR}/shaders/phong_light.vert COPYONLY)
configure_file(${EXAMPLE_SOURCE_DIR}/shaders/white_light_lamp.frag ${EXAMPLE_BINARY_DIR}/shaders/white_light_lamp.frag COPYONLY)
configure_file(${EXAMPLE_SOURCE_DIR}/shaders/white_light_lamp.vert ${EXAMPLE_BINARY_DIR}/shaders/white_light_lamp.vert COPYONLY)