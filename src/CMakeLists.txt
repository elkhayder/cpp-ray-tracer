
include_directories(.)

file(GLOB_RECURSE SOURCES "*.cpp")

add_executable(${CMAKE_PROJECT_NAME} ${SOURCES})
set_target_properties(${CMAKE_PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
