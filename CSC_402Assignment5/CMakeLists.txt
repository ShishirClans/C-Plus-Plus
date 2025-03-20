cmake_minimum_required(VERSION 3.30)
project(CSC_402Assignment5)

set(CMAKE_CXX_STANDARD 20)

add_executable(CSC_402Assignment5 main.cpp
        Shape.h
        Shape.cpp
        Circle.h
        Circle.cpp
        Triangle.h
        Triangle.cpp
        Rectangle.h
        Rectangle.cpp
        Sphere.h
        Sphere.cpp
        Cuboid.h
        Cuboid.cpp)
