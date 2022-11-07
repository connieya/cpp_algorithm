cmake_minimum_required(VERSION 3.20)
project(c_cpp_algorithm)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_C_FLAGS "-fexec-charset=CP949 -g -Wall")


add_executable(solved_bronze5_3003 solved/bronze5/3003.cpp)
add_executable(solved_bronze1_1110 solved/bronze1/1110.cpp)
add_executable(solved_gold3_7579 solved/gold3/7579.cpp)
add_executable(solved_gold5_12865 solved/gold5/12865.cpp)
add_executable(inflearn_5.dp_9 inflearn/5.dp/9.cpp)
add_executable(inflearn_5.dp_10 inflearn/5.dp/10.cpp)
add_executable(inflearn_5.dp_11 inflearn/5.dp/11.cpp)