file(GLOB_RECURSE CORE_SOURCES CONFIGURE_DEPENDS
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
)

add_library(xo-core STATIC
    ${CORE_SOURCES}
)

target_include_directories(xo-core PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

add_subdirectory(test)