set_sources(PUBLIC_SOURCES
    math.hpp

    inc/matrix_type.hpp
    inc/vector_type.hpp

    inc/common_functions.hpp
    inc/constants.hpp
    inc/exponential_functions.hpp
    inc/geometric_functions.hpp
    inc/matrix_functions.hpp
    inc/relational_functions.hpp
    inc/transform_functions.hpp

    inc/matrix_type_details.hpp
    inc/vector_type_details.hpp

    inc/common_functions_details.hpp
    inc/geometric_functions_details.hpp
    inc/matrix_functions_details.hpp
    inc/relational_functions_details.hpp
    inc/trigonometric_functions.hpp
    inc/bezier_functions.hpp
    inc/polygon_functions.hpp

    inc/utility_hash.hpp
    inc/utility_hash_details.hpp
)

set_sources(PRIVATE_SOURCES
    src/polygon_functions.cpp
)

target_sources(${PROJECT_NAME}
    PUBLIC
        ${PUBLIC_SOURCES}
    PRIVATE
        ${PRIVATE_SOURCES}
)

make_install_files_target(include/${MODULE_NAME} ${PUBLIC_SOURCES})
