cmake_minimum_required(VERSION 3.15)
project(Alienator)

set(CMAKE_CXX_STANDARD 14)

add_executable(Alienator
        main.cpp

        GameCharacter.h

        States/StateHandler.cpp
        States/StateHandler.h
        States/GameState.cpp
        States/GameState.h)

#SFML Library
include_directories(SFML/include)
link_directories(./SFML/lib)
