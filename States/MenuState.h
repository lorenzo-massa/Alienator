//
// Created by th3lo on 25/05/2020.
//

#ifndef ALIENATOR_MENUSTATE_H
#define ALIENATOR_MENUSTATE_H


#include "GameState.h"
#include "../MainMenu.h"

class MenuState : public GameState {
public:
    explicit MenuState();
    void handleInput() override;
    void frameCalculator() override;
    void generateFrame() override;
private:
    MainMenu mainMenu;
};



#endif //ALIENATOR_MENUSTATE_H
