set_sources(PRIVATE_SOURCES
    main.cpp
    view.hpp
    view.cpp
    event_handler.hpp
    event_handler.cpp
    data_context.hpp
    data_context.cpp
)

configure_file(${EXAMPLE_SOURCE_DIR}/data/UbuntuMono-Regular.ttf ${EXAMPLE_BINARY_DIR}/data/UbuntuMono-Regular.ttf COPYONLY)
