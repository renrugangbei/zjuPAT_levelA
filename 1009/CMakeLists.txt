cmake_minimum_required (VERSION 2.6)
project (1009 CXX)

if (CMAKE_C_COMPILER_ID MATCHES "GNU|Clang")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -ansi -pedantic -Wall")
endif()
add_executable(1009 1009.cpp)

