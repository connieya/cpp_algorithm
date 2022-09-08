cmake_minimum_required(VERSION 3.20)
project(c_cpp_algorithm)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_C_FLAGS "-fexec-charset=CP949 -g -Wall")


add_executable(STL_vector STL/vector.cpp)
add_executable(main main.cpp)
add_executable(solved_gold4_9935 solved/gold4/9935.cpp)
add_executable(jungle_week2_6549 jungle/week2/6549.cpp)
add_executable(solved_gold1_3015 solved/gold1/3015.cpp)