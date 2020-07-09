//
// Created by Lorenzo Massa on 10/06/2020.
//

#include "Loader.h"
#include "../GameCharacter/Hero.h"
#include "Game.h"

void Loader::saveHero(int coins, int ammo, int armor) {
    std::basic_ofstream<char> file = std::ofstream("Data/heroFile.txt");
    file << std::to_string(coins);
    file << " ";
    file << std::to_string(ammo);
    file << " ";
    file << std::to_string(armor);
    file.close();
}

void Loader::loadHero() {

    std::basic_ifstream<char> file = std::ifstream("Data/heroFile.txt");
    if (file.is_open()) {
        int coins, ammo, armor;
        file >> coins;
        file >> ammo;
        file >> armor;
        Game::getGame()->getHero()->setCoins(coins);
        Game::getGame()->getHero()->setAmmo(ammo);
        Game::getGame()->getHero()->setArmor(armor);
        file.close();
    } else {
        Game::getGame()->getHero()->setCoins(0);
        Game::getGame()->getHero()->setAmmo(50);
        Game::getGame()->getHero()->setArmor(50);
    }
}
