cmake_minimum_required(VERSION 3.0)
cmake_policy(VERSION 3.13)

project(AdventOfCode)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


add_executable(AdventOfCode)
set_property(TARGET AdventOfCode
    PROPERTY CXX_STANDARD 17)


add_subdirectory(src)
add_subdirectory(utils)