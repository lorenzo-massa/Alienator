//
// Created by th3lo on 23/05/2020.
//

#ifndef ALIENATOR_GAMESTATE_H
#define ALIENATOR_GAMESTATE_H

#include <memory>
//#include "SFML/Graphics.hpp"

//typedef std::shared_ptr<sf::RenderWindow> TargetWindow;

class GameState {
public:
    //explicit GameState(TargetWindow targetWindow);

    virtual void handleInput() = 0;

    virtual void frameCalculator() = 0;

    virtual void generateFrame() = 0;

protected:
    //TargetWindow targetWindow;
};


#endif //ALIENATOR_GAMESTATE_H
