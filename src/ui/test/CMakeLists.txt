file(GLOB_RECURSE UI_TEST_SOURCES CONFIGURE_DEPENDS
	${CMAKE_CURRENT_SOURCE_DIR}/*.tests.cpp
)

add_executable(xo-ui-tests
    ${UI_TEST_SOURCES}
)

target_link_libraries(xo-ui-tests PRIVATE
	GTest::gtest_main
  	GTest::gmock
  	GTest::gmock_main
	xo-core
	xo-ui
)

target_include_directories(xo-ui-tests PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/mock
)

include(GoogleTest)
gtest_discover_tests(xo-ui-tests)