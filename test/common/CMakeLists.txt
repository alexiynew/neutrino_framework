set(TESTS 
    utils
    crc
    signal
    version
    zlib
    utf
)

foreach(TEST ${TESTS})
    set(TEST_NAME ${TEST})
    set(TEST_DIR ${GROUP_DIR}/${TEST})

    include(${TEST_DIR}/CMakeLists.txt)
endforeach(TEST)
