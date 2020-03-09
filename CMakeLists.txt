cmake_minimum_required(VERSION 3.4)
project(knockout VERSION 1.0)

set (CMAKE_CXX_STANDARD 14)

option(ENABLE_COVERAGE FALSE)

if(ENABLE_COVERAGE)
  add_compile_options(--coverage -O0)
  list(APPEND EXTRA_LIBS gcov --coverage)
endif()

# Locate GTest
include(gtest.cmake)
find_package (Threads)
include_directories(include)

# find_package(GTest REQUIRED)
# include_directories(include ${GTEST_INCLUDE_DIRS})
 
file(GLOB SOURCES "src/*.cpp")
 
add_executable(knockoutApp src/knockoutApp.cpp src/knockout.cpp)
target_link_libraries(knockoutApp ${EXTRA_LIBS})

add_executable(knockoutTest tests/knockoutTest.cpp src/knockout.cpp)
target_link_libraries(knockoutTest gtest ${CMAKE_THREAD_LIBS_INIT} ${EXTRA_LIBS})