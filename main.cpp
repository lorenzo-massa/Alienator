#include <iostream>
#include <SFML/Graphics.hpp>
#include "Engine/Game.h"
#include "Objects/PowerUp.h"

int main() {

    auto game = Game::getGame();
    game->init();
    game->start();

    return 0;
}