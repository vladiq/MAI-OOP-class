cmake_minimum_required(VERSION 3.5)

project(lab1)

add_executable(lab1
  main.cpp
  angle.cpp
)

set_property(TARGET lab1 PROPERTY CXX_STANDARD 11)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
