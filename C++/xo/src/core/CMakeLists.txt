#core
file(GLOB_RECURSE ALL_CORE_CPP CONFIGURE_DEPENDS
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
)

set(CORE_SOURCES "")
foreach(f ${ALL_CORE_CPP})
    if(NOT f MATCHES "\\.tests?\\.cpp$")
        list(APPEND CORE_SOURCES ${f})
    endif()
endforeach()

add_library(xo-core STATIC ${CORE_SOURCES})

target_include_directories(xo-core PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)


#test
file(GLOB_RECURSE CORE_TEST_FILES CONFIGURE_DEPENDS
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.tests.cpp
)

add_executable(xo-tests ${CORE_TEST_FILES})

target_link_libraries(xo-tests PRIVATE GTest::gtest_main xo-core)

include(GoogleTest)
gtest_discover_tests(xo-tests)