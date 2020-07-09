//
// Created by Lorenzo Massa on 29/05/2020.
//

#ifndef ALIENATOR_LEVELSELECTSTATE_H
#define ALIENATOR_LEVELSELECTSTATE_H


#include "GameState.h"
#include "../Menu/MainMenu.h"

class LevelSelectState : public GameState {
public:
    LevelSelectState(std::shared_ptr<sf::RenderWindow> targetWindow);

    void handleInput() override;

    void generateFrame() override;

private:
    MainMenu mainMenu;

};


#endif //ALIENATOR_LEVELSELECTSTATE_H
