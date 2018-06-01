get_filename_component(MODULE_NAME ${CMAKE_CURRENT_LIST_DIR} NAME)

message("\tAdd module: ${MODULE_NAME}")

set(PUBLIC_SOURCES
    ${CMAKE_CURRENT_LIST_DIR}/math.hpp

    ${CMAKE_CURRENT_LIST_DIR}/matrix_type.hpp
    ${CMAKE_CURRENT_LIST_DIR}/vector_type.hpp

    ${CMAKE_CURRENT_LIST_DIR}/constants.hpp
    ${CMAKE_CURRENT_LIST_DIR}/common_functions.hpp
    ${CMAKE_CURRENT_LIST_DIR}/exponential_functions.hpp
    ${CMAKE_CURRENT_LIST_DIR}/geometric_functions.hpp
    ${CMAKE_CURRENT_LIST_DIR}/matrix_functions.hpp
    ${CMAKE_CURRENT_LIST_DIR}/relational_functions.hpp
    ${CMAKE_CURRENT_LIST_DIR}/transform_functions.hpp

    ${CMAKE_CURRENT_LIST_DIR}/vector_type_details.hpp
    ${CMAKE_CURRENT_LIST_DIR}/matrix_type_details.hpp

    ${CMAKE_CURRENT_LIST_DIR}/common_functions_details.hpp
    ${CMAKE_CURRENT_LIST_DIR}/geometric_functions_details.hpp
    ${CMAKE_CURRENT_LIST_DIR}/matrix_functions_details.hpp
    ${CMAKE_CURRENT_LIST_DIR}/relational_functions_details.hpp
    ${CMAKE_CURRENT_LIST_DIR}/trigonometric_functions.hpp
)

target_sources(${PROJECT_NAME} 
    PUBLIC 
        ${PUBLIC_SOURCES}
)

source_group(${MODULE_NAME} FILES ${PUBLIC_SOURCES})

