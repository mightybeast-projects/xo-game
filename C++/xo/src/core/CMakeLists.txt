file(GLOB_RECURSE CORE_FILES CONFIGURE_DEPENDS
    src/*.cpp
)

add_executable(xo-tests ${CORE_FILES})

target_link_libraries(
  xo-tests
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(xo-tests)

file(GLOB_RECURSE CORE CONFIGURE_DEPENDS
    src/xo.cpp
)

add_library(xo-core STATIC ${CORE})

target_include_directories(xo-core PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})