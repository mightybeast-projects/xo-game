file(GLOB_RECURSE UI_TEST_SOURCES CONFIGURE_DEPENDS
	${CMAKE_CURRENT_SOURCE_DIR}/*.tests.cpp 
)

add_executable(xo-ui-tests ${UI_TEST_SOURCES})

target_link_libraries(xo-ui-tests PRIVATE gtest_main xo-core)

file(GLOB_RECURSE ELEMENT_DIRS LIST_DIRECTORIES true "${CMAKE_CURRENT_SOURCE_DIR}/../src/*")

foreach(dir ${ELEMENT_DIRS})
	if(IS_DIRECTORY ${dir})
		target_include_directories(xo-ui-tests PRIVATE ${dir})
	endif()
endforeach()

include(GoogleTest)
gtest_discover_tests(xo-ui-tests)