file(GLOB_RECURSE CORE_TEST_SOURCES CONFIGURE_DEPENDS
    ${CMAKE_CURRENT_SOURCE_DIR}/*.tests.cpp
)

add_executable(xo-tests
    ${CORE_TEST_SOURCES}
)

target_link_libraries(xo-tests PRIVATE
    GTest::gtest_main
    xo-core
)

include(GoogleTest)
gtest_discover_tests(xo-tests)