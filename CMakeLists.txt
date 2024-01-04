# Example file compied from GTest Cmake Quickstart
# https://google.github.io/googletest/quickstart-cmake.html

cmake_minimum_required(VERSION 3.14)
project(ray_tracer)
set(CMAKE_CXX_STANDARD 20)


include(cmake/UpdateSubmodules.cmake)

add_subdirectory(external)
add_subdirectory(src)
include(CTest)
add_subdirectory(test)
