cmake_minimum_required(VERSION 3.6)
project(Reviiyot)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall -Weffc++ -std=c++11")

set(SOURCE_FILES Card.cpp Deck.cpp Game.cpp Hand.cpp Player.cpp Card.h Deck.h Game.h Hand.h Player.h Main.cpp)
add_executable(Reviiyot ${SOURCE_FILES})