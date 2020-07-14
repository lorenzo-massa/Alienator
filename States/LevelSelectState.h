//
// Created by Lorenzo Massa on 29/05/2020.
//

#ifndef ALIENATOR_LEVELSELECTSTATE_H
#define ALIENATOR_LEVELSELECTSTATE_H


#include "GameState.h"
#include "../Menu/MainMenu.h"

class LevelSelectState : public GameState {
public:
    explicit LevelSelectState(std::shared_ptr<sf::RenderWindow> targetWindow);

    ~LevelSelectState() override;

    void handleInput() override;

    void generateFrame() override;

private:
    MainMenu mainMenu;

};


#endif //ALIENATOR_LEVELSELECTSTATE_H
