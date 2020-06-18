//
// Created by Lorenzo Massa on 03/06/2020.
//

#include "Collectable.h"

Collectable::Collectable(sf::Vector2f position){
    powerUp = PowerUp();
    /*
    if(powerUp.getType() == "COINS"){
        setScale(sf::Vector2f(0.075,0.075));
    } else if(powerUp.getType() == "MUNITIONS"){
        setScale(sf::Vector2f(0.075,0.075));
    }else if(powerUp.getType() == "FIRE_RATE"){
        setScale(sf::Vector2f(0.2,0.2));
    }else if(powerUp.getType() == "SPEED"){
        setScale(sf::Vector2f(0.1,0.1));
    }    else if(powerUp.getType() == "DAMAGE_BOOST"){
        setScale(sf::Vector2f(0.075,0.075));
    }    else if(powerUp.getType() == "INVICIBILITY"){
        setScale(sf::Vector2f(0.075,0.075));
    }
    */
    setScale(sf::Vector2f(0.05,0.05));
    setTextureRect(sf::IntRect(0,0,1184,1184));
    sf::Sprite::setPosition(position);


}

Collectable::Collectable(sf::Vector2f position, std::string type){

    setTextureRect(sf::IntRect(0,0,width,height));
    setScale(sf::Vector2f(0.075,0.075));
    sf::Sprite::setPosition(position);

    powerUp = PowerUp(type);

}

Collectable::~Collectable(){
}


const PowerUp &Collectable::getPowerUp() const {
    return powerUp;
}

void Collectable::setPowerUp(const PowerUp &powerUp) {
    Collectable::powerUp = powerUp;
}
