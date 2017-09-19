cmake_minimum_required (VERSION 2.6)
project (10301 CXX)

if (CMAKE_C_COMPILER_ID MATCHES "GNU|Clang")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -ansi -pedantic -Wall")
endif()
add_executable(10301 10301.cpp)

