cmake_minimum_required(VERSION 2.8.9)
project(cpp_code)

set (CMAKE_CXX_STANDARD 14)

option(ENABLE_COVERAGE FALSE)

#if(ENABLE_COVERAGE)
#  add_compile_options(--coverage -O0)
#endif()

# Locate GTest and yaml-cpp
include(gtest.cmake)
find_package (Threads)
add_subdirectory(SYSTEM yaml)
include_directories(include SYSTEM yaml/include)

# find_package(GTest REQUIRED)
# include_directories(include ${GTEST_INCLUDE_DIRS})
 
file(GLOB SOURCES "src/*.cpp")
 
add_executable(knockoutApp src/knockoutApp.cpp src/knockout.cpp)
target_link_libraries(knockoutApp)
#target_link_libraries(knockoutApp --coverage)

add_executable(knockoutTest tests/knockoutTest.cpp src/knockout.cpp)
target_link_libraries(knockoutTest gtest ${CMAKE_THREAD_LIBS_INIT} yaml-cpp)
#target_link_libraries(knockoutTest --coverage gtest ${CMAKE_THREAD_LIBS_INIT} yaml-cpp)
