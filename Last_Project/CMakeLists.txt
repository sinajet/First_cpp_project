cmake_minimum_required(VERSION 3.28)
project(Last_Project)

set(CMAKE_CXX_STANDARD 23)

add_executable(Last_Project main.cpp
        Authors.cpp
        Books.cpp
        Books.hpp
        Libraries.cpp
        Libraries.hpp
        Process.cpp
        Process.hpp
)
