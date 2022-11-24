cmake_minimum_required(VERSION 3.0)

set(CMAKE_CXX_STANDARD 17)
project(set_functions)
add_executable(main set_operations.hpp main.cc)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3")