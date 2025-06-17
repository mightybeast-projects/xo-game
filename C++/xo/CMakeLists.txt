cmake_minimum_required(VERSION 3.14)
project(my_project)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
  DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

file(GLOB_RECURSE CORE_FILES CONFIGURE_DEPENDS
    src/core/*.cpp
    src/core/*.hpp
)

add_executable(xo-tests ${CORE_FILES})

target_link_libraries(
  xo-tests
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(xo-tests)

file(GLOB_RECURSE UI_FILES CONFIGURE_DEPENDS
    src/ui/*.cpp
    src/ui/*.hpp
)

add_executable(xo-game ${UI_FILES}) 

add_subdirectory(lib/raylib)

target_link_libraries(xo-game raylib)

target_include_directories(xo-game PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/lib/raygui/src
  ${CMAKE_SOURCE_DIR}/src/core
)

file(GLOB_RECURSE ELEMENT_DIRS LIST_DIRECTORIES true "${CMAKE_SOURCE_DIR}/src/ui/*")

foreach(dir ${ELEMENT_DIRS})
    if(IS_DIRECTORY ${dir})
        target_include_directories(xo-game PRIVATE ${dir})
    endif()
endforeach()
