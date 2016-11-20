cmake_minimum_required(VERSION 3.6)
project(Reviiyot)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    include/Card.h
    include/Deck.h
    include/Game.h
    include/Hand.h
    include/Player.h
    src/Card.cpp
    src/Deck.cpp
    src/Game.cpp
    src/Hand.cpp
    src/Main.cpp
    src/Player.cpp
    config_1.txt)

add_executable(Reviiyot ${SOURCE_FILES})