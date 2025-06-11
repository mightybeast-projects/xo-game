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

file(GLOB_RECURSE SOURCE_FILES CONFIGURE_DEPENDS
    src/core/**/*.cpp
    src/core/**/*.hpp
)

add_executable(xo-tests ${SOURCE_FILES})

target_link_libraries(
  xo-tests
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(xo-tests)