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
#include "../Maps/MapHandler.h"
#include "../Weapons/Bullet.h"
#include "ObserverGame.h"
#include <AssetsManager.h>
#include "Loader.h"

#define GAME_NAME "Alienator"
#define FPS 60
#define SLEEP_TIME 1.0f / FPS

class Game : public ObserverGame{
public:
    Game();
    ~Game();

    static std::shared_ptr<Game> getGame();

    void init();
    void start();
    void save();
    void end();

    void update(int i);

    std::shared_ptr<StateHandler> getStateHandler();
    std::shared_ptr<MapHandler> getMapHandler();
    std::shared_ptr<Hero> getHero();
    std::shared_ptr<sf::Clock> getClock();

    const std::shared_ptr<sf::RenderWindow> &getWindow() const;

    void createHero(int x, int y);

    static void setMyGame(const std::shared_ptr<Game> &myGame);
    void setPtrHero(std::shared_ptr<Hero> ptr);

    void addSubject(std::shared_ptr<SubjectGame> subject);
    void removeSubject(std::shared_ptr<SubjectGame> subject);
    void removeSubject(int i);
    std::shared_ptr<SubjectGame> getSubject(int i);





private:
    std::shared_ptr<sf::Clock> clock;

    std::shared_ptr<MapHandler> ptrMapHandler;
    std::shared_ptr<Hero> ptrHero;
    std::list<Bullet> bullets;
    std::shared_ptr<StateHandler> ptrStateHandler;
    //std::shared_ptr<EnemyBrain> ptrEnemyBrain;

    static std::shared_ptr<Game> myGame;
    std::shared_ptr<sf::RenderWindow> gameWindow;

    std::list<std::shared_ptr<SubjectGame>> subjects;


};


#endif //ALIENATOR_GAME_H
