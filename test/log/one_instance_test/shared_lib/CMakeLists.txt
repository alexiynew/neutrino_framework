set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(LIB_NAME "shared_lib")

# Export no symbols by default. 
# This makes e.g. GCC's "visibility behavior" consistent with MSVC's. 
set(CMAKE_C_VISIBILITY_PRESET hidden)
set(CMAKE_CXX_VISIBILITY_PRESET hidden)

add_library(${LIB_NAME} SHARED EXCLUDE_FROM_ALL shared_lib.cpp shared_lib.hpp)

target_include_directories(${LIB_NAME} PRIVATE ${FRAMEWORK_SOURCES} ${TEST_SOURCE_DIR})
# Include path to generated export header
target_include_directories(${LIB_NAME} PUBLIC ${CMAKE_CURRENT_BINARY_DIR})
target_link_libraries(${LIB_NAME} log)

set_target_properties(${LIB_NAME} PROPERTIES FOLDER ${TARGET_PROJECT_FOLDER}/${TEST_PACK_NAME}/${TEST_NAME})

# generate export header automatically
include (GenerateExportHeader)
GENERATE_EXPORT_HEADER(${LIB_NAME}
             BASE_NAME ${LIB_NAME} 
             EXPORT_MACRO_NAME EXPORT
             EXPORT_FILE_NAME generated_${LIB_NAME}_export.hpp)
