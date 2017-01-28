cmake_minimum_required (VERSION 2.6)
project (1002 CXX)

if (CMAKE_C_COMPILER_ID MATCHES "GNU|Clang")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -ansi -pedantic -Wall")
endif()


add_executable(1002 1002.cpp)

