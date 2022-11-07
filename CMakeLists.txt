cmake_minimum_required(VERSION 3.20)
project(c_cpp_algorithm)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_C_FLAGS "-fexec-charset=CP949 -g -Wall")


add_executable(solved_bronze5_3003 solved/bronze5/3003.cpp)
add_executable(solved_bronze1_1110 solved/bronze1/1110.cpp)