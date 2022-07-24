cmake_minimum_required(VERSION 3.22)
project(array_template)

set(CMAKE_CXX_STANDARD 20)

add_executable(array_template main.cpp ArrayTemplate.cpp ArrayTemplate.h Date.cpp Date.h)
