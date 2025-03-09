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

add_executable(SampleTest1 testavl.cpp)

add_executable(SampleTests test.cpp)

target_link_libraries(SampleTests gtest gtest_main)

target_include_directories(SampleTests PRIVATE ${CMAKE_SOURCE_DIR}/external/googletest/googletest)

option(ENABLE_SANITIZERS "Enable Address, Undefined Behavior, and Memory Leak sanitizers" OFF)

if (ENABLE_SANITIZERS)
    set(SANITIZER_FLAGS "-fsanitize=leak,address,undefined")
    target_compile_options(SampleTests PRIVATE ${SANITIZER_FLAGS})
    target_link_options(SampleTests PRIVATE ${SANITIZER_FLAGS})
endif()
