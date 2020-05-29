//
// Created by Lorenzo Massa on 23/05/2020.
//

#include "StateHandler.h"


StateHandler::StateHandler() {

}

void StateHandler::addState(const std::shared_ptr<GameState> &topState) {
    //stateBuffer = NULL
    stateBuffer.push(topState);
}

void StateHandler::removeState() {
    if (!stateBuffer.empty())
        stateBuffer.pop();
    else
        std::cerr << "Stack empty!";
}

const std::shared_ptr<GameState> &StateHandler::getState() {
    return stateBuffer.top();
}
