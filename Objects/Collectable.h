//
// Created by Lorenzo Massa on 03/06/2020.
//

#ifndef ALIENATOR_COLLECTABLE_H
#define ALIENATOR_COLLECTABLE_H


#include <memory>
#include <SFML/Graphics.hpp>
#include "PowerUp.h"
#include "../Engine/SubjectGame.h"

class Collectable : public sf::Sprite, public SubjectGame {
public:
    explicit Collectable(sf::Vector2f position);

    Collectable(sf::Vector2f position, PowerUp::TYPE type);

    ~Collectable() override;


    void registerObserver(ObserverGame* observer) override;

    void removeObserver(ObserverGame* observer) override;

    void notifyObservers(int i) const override;

    const PowerUp &getPowerUp() const;

    void setPowerUp(const PowerUp &powerUp);

private:
    const float height{1080};
    const float width{1080};

    PowerUp powerUp;
    std::list<ObserverGame*> observers;

};


#endif //ALIENATOR_COLLECTABLE_H
