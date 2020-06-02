cmake_minimum_required(VERSION 3.15)
project(Alienator)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES
        Engine/Game.h
        Engine/Game.cpp
        Engine/Observer.h
        Engine/Subject.h
        Engine/Timer.cpp
        Engine/Timer.h
        GameCharacter/GameCharacter.h
        GameCharacter/Hero.h
        GameCharacter/Enemy.h
        GameCharacter/Enemy.cpp
        GameCharacter/GameCharacter.cpp
        GameCharacter/Hero.cpp
        States/StateHandler.cpp
        States/StateHandler.h
        States/GameState.cpp
        States/GameState.h
        States/MenuState.cpp
        States/MenuState.h
        States/LevelSelectState.cpp
        States/LevelSelectState.h
        Weapons/Weapon.h
        Weapons/Bullet.h
        Weapons/Gun.h
        Weapons/Assault.h
        Weapons/Shotgun.h
        Weapons/Minigun.h
        Weapons/Sniper.h
        Weapons/Assault.cpp
        Weapons/Bullet.cpp
        Weapons/Gun.cpp
        Weapons/Minigun.cpp
        Weapons/Shotgun.cpp
        Weapons/Sniper.cpp
        Weapons/Weapon.cpp
        Behavior/HeroBehavior/HeroBehavior.h
        Behavior/EnemyBehavior/EnemyBehavior.h
        Behavior/HeroBehavior/HeroBehavior.cpp
        Behavior/EnemyBehavior/EnemyBehavior.cpp
        Behavior/EnemyBehavior/Sentinel.h
        Behavior/EnemyBehavior/Sentinel.cpp
        Behavior/EnemyBehavior/Guard.h
        Behavior/EnemyBehavior/Guard.cpp
        Behavior/EnemyBehavior/Wizard.cpp
        Behavior/EnemyBehavior/Wizard.h
        Behavior/HeroBehavior/Archer.h
        Behavior/HeroBehavior/Archer.cpp
        Behavior/HeroBehavior/Boxer.h
        Behavior/HeroBehavior/Boxer.cpp
        Behavior/HeroBehavior/Mage.h
        Behavior/HeroBehavior/Mage.cpp
        MainMenu.cpp
        MainMenu.h
        Maps/MapHandler.cpp
        Maps/MapHandler.h
        Maps/Map.cpp
        Maps/Map.h
        Maps/MapFactory.cpp
        Maps/MapFactory.h
        States/PlayState.cpp
        States/PlayState.h)


link_directories(SFML-2.5.1/bin)
link_libraries(
        sfml-audio-d-2.dll
        sfml-graphics-d-2.dll
        sfml-window-d-2.dll
        sfml-system-d-2.dll
)

# Add directory containing FindSFML.cmake to module path
set (SFML_DIR SFML-2.5.1/lib/cmake/SFML)

# Find SFML
find_package(SFML 2.5 COMPONENTS audio graphics window system)
include_directories(SFML-2.5.1/include)
include_directories(Assets)

add_executable(Alienator main.cpp ${SOURCE_FILES})

target_link_libraries(Alienator sfml-audio sfml-graphics sfml-window sfml-system)

