cmake_minimum_required(VERSION 3.20)
project(c_cpp_algorithm)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_C_FLAGS "-fexec-charset=CP949 -g -Wall")


add_executable(solved_gold2_17780 solved/gold2/17780.cpp)
add_executable(solved_gold4_14466 solved/gold4/14466.cpp)
add_executable(solved_silver4_14469 solved/silver4/14469.cpp)