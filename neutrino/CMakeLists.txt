add_library(${PROJECT_NAME} STATIC "")

target_include_directories(${PROJECT_NAME}
    PRIVATE
        ${FRAMEWORK_SOURCE_DIR}
        ${FRAMEWORK_DEPENDENCIES_DIR}
)

message(STATUS "Add modules...")

set(MODULES
    common
    game_core
    graphics
    log
    math
    system
    unit_test
)

foreach(MODULE ${MODULES})
    set(MODULE_NAME ${MODULE})
    set(MODULE_DIR ${FRAMEWORK_SOURCE_DIR}/${MODULE})

    message(STATUS "\t${MODULE_NAME}")
    include(${MODULE_DIR}/CMakeLists.txt)
endforeach(MODULE)

set_property(TARGET ${PROJECT_NAME} PROPERTY POSITION_INDEPENDENT_CODE 1)

get_target_property(${PROJECT_NAME}_SOURCES ${PROJECT_NAME} SOURCES)
source_group(TREE ${FRAMEWORK_SOURCE_DIR} FILES ${${PROJECT_NAME}_SOURCES})

install(TARGETS ${PROJECT_NAME} DESTINATION lib)
