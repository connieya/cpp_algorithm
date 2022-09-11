cmake_minimum_required(VERSION 3.20)
project(c_cpp_algorithm)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_C_FLAGS "-fexec-charset=CP949 -g -Wall")


add_executable(solved_gold3_16988 solved/gold3/16988.cpp)
add_executable(solved_silver2_16953 solved/silver2/16953.cpp)
add_executable(solved_silver3_16945 solved/silver3/16945.cpp)