#lib
file(GLOB_RECURSE CORE_FILES CONFIGURE_DEPENDS
	src/xo.cpp
	src/xo.hpp
)

add_library(xo-core STATIC ${CORE_FILES})

target_include_directories(xo-core PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)


#tests
file(GLOB_RECURSE TEST_FILES CONFIGURE_DEPENDS
	src/*.tests.cpp
)

add_executable(xo-tests ${TEST_FILES})

target_link_libraries(xo-tests GTest::gtest_main xo-core)

include(GoogleTest)

gtest_discover_tests(xo-tests)