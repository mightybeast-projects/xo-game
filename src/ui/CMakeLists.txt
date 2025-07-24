#ui-lib
file(GLOB_RECURSE UI_SOURCES CONFIGURE_DEPENDS
	${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
)

add_library(xo-ui STATIC
	${UI_SOURCES}
)

target_link_libraries(xo-ui PRIVATE
	raylib
	xo-core
)

target_include_directories(xo-ui PUBLIC
	${CMAKE_CURRENT_SOURCE_DIR}/src
	${CMAKE_CURRENT_SOURCE_DIR}/lib/raygui/src
	${CMAKE_CURRENT_SOURCE_DIR}/lib/raygui/styles/cyber
)

file(GLOB_RECURSE INCLUDE_DIRS LIST_DIRECTORIES true "${CMAKE_CURRENT_SOURCE_DIR}/src/*")

foreach(dir ${INCLUDE_DIRS})
	if(IS_DIRECTORY ${dir})
		target_include_directories(xo-ui PUBLIC ${dir})
	endif()
endforeach()


#game
add_executable(xo-game
	${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
)

target_link_libraries(xo-game PRIVATE
	xo-ui
	xo-core
	raylib
)


#ui-tests
add_subdirectory(test)