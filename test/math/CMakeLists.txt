set(TESTS 
    vector_constructor
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

foreach(TEST ${TESTS})
    set(TEST_NAME ${TEST})
    set(TEST_DIR ${GROUP_DIR}/${TEST})

    include(${TEST_DIR}/CMakeLists.txt)
endforeach(TEST)
