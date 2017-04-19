message("Add libraries...")

add_subdirectory(${FRAMEWORK_SOURCES}/log)
add_subdirectory(${FRAMEWORK_SOURCES}/math)
add_subdirectory(${FRAMEWORK_SOURCES}/unit_test)
add_subdirectory(${FRAMEWORK_SOURCES}/window)

add_custom_target(${PROJECT_NAME}
	ALL
	DEPENDS log math unit_test
)
