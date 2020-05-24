cmake_minimum_required(VERSION 3.15)
project(Alienator)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES
    main.cpp

        GameCharacter/GameCharacter.h

    States/StateHandler.cpp
    States/StateHandler.h
    States/GameState.cpp
    States/GameState.h Weapons/Weapon.h Weapons/Bullet.h GameCharacter/Hero.h GameCharacter/Enemy.h Weapons/Gun.h Weapons/Assault.h Weapons/Shotgun.h Weapons/Minigun.h Weapons/Sniper.h)


link_directories(SFML-2.5.1/bin)
link_libraries(sfml-audio-d-2.dll
        sfml-graphics-d-2.dll
        sfml-window-d-2.dll
        sfml-system-d-2.dll
        )

#Add DLLs
#include_directories("${PROJECT_SOURCE_DIR}/SFML-2.5.1/bin")
#add_subdirectory(SFML-2.5.1/bin)


# Add directory containing FindSFML.cmake to module path
set (SFML_DIR SFML-2.5.1/lib/cmake/SFML)
# Find SFML
find_package(SFML 2.5 COMPONENTS audio graphics window system)
include_directories(SFML-2.5.1/include)

add_executable(Alienator ${SOURCE_FILES})

target_link_libraries(Alienator sfml-audio sfml-graphics sfml-window sfml-system)

