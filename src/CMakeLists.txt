file(GLOB _HEADERS "*.h")
file(GLOB _SOURCES "*.cpp")

set(HEADER_FILES ${_HEADERS}
)
set(SOURCE_FILES ${_SOURCES}
)

if (EXISTS ${SOURCE_FILES})
    # The library contains header and source files.
    add_library(${CMAKE_PROJECT_NAME}_lib SHARED
        ${SOURCE_FILES}
        ${HEADER_FILES}
    )
else()
    # The library only contains header files.
    message("No source files, headers only")
    add_library(${CMAKE_PROJECT_NAME}_lib INTERFACE)
endif()