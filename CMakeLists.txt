cmake_minimum_required(VERSION 3.10)
project(szwlib CXX)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_CXX_FLAGS "-g3 -O0 -pg -Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "-g3 -O0 -pg")
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -s -DNDEBUG -march=native")

# OpenMP
find_package(OpenMP REQUIRED)
if(OpenMP_FOUND)
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} ${OpenMP_CXX_FLAGS}")
endif()

add_executable(example main.cpp)
