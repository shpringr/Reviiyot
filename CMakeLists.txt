cmake_minimum_required(VERSION 3.6)
project(Reviiyot)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES  Main.cpp include src)
add_executable(Reviiyot ${SOURCE_FILES})