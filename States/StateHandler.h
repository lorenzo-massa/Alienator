//
// Created by Lorenzo Massa on 23/05/2020.
//

#ifndef ALIENATOR_STATEHANDLER_H
#define ALIENATOR_STATEHANDLER_H


#include <stack>
#include <memory>
#include <iostream>

#include "GameState.h"


class StateHandler {
public:
    StateHandler();

    ~StateHandler();

    void addState(const std::shared_ptr<GameState> &topState);

    void removeState();

    const std::shared_ptr<GameState> &getState();

private:
    std::stack<std::shared_ptr<GameState>> stateBuffer;
};


#endif //ALIENATOR_STATEHANDLER_H
