cmake_minimum_required(VERSION 2.8.9)
project(cpp_code)

set (CMAKE_CXX_STANDARD 14)

# Locate GTest
find_package(GTest REQUIRED)
include_directories(include ${GTEST_INCLUDE_DIRS})
 
file(GLOB SOURCES "src/*.cpp")
 
add_executable(knockoutApp src/knockoutApp.cpp src/knockout.cpp)

add_executable(knockoutTest tests/knockoutTest.cpp src/knockout.cpp)
target_link_libraries(knockoutTest ${GTEST_LIBRARIES} pthread)
