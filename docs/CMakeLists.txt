find_package(Doxygen)

if (Doxygen_FOUND)
    set(DOCS_INPUT_HEADERS $<TARGET_PROPERTY:${PROJECT_NAME},INTERFACE_SOURCES>)

    set(DOCS_INPUT_DOX ${FRAMEWORK_SOURCE_DIR}/neutrino.dox)

    configure_file(${DOCS_SOURCE_DIR}/Doxyfile.in ${DOCS_BINARY_DIR}/Doxyfile @ONLY)
    configure_file(${DOCS_SOURCE_DIR}/DoxygenLayout.xml ${DOCS_BINARY_DIR}/DoxygenLayout.xml COPYONLY)
    configure_file(${DOCS_SOURCE_DIR}/header.html ${DOCS_BINARY_DIR}/header.html COPYONLY)
    configure_file(${DOCS_SOURCE_DIR}/footer.html ${DOCS_BINARY_DIR}/footer.html COPYONLY)
    configure_file(${DOCS_SOURCE_DIR}/neutrino.css ${DOCS_BINARY_DIR}/neutrino.css COPYONLY)

    add_custom_target(docs ALL
        COMMAND ${CMAKE_COMMAND} -E make_directory ${DOCS_OUTPUT_DIR}
        COMMAND ${DOXYGEN_EXECUTABLE} ${DOCS_BINARY_DIR}/Doxyfile
        WORKING_DIRECTORY ${DOCS_BINARY_DIR}
        DEPENDS ${DOCS_INPUT_HEADERS} ${DOCS_INPUT_DOX}
        COMMENT "Generating documentation"
    )
else ()
    message(WARNING "BUILD_DOCS option is ${BUILD_DOCS}, but Doxygen not found.")
endif ()