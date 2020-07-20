cmake_minimum_required(VERSION 3.15)

add_subdirectory(lib/googletest)
set(GTEST_SOURCE_DIR, ./lib/googletest)
include_directories(${GTEST_SOURCE_DIR}/include ${GTEST_SOURCE_DIR} ${GTEST_INCLUDE_DIRS})


set(SOURCE_FILES
        mainTests.cpp
        TestCollision.cpp
        TestHero.cpp
        TestEnemyBehavior.cpp

        ../Engine/Game.h
        ../Engine/Game.cpp
        ../Engine/Observer.h
        ../Engine/Subject.h
        ../GameCharacter/GameCharacter.h
        ../GameCharacter/GameCharacter.cpp
        ../GameCharacter/Hero.h
        ../GameCharacter/Enemy.h
        ../GameCharacter/Enemy.cpp
        ../GameCharacter/Hero.cpp
        ../States/StateHandler.cpp
        ../States/StateHandler.h
        ../States/GameState.cpp
        ../States/GameState.h
        ../States/MenuState.cpp
        ../States/MenuState.h
        ../States/LevelSelectState.cpp
        ../States/LevelSelectState.h
        ../Weapons/Weapon.h
        ../Weapons/Bullet.h
        ../Weapons/Bullet.cpp
        ../Weapons/Weapon.cpp
        ../Menu/MainMenu.cpp
        ../Menu/MainMenu.h
        ../Maps/Map.cpp
        ../Maps/Map.h
        ../States/PlayState.cpp
        ../States/PlayState.h
        ../States/PauseState.cpp
        ../States/PauseState.h
        ../Objects/Collectable.cpp
        ../Objects/Collectable.h
        ../Objects/PowerUp.cpp
        ../Objects/PowerUp.h
        ../Assets/AssetsManager.cpp
        ../Assets/AssetsManager.h
        ../Objects/Tile.cpp
        ../Objects/Tile.h
        ../Objects/TileEnum.h
        ../Strategy/AttackBehavior.h
        ../Strategy/ConcreteStrategy/CloseAttack.h
        ../Strategy/ConcreteStrategy/DistanceAttack.h
        ../Strategy/PatrolBehavior.h
        ../Strategy/ConcreteStrategy/GroundPatrolling.h
        ../Strategy/AttackBehavior.cpp
        ../Strategy/PatrolBehavior.cpp
        ../Strategy/ConcreteStrategy/CloseAttack.cpp
        ../Strategy/ConcreteStrategy/DistanceAttack.cpp
        ../Strategy/ConcreteStrategy/GroundPatrolling.cpp
        ../Strategy/BehaviorEnum.h
        ../Engine/AchievementsEnum.h
        ../Engine/Achievements.cpp
        ../Engine/Achievements.h
        )

##
link_directories(SFML-2.5.1/bin)

set (SFML_DIR SFML-2.5.1/lib/cmake/SFML)

find_package(SFML 2.5.1 COMPONENTS audio graphics window system)
include_directories(SFML-2.5.1/include)
include_directories(Assets)
##




add_executable(runTests ${SOURCE_FILES})
target_link_libraries(runTests
        gtest
        gtest_main
        sfml-audio sfml-graphics sfml-window sfml-system
        )
