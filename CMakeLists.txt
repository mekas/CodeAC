cmake_minimum_required(VERSION 3.3)
project(CodeAC)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.c main.h compute.c compute.h io.c io.h structure.c structure.h libstring.c libstring.h)
add_executable(CodeAC ${SOURCE_FILES})