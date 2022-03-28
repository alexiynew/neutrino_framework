set(TESTS 
    font
    image_bmp
    image_png
    mesh
    shader
    texture
    #renderer
)

foreach(TEST ${TESTS})
    set(TEST_NAME ${TEST})
    set(TEST_DIR ${GROUP_DIR}/${TEST})

    include(${TEST_DIR}/CMakeLists.txt)
endforeach(TEST)
