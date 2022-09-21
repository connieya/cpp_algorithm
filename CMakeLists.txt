cmake_minimum_required(VERSION 3.20)
project(c_cpp_algorithm)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_C_FLAGS "-fexec-charset=CP949 -g -Wall")


add_executable(main main.cpp)
add_executable(solved_gold3_2151 solved/gold3/2151.cpp)
add_executable(solved_gold3_2234 solved/gold3/2234.cpp)
add_executable(solved_gold2_12906 solved/gold2/12906.cpp)
add_executable(solved_bronze4_10808 solved/bronze4/10808.cpp)