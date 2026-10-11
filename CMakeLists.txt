cmake_minimum_required(VERSION 3.20)


set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_C_COMPILER gcc-14)
set(CMAKE_CXX_COMPILER g++-14)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(gorillatype LANGUAGES CXX)

add_executable(gorillatype
        src/main.cpp
)
