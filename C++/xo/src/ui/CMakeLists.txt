#ui
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/lib/raylib)

file(GLOB_RECURSE UI_SOURCES CONFIGURE_DEPENDS
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.hpp
)

add_executable(xo-game ${UI_SOURCES})

target_link_libraries(xo-game raylib GTest::gtest_main xo-core)
 
target_include_directories(xo-game PRIVATE
	${CMAKE_CURRENT_SOURCE_DIR}/src
	${CMAKE_CURRENT_SOURCE_DIR}/lib/raygui/src
	${CMAKE_CURRENT_SOURCE_DIR}/lib/raygui/styles/cyber
)

file(GLOB_RECURSE ELEMENT_DIRS LIST_DIRECTORIES true "${CMAKE_CURRENT_SOURCE_DIR}/src/*")

foreach(dir ${ELEMENT_DIRS})
	if(IS_DIRECTORY ${dir})
		target_include_directories(xo-game PRIVATE ${dir})
	endif()
endforeach()

# #test 
# file(GLOB_RECURSE UI_TEST_SOURCES CONFIGURE_DEPENDS
#     ${CMAKE_CURRENT_SOURCE_DIR}/src/*.tests.cpp
# )

# add_executable(xo-ui-tests ${UI_TEST_SOURCES})

# target_link_libraries(xo-ui-tests PRIVATE GTest::gtest_main xo-core)

# include(GoogleTest)
# gtest_discover_tests(xo-ui-tests)