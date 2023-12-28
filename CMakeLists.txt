# Example file compied from GTest Cmake Quickstart
# https://google.github.io/googletest/quickstart-cmake.html

cmake_minimum_required(VERSION 3.14)
project(ray_tracer)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


include_directories(src)
# Add all source files in the 'src' directory
file(GLOB SOURCES "src/*.cpp" "src/**/*.cpp")
# Create an executable from the source files
add_executable(app ${SOURCES})

