cmake_minimum_required(VERSION 3.22)
project(AdventOfCode2k24)

include(common.cmake)

set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

setup_executable(hello_world hello_world/hello_world.cpp)
setup_executable(d1p1 day-01/part-1.cpp)
setup_executable(d1p2 day-01/part-2.cpp)
