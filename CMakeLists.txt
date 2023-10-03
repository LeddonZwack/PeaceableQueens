cmake_minimum_required(VERSION 3.26)
project(testPQ)

set(CMAKE_CXX_STANDARD 17)

add_executable(testPQ main.cpp
        src/Square.cpp
        include/Square.h
        src/solverBackTrack.cpp
        include/solverBackTrack.h
)
