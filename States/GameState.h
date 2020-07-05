//
// Created by Lorenzo Massa on 23/05/2020.
//

#ifndef ALIENATOR_GAMESTATE_H
#define ALIENATOR_GAMESTATE_H

#include <memory>
#include "SFML/Graphics.hpp"


class GameState {
public:
    explicit GameState(std::shared_ptr<sf::RenderWindow> targetWindow);

    virtual void handleInput() = 0;

    virtual void generateFrame() = 0;

    const std::shared_ptr<sf::RenderWindow> &getTargetWindow() const;

    void setTargetWindow(const std::shared_ptr<sf::RenderWindow> &targetWindow);

    int getLevel() const;

    void setLevel(int level);

protected:
    std::shared_ptr<sf::RenderWindow> targetWindow;
    int level;

};


#endif //ALIENATOR_GAMESTATE_H
