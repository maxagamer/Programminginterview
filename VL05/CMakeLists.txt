cmake_minimum_required(VERSION 3.24)
project(VL05)

set(CMAKE_CXX_STANDARD 17)

add_executable(VL05 01/Node.h 02/bucket_sort.cpp 03/sort_16_int.cpp 04/my_hash.cpp main.cpp)
