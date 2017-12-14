project(math_tests)

get_filename_component(TEST_PACK_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)

message("\tAdd tests: ${TEST_PACK_NAME}")

add_subdirectory(vector_constructor)
add_subdirectory(vector_operators)
add_subdirectory(vector_common)
add_subdirectory(vector_exponential)
add_subdirectory(vector_geometric)
add_subdirectory(vector_relational)
add_subdirectory(vector_trigonometric)

add_subdirectory(matrix_constructor)
add_subdirectory(matrix_math_operators)
add_subdirectory(matrix_access)
add_subdirectory(matrix_assign)
add_subdirectory(matrix_func)
add_subdirectory(matrix_transform)

add_custom_target(${PROJECT_NAME}
    DEPENDS vector_constructor 
            vector_operators 
            vector_common 
            vector_exponential 
            vector_geometric 
            vector_relational 
            vector_trigonometric 
            matrix_constructor 
            matrix_math_operators 
            matrix_access 
            matrix_assign 
            matrix_func 
            matrix_transform 
)
