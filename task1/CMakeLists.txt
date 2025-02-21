cmake_minimum_required(VERSION 3.14)

project(SampleTest1)

include_directories(${CMAKE_SOURCE_DIR}/external/googletest/googletest)


include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG main
)

FetchContent_MakeAvailable(googletest)

add_executable(SampleTest1
    testavl.cpp
 "test.cpp")

add_executable(SampleTests
    test.cpp
 "test.cpp")

target_link_libraries(SampleTests gtest gtest_main)

target_include_directories(SampleTests PRIVATE external/googletest/googletest)