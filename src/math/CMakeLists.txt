get_filename_component(MODULE_NAME ${CMAKE_CURRENT_LIST_DIR} NAME)

message("\tAdd module: ${MODULE_NAME}")

set(PUBLIC_SOURCES
    ${CMAKE_CURRENT_LIST_DIR}/math.hpp

    ${CMAKE_CURRENT_LIST_DIR}/details/matrix_type.hpp
    ${CMAKE_CURRENT_LIST_DIR}/details/vector_type.hpp

    ${CMAKE_CURRENT_LIST_DIR}/details/constants.hpp
    ${CMAKE_CURRENT_LIST_DIR}/details/common_functions.hpp
    ${CMAKE_CURRENT_LIST_DIR}/details/exponential_functions.hpp
    ${CMAKE_CURRENT_LIST_DIR}/details/geometric_functions.hpp
    ${CMAKE_CURRENT_LIST_DIR}/details/matrix_functions.hpp
    ${CMAKE_CURRENT_LIST_DIR}/details/relational_functions.hpp
    ${CMAKE_CURRENT_LIST_DIR}/details/transform_functions.hpp

    ${CMAKE_CURRENT_LIST_DIR}/details/vector_type_details.hpp
    ${CMAKE_CURRENT_LIST_DIR}/details/matrix_type_details.hpp

    ${CMAKE_CURRENT_LIST_DIR}/details/common_functions_details.hpp
    ${CMAKE_CURRENT_LIST_DIR}/details/geometric_functions_details.hpp
    ${CMAKE_CURRENT_LIST_DIR}/details/matrix_functions_details.hpp
    ${CMAKE_CURRENT_LIST_DIR}/details/relational_functions_details.hpp
    ${CMAKE_CURRENT_LIST_DIR}/details/trigonometric_functions.hpp
)

target_sources(${PROJECT_NAME} 
    PUBLIC 
        ${PUBLIC_SOURCES}
)

source_group(${MODULE_NAME} FILES ${PUBLIC_SOURCES})
