//
// Created by Lorenzo Massa on 25/05/2020.
//

#ifndef ALIENATOR_GAME_H
#define ALIENATOR_GAME_H

#include <list>
#include <memory>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "../States/StateHandler.h"
#include "../States/MenuState.h"
#include "../GameCharacter/Hero.h"
#include "../Weapons/Bullet.h"
#include "ObserverGame.h"
#include <AssetsManager.h>
#include "../Maps/Map.h"
#include "Achievements.h"

#define GAME_NAME "Alienator"
#define FPS 60
#define SLEEP_TIME 1.0f / FPS
#define BLOCK_SIZE 64

class Game : public ObserverGame {
public:
    Game();

    ~Game();

    static std::shared_ptr<Game> getGame();

    void init();

    void start();

    void save();

    void update(int i) override;

    std::shared_ptr<StateHandler> getStateHandler();

    std::shared_ptr<Map> getMap();

    std::shared_ptr<Hero> getHero();

    std::shared_ptr<sf::Clock> getClock();

    const std::shared_ptr<sf::RenderWindow> &getWindow() const;

    void createHero(int x, int y);

    void setPtrHero(std::shared_ptr<Hero> ptr);

    void addSubject(std::shared_ptr<SubjectGame> subject);

    void removeSubject(std::shared_ptr<SubjectGame> subject);

    void removeSubject(int i);

    std::shared_ptr<SubjectGame> getSubject(int i);

    const std::vector<bool> &getLevelCompleted() const;

    void setLevelCompleted(const std::vector<bool> &levelCompleted);

    void killHero();

    void finishLevel(int i);

    const std::shared_ptr<Achievements> &getAchievements() const;

    void setAchievements(const std::shared_ptr<Achievements> &achievements);

private:
    std::shared_ptr<sf::Clock> clock;

    std::shared_ptr<Map> ptrMap;
    std::shared_ptr<Hero> ptrHero;
    std::shared_ptr<StateHandler> ptrStateHandler;

    static std::shared_ptr<Game> myGame;
    std::shared_ptr<sf::RenderWindow> gameWindow;

    std::list<std::shared_ptr<SubjectGame>> subjects;

    std::vector<bool> levelCompleted;

    std::shared_ptr<Achievements> achievements;

    void loadAchievements();

    std::shared_ptr<AssetManager> assetManager;
};


#endif //ALIENATOR_GAME_H
