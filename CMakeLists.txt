cmake_minimum_required(VERSION 3.20)
project(c_cpp_algorithm)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_C_FLAGS "-fexec-charset=CP949 -g -Wall")

add_executable(solved_platinum5_9376 solved/platinum5/9376.cpp)
add_executable(study_2022_week3_2251 study/2022/week3/2251.cpp)
add_executable(study_2022_week15_16932 study/2022/week15/16932.cpp)
add_executable(study_2022_week3_17086 study/2022/week3/17086.cpp)
add_executable(STL_unique STL/unique.cpp)
add_executable(STL_string STL/string.cpp)