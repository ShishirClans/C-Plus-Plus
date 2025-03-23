cmake_minimum_required(VERSION 3.30)
project(prog6)

set(CMAKE_CXX_STANDARD 20)

add_executable(prog6 main.cpp
        myQueue.h
        myQueue.cpp
        myStack.h
        myStack.cpp
        Employee.h
        Employee.cpp)
