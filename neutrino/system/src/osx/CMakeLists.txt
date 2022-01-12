set_sources(PRIVATE_SOURCES
    osx_autorelease_pool.hpp
    osx_autorelease_pool.mm
    osx_application.hpp
    osx_application.mm
    osx_platform_window.cpp
    osx_window.hpp
    osx_window.mm
    osx_context.hpp
    osx_context.mm
)

target_sources(${PROJECT_NAME}
    PRIVATE
        ${PRIVATE_SOURCES}
)

find_library(FOUNDATION Foundation)
find_library(APPKIT AppKit)
target_link_libraries(${PROJECT_NAME} ${FOUNDATION} ${APPKIT})
