cmake_minimum_required(VERSION 3.10)
project(DSA)                   # project name
add_compile_options(-g -Werror) #do not allow any warning

set(CMAKE_CXX_STANDARD 14)            # C++14

add_executable(heap heap.cpp)  # set the executable file name
