set(TESTS 
    matrix_access
    matrix_assign
    matrix_constructor
    matrix_func
    matrix_math_operators
    matrix_transform
    vector_common
    vector_constructor
    vector_exponential
    vector_geometric
    vector_operators
    vector_relational
    vector_trigonometric
)

foreach(TEST ${TESTS})
    set(TEST_NAME ${TEST})
    set(TEST_DIR ${GROUP_DIR}/${TEST})

    include(${TEST_DIR}/CMakeLists.txt)
endforeach(TEST)
