set_sources(PUBLIC_SOURCES
    color.hpp
    font.hpp
    image.hpp
    mesh.hpp
    renderer.hpp
    shader.hpp
    texture.hpp
    uniform.hpp

    inc/types.hpp
)

set_sources(PRIVATE_SOURCES
    src/mesh.cpp
    src/shader.cpp
    src/texture.cpp
    src/uniform.cpp

    src/font/font.cpp
    src/font/tables/character_to_glyph_index_mapping.cpp
    src/font/tables/character_to_glyph_index_mapping.hpp
    src/font/tables/font_header.cpp
    src/font/tables/font_header.hpp
    src/font/tables/glyph_data.cpp
    src/font/tables/glyph_data.hpp
    src/font/tables/horizontal_header.cpp
    src/font/tables/horizontal_header.hpp
    src/font/tables/horizontal_metrics.cpp
    src/font/tables/horizontal_metrics.hpp
    src/font/tables/index_to_location.cpp
    src/font/tables/index_to_location.hpp
    src/font/tables/maximum_profile.cpp
    src/font/tables/maximum_profile.hpp
    src/font/tables/naming.cpp
    src/font/tables/naming.hpp
    src/font/tables/os2.cpp
    src/font/tables/os2.hpp
    src/font/types.hpp

    src/image/bmp.cpp
    src/image/bmp.hpp
    src/image/image_info.hpp
    src/image/image.cpp
    src/image/png.cpp
    src/image/png.hpp

    src/opengl/opengl.cpp
    src/opengl/opengl.hpp

    src/render/render_command.hpp
    src/render/render_command.cpp
    src/render/renderer_impl.hpp
    src/render/renderer.cpp

    src/render/opengl/attributes.hpp
    src/render/opengl/opengl_logger.cpp
    src/render/opengl/opengl_logger.hpp
    src/render/opengl/opengl_mesh.cpp
    src/render/opengl/opengl_mesh.hpp
    src/render/opengl/opengl_renderer.cpp
    src/render/opengl/opengl_renderer.hpp
    src/render/opengl/opengl_shader.cpp
    src/render/opengl/opengl_shader.hpp
    src/render/opengl/opengl_texture.cpp
    src/render/opengl/opengl_texture.hpp
)

target_sources(${PROJECT_NAME}
    PUBLIC
        ${PUBLIC_SOURCES}
    PRIVATE
        ${PRIVATE_SOURCES}
)

install(FILES ${FRAMEWORK_DEPENDENCIES_DIR}/KHR/khrplatform.h DESTINATION dependencies/KHR)

make_install_files_target(include/${MODULE} ${PUBLIC_SOURCES})

# Link with OpenGL
find_package(OpenGL REQUIRED)

target_link_libraries(${PROJECT_NAME} PRIVATE ${OPENGL_LIBRARIES})
