message("Add libraries...")

set(TARGET_PROJECT_FOLDER src)

add_subdirectory(common)
add_subdirectory(logger)
add_subdirectory(math)
add_subdirectory(unit_test)
add_subdirectory(window)

add_custom_target(${PROJECT_NAME}
    ALL
    DEPENDS common logger math unit_test window
)

set_target_properties(${PROJECT_NAME} 
    PROPERTIES FOLDER src
)
