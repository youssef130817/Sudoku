cmake_minimum_required(VERSION 3.26)
project(sudoku)

set(CMAKE_CXX_STANDARD 17)

add_executable(sudoku main.cpp
        Sudoku.cpp
        Sudoku.hpp)
