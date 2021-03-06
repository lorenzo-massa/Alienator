//
// Created by Lorenzo Massa on 25/05/2020.
//

#ifndef ALIENATOR_MENUSTATE_H
#define ALIENATOR_MENUSTATE_H


#include "GameState.h"
#include "../Menu/MainMenu.h"

class MenuState : public GameState {
public:
    explicit MenuState(std::shared_ptr<sf::RenderWindow> targetWindow);

    ~MenuState() override;

    void handleInput() override;

    void generateFrame() override;

private:
    MainMenu mainMenu;
};


#endif //ALIENATOR_MENUSTATE_H
