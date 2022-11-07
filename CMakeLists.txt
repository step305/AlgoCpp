cmake_minimum_required(VERSION 3.23)
project(AlgoCpp)

set(CMAKE_CXX_STANDARD 14)

set(PROJECT_SOURCES
        Utils/utils.cpp Utils/utils.h)

set(TEST_SOURCES
        tests/tests.cpp
        Utils/utils.cpp Utils/utils.h)

add_executable(AlgoCpp main.cpp ${PROJECT_SOURCES})
add_executable(AlgoCpp_Tests ${PROJECT_SOURCES} ${TEST_SOURCES} )
