cmake_minimum_required(VERSION 3.20)
project(aoc)

set(CMAKE_CXX_STANDARD 23)

add_executable(aoc main.cpp)

add_executable(aoc1 src/aoc1.cpp src/SlidingTotalWindow.cpp src/SlidingTotalWindow.h)
