cmake_minimum_required(VERSION 3.8)
project(knockout VERSION 1.0
                 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)

option(ENABLE_COVERAGE FALSE)

if(ENABLE_COVERAGE)
  add_compile_options(--coverage -O0)
  list(APPEND EXTRA_LIBS gcov --coverage)
endif()

# Locate GTest
include(gtest.cmake)
find_package (Threads)

# find_package(GTest REQUIRED)
# include_directories(include ${GTEST_INCLUDE_DIRS})
 
add_executable(knockoutApp src/knockoutApp.cpp src/knockout_functional.cpp)
target_include_directories(knockoutApp PUBLIC include)
target_link_libraries(knockoutApp PUBLIC ${EXTRA_LIBS})

add_executable(knockoutTest tests/knockoutTest.cpp src/knockout_functional.cpp)
target_include_directories(knockoutTest PUBLIC include)
target_link_libraries(knockoutTest PUBLIC gtest ${CMAKE_THREAD_LIBS_INIT} ${EXTRA_LIBS})