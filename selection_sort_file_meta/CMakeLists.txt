cmake_minimum_required(VERSION 3.0)

set(CMAKE_CXX_STANDARD 17)
project(selection_sort_file_meta)
add_executable(main sort_file.hpp my_sort.hpp main.cc)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3")