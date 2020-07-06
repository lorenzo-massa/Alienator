//
// Created by Lorenzo Massa on 03/06/2020.
//

#ifndef ALIENATOR_COLLECTABLE_H
#define ALIENATOR_COLLECTABLE_H


#include <memory>
#include <SFML/Graphics.hpp>
#include "PowerUp.h"
#include "../Engine/SubjectGame.h"

class Collectable : public sf::Sprite, public SubjectGame{
public:
    explicit Collectable(sf::Vector2f position);
    Collectable(sf::Vector2f position, std::string type);
    ~Collectable();


    virtual void registerObserver(std::shared_ptr<ObserverGame> observer);
    virtual void removeObserver(std::shared_ptr<ObserverGame> observer);
    virtual void notifyObservers(int i) const;

    const PowerUp &getPowerUp() const;
    void setPowerUp(const PowerUp &powerUp);

private:
    const float height {512};
    const float width {512};

    PowerUp powerUp;
    std::list<std::shared_ptr<ObserverGame>> observers;

};


#endif //ALIENATOR_COLLECTABLE_H
