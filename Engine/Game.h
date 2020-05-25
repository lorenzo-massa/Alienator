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
#include "../Weapons/Bullet.h"
//#include <Timer.h>

#define GAME_NAME "Alienator"
#define FPS 60
#define SLEEP_TIME 1.0f / FPS

class Game {
public:
    Game();
    ~Game();


    void init();
    void start();
    void play();
    void save();
    void end();

    Timer timer;

    static const std::shared_ptr<sf::RenderWindow> &getGameWindow() const;

private:
    std::shared_ptr<MapHandler> ptrMapHandler;
    std::shared_ptr<Hero> ptrHero;
    std::list<Bullet> bullets;
    std::shared_ptr<StateHandler> ptrStateHandler;
    std::shared_ptr<EnemyBrain> ptrEnemyBrain;

    std::shared_ptr<sf::RenderWindow> gameWindow;
    sf::Clock gameClock;


};


#endif //ALIENATOR_GAME_H
