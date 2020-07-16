//
// Created by Leonardo Corsini on 27/05/2020.
//

#include "GameCharacter.h"

GameCharacter::GameCharacter(int hp, int ar, int am, sf::Vector2f s, sf::Vector2f pos, sf::Vector2f dir, float speedCoeff) :
        healthPoint(hp), armor(ar), ammo(am), speed(s), pos(pos), direction(dir), speedBoost(1.0f),
        invincibility(false), fireRateBoost(1.0f), damageBoost(1.0f), speedCoeff(speedCoeff) {

    clockAnimation = std::make_shared<sf::Clock>();
    fireRateClock = std::make_shared<sf::Clock>();
    isLegalJump=false;

}

int GameCharacter::receiveDamage(int points) {
    if (!invincibility){
        healthPoint -= (points / armor);
        setColor(sf::Color::Red);
    }

    return healthPoint;
}

sf::Vector2f GameCharacter::move( float deltaT) {
    float yT;
    float xT;

    if (GameCharacter::getDirection().x == 0.0f) {   //attrito
        if (speed.x > 0)
            speed.x -= 30.0f * 64.0f * deltaT;

        else if (speed.x < 0)
            speed.x += 30.0f * 64.0f * deltaT;

        if (speed.x > -3 && speed.x < 3)//settaggio velocità
            speed.x = 0;
    }
    if (GameCharacter::getDirection().x != 0)
        speed.x = speedCoeff * 64.0f * GameCharacter::getDirection().x;//velocità costante se tengo premuto

    xT = speed.x * deltaT;

    speed.y = speed.y + 98.0f * 64.0f * deltaT; //gravità
    yT = speed.y * deltaT + 0.5f * 98.0f * 64.0f * deltaT * deltaT ;

    if(yT<0)
        GameCharacter::setDirection(sf::Vector2f(GameCharacter::getDirection().x,-1.0f));
    else
        GameCharacter::setDirection(sf::Vector2f(GameCharacter::getDirection().x,1.0f));

    xT = xT * speedBoost;
    yT = yT * speedBoost;

    return {xT, yT};
}

void GameCharacter::jump() {
    speed.y -= 25.0f * BLOCK_SIZE;
}

std::shared_ptr<Bullet> GameCharacter::shot(sf::Vector2f mousePosition) {
    return weapon->fire(sf::Sprite::getPosition().x, sf::Sprite::getPosition().y, weapon->getDamage() * damageBoost,
                        mousePosition);
}

void GameCharacter::removePowerUp() {
    invincibility = false;
    speedBoost = 1.0f;
    fireRateBoost = 1.0f;
    damageBoost = 1.0f;

    powerUpState = false;

}

bool GameCharacter::fireClock(float fireRate) {
    if (fireRateClock->getElapsedTime().asSeconds() > 1.0f / fireRate) {
        fireRateClock->restart();
        return true;
    }
    return false;
}

sf::Vector2f GameCharacter::getPos() const {
    return GameCharacter::pos;
}

void GameCharacter::setPos(sf::Vector2f pos) {
    GameCharacter::pos = pos;
}

int GameCharacter::getHealthPoint() const {
    return GameCharacter::healthPoint;
}

void GameCharacter::setHealthPoint(int healthPoint) {
    GameCharacter::healthPoint = healthPoint;
}

std::shared_ptr<Weapon> GameCharacter::getWeapon() const {
    return weapon;
}

void GameCharacter::setWeapon(std::shared_ptr<Weapon> weapon) {
    this->weapon = weapon;
}

int GameCharacter::getArmor() const {
    return armor;
}

void GameCharacter::setArmor(int armor) {
    GameCharacter::armor = armor;
}

sf::Vector2f GameCharacter::getSpeed() const {
    return speed;
}

void GameCharacter::setSpeed(sf::Vector2f speed) {
    GameCharacter::speed = speed;
}

int GameCharacter::getAmmo() const {
    return ammo;
}

void GameCharacter::setAmmo(int ammo) {
    GameCharacter::ammo = ammo;
}

sf::Vector2f GameCharacter::getDirection() const {
    return direction;
}

void GameCharacter::setDirection(sf::Vector2f direction) {
    GameCharacter::direction = direction;
}

const std::string &GameCharacter::getStrTexture() const {
    return strTexture;
}

void GameCharacter::setStrTexture(const std::string &strTexture) {
    GameCharacter::strTexture = strTexture;
}

float GameCharacter::getSpeedBoost() const {
    return speedBoost;
}

void GameCharacter::setSpeedBoost(float speedBoost) {
    GameCharacter::speedBoost = speedBoost;
}

bool GameCharacter::isInvincibility() const {
    return invincibility;
}

void GameCharacter::setInvincibility(bool invincibility) {
    GameCharacter::invincibility = invincibility;
}

const sf::Clock &GameCharacter::getClockPowerUp() const {
    return clockPowerUp;
}

void GameCharacter::setClockPowerUp(const sf::Clock &clockPowerUp) {
    GameCharacter::clockPowerUp = clockPowerUp;
}

bool GameCharacter::isPowerUpState() const {
    return powerUpState;
}

void GameCharacter::setPowerUpState(bool powerUpState) {
    GameCharacter::powerUpState = powerUpState;
}

float GameCharacter::getFireRateBoost() const {
    return fireRateBoost;
}

void GameCharacter::setFireRateBoost(float fireRateBoost) {
    GameCharacter::fireRateBoost = fireRateBoost;
}

float GameCharacter::getDamageBoost() const {
    return damageBoost;
}

void GameCharacter::setDamageBoost(float damageBoost) {
    GameCharacter::damageBoost = damageBoost;
}

void GameCharacter::resetClockPowerUp() {
    clockPowerUp.restart();
}

float GameCharacter::getSpeedCoeff() const {
    return speedCoeff;
}

void GameCharacter::setSpeedCoeff(float speedCoeff) {
    GameCharacter::speedCoeff = speedCoeff;
}

const std::shared_ptr<sf::Clock> &GameCharacter::getClockAnimation() const {
    return clockAnimation;
}

void GameCharacter::setClockAnimation(const std::shared_ptr<sf::Clock> &clockAnimation) {
    GameCharacter::clockAnimation = clockAnimation;
}

const std::shared_ptr<sf::Clock> &GameCharacter::getFireRateClock() const {
    return fireRateClock;
}

void GameCharacter::setFireRateClock(const std::shared_ptr<sf::Clock> &fireRateClock) {
    GameCharacter::fireRateClock = fireRateClock;
}

PowerUp GameCharacter::getPowerUp() const {
    return powerUp;
}

void GameCharacter::setPowerUp(const PowerUp &powerUp) {
    GameCharacter::powerUp = powerUp;
}

bool GameCharacter::isLegalJump1() const {
    return isLegalJump;
}

void GameCharacter::setIsLegalJump(bool isLegalJump) {
    GameCharacter::isLegalJump = isLegalJump;
}

GameCharacter::~GameCharacter() = default;
