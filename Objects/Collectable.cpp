//
// Created by Lorenzo Massa on 03/06/2020.
//

#include "Collectable.h"

Collectable::Collectable(sf::Vector2f position) {
    powerUp = PowerUp();

    setScale(sf::Vector2f(0.05, 0.05));
    setTextureRect(sf::IntRect(0, 0, 1184, 1184));
    sf::Sprite::setPosition(position);

}

Collectable::Collectable(sf::Vector2f position, PowerUp::TYPE type) {

    setTextureRect(sf::IntRect(0, 0, width, height));
    setScale(sf::Vector2f(0.075, 0.075));
    sf::Sprite::setPosition(position);

    powerUp = PowerUp(type);

}

Collectable::~Collectable() {
}

const PowerUp &Collectable::getPowerUp() const {
    return powerUp;
}

void Collectable::setPowerUp(const PowerUp &powerUp) {
    Collectable::powerUp = powerUp;
}

void Collectable::removeObserver(std::shared_ptr<ObserverGame> observer) {
    observers.remove(observer);
}

void Collectable::registerObserver(std::shared_ptr<ObserverGame> observer) {
    observers.push_back(observer);
}

void Collectable::notifyObservers(int i) const {
    for (const auto &observer : observers)
        observer->update(i);
}
