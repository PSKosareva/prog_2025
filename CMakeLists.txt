cmake_minimum_required(VERSION 3.15)

set(PROJECT_NAME lab_2)
project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(task1 "first_task.cpp")
add_executable(task2 "second_task.cpp")