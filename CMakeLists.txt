cmake_minimum_required(VERSION 3.15)
project(Alienator)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES
        Engine/Game.h
        Engine/Game.cpp
        Engine/Observer.h
        Engine/Subject.h
        GameCharacter/GameCharacter.h
        GameCharacter/GameCharacter.cpp
        GameCharacter/Hero.h
        GameCharacter/Enemy.h
        GameCharacter/Enemy.cpp
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
        Weapons/Bullet.cpp
        Weapons/Weapon.cpp
        Menu/MainMenu.cpp
        Menu/MainMenu.h
        Maps/Map.cpp
        Maps/Map.h
        States/PlayState.cpp
        States/PlayState.h
        States/PauseState.cpp
        States/PauseState.h
        Objects/Collectable.cpp
        Objects/Collectable.h
        Objects/PowerUp.cpp
        Objects/PowerUp.h
        Assets/AssetsManager.cpp
        Assets/AssetsManager.h
        Engine/ObserverGame.h
        Engine/SubjectGame.h
        Engine/Observer.h
        Engine/Subject.h
        Engine/AchievementsEnum.h
        Engine/Achievements.cpp
        Engine/Achievements.h
        Strategy/Attack.h
        Strategy/ConcreteStrategy/CloseAttack.h
        Strategy/ConcreteStrategy/DistanceAttack.h
        Strategy/Patrolling.h
        Strategy/ConcreteStrategy/GroundPatrolling.h
        Strategy/Attack.cpp
        Strategy/Patrolling.cpp
        Strategy/ConcreteStrategy/CloseAttack.cpp
        Strategy/ConcreteStrategy/DistanceAttack.cpp
        Strategy/ConcreteStrategy/GroundPatrolling.cpp
        Objects/Tile.cpp Objects/Tile.h Objects/TileEnum.h Strategy/BehaviorEnum.h GameCharacter/EnemyTypeEnum.h)


link_directories(SFML-2.5.1/bin)
#link_libraries(
#        sfml-audio-d-2.dll
#        sfml-graphics-d-2.dll
#        sfml-window-d-2.dll
#        sfml-system-d-2.dll
#)

# Add directory containing FindSFML.cmake to module path
set (SFML_DIR SFML-2.5.1/lib/cmake/SFML)

# Find SFML
find_package(SFML 2.5 COMPONENTS audio graphics window system)
include_directories(SFML-2.5.1/include)
include_directories(Assets)

# Google Tests
add_subdirectory(test)

add_executable(Alienator main.cpp ${SOURCE_FILES})

target_link_libraries(Alienator sfml-audio sfml-graphics sfml-window sfml-system)

