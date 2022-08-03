cmake_minimum_required(VERSION 3.20)
project(c_cpp_algorithm)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_C_FLAGS "-fexec-charset=CP949 -g -Wall")

add_executable(solved_gold1_17472 solved/gold1/17472.cpp)
add_executable(solved_gold3_16940 solved/gold3/16940.cpp)
add_executable(solved_gold4_1695 solved/gold4/1695.cpp)
add_executable(solved_gold4_2643 solved/gold4/2643.cpp)