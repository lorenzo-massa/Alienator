//
// Created by th3lo on 25/05/2020.
//

#ifndef ALIENATOR_MENUSTATE_H
#define ALIENATOR_MENUSTATE_H


#include "GameState.h"
#include "../Menu/MainMenu.h"

class MenuState : public GameState {
public:
    MenuState(std::shared_ptr<sf::RenderWindow> targetWindow);
    void handleInput() override;
    void generateFrame() override;
private:
    MainMenu mainMenu;
};



#endif //ALIENATOR_MENUSTATE_H
