cmake_minimum_required(VERSION 3.20)
project(aoc)

set(CMAKE_CXX_STANDARD 23)

add_executable(aoc main.cpp)

add_library(aoc_lib
        src/SlidingTotalWindow.cpp src/SlidingTotalWindow.h
        )
target_include_directories(aoc_lib PUBLIC
        src)

add_executable(aoc1 src/aoc1.cpp)
target_link_libraries(aoc1 PUBLIC
        aoc_lib)

add_executable(aoc2 src/aoc2.cpp)
target_link_libraries(aoc2 PUBLIC
        aoc_lib)
