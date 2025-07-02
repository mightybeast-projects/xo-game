file(GLOB_RECURSE UI_TEST_SOURCES CONFIGURE_DEPENDS
	${CMAKE_CURRENT_SOURCE_DIR}/*.tests.cpp
)

add_executable(xo-ui-tests
    ${UI_TEST_SOURCES}
)

target_link_libraries(xo-ui-tests PRIVATE
	GTest::gtest_main
	xo-core
	xo-ui
)

include(GoogleTest)
gtest_discover_tests(xo-ui-tests)