//
// Created by th3lo on 23/05/2020.
//

#ifndef ALIENATOR_GAMESTATE_H
#define ALIENATOR_GAMESTATE_H

#include <memory>
#include "SFML/Graphics.hpp"


class GameState {
public:
    explicit GameState();

    virtual void handleInput() = 0;

    virtual void frameCalculator() = 0;

    virtual void generateFrame() = 0;

protected:
    std::shared_ptr<sf::RenderWindow> targetWindow;
};


#endif //ALIENATOR_GAMESTATE_H
