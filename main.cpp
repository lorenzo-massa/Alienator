#include "Engine/Game.h"

int main() {

    auto game = Game::getGame();
    game->init();
    game->start();

    return 0;
}