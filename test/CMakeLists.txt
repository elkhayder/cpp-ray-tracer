cmake_minimum_required(VERSION 3.14)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE SOURCES "*.cpp" ${CMAKE_SOURCE_DIR}/src/**/*.cpp)
if(BUILD_TESTING)
    enable_testing()

    add_executable(
        ${CMAKE_PROJECT_NAME}_test
        ${SOURCES}
    )
    # set_target_properties(${CMAKE_PROJECT_NAME}_test PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
        
    target_link_libraries(
        ${CMAKE_PROJECT_NAME}_test
        GTest::gtest_main
    )
            
    include(GoogleTest)
    gtest_discover_tests(${CMAKE_PROJECT_NAME}_test)
endif()