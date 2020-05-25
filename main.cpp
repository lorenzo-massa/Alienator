#include <iostream>
#include <SFML/Graphics.hpp>
#include "Engine/Game.h"

int main() {

    auto game = Game::getGame();
    game->start();

    return 0;
}