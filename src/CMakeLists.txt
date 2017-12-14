message("Add libraries...")

add_subdirectory(common)
add_subdirectory(log)
add_subdirectory(math)
add_subdirectory(unit_test)
add_subdirectory(window)

add_custom_target(${PROJECT_NAME}
	ALL
	DEPENDS common log math unit_test window
)
