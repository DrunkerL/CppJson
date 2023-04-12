cmake_minimum_required(VERSION 3.25)
project(CppJson)

set(CMAKE_CXX_STANDARD 11)

add_executable(CppJson main.cpp json/Json.cpp json/Json.h json/Parser.cpp json/Parser.h)
