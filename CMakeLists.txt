cmake_minimum_required(VERSION 3.15)
project(Alienator)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES
    main.cpp

    GameCharacter.h

    States/StateHandler.cpp
    States/StateHandler.h
    States/GameState.cpp
    States/GameState.h)

#SFML
find_package(SFML 2.5 COMPONENTS system window graphics REQUIRED)
include_directories(${SFML_CLUDE_DIR})

#Executable
add_executable(Alienator main.cpp ${SOURCE_FILES})

target_link_libraries(Alienator smfl-system smfl-window smfl-graphics -static)