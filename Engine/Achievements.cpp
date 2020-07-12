//
// Created by Lorenzo Massa on 11/07/20.
//

#include <iostream>
#include "Achievements.h"

Achievements::Achievements() : totKills(false), totJumps(false), totBulletsShot(false), totDeaths(false), totFalls(false),
                               countKills(0), countJumps(0), countBulletsShot(0), countDeaths(0), countFalls(0) {
}

void Achievements::update(EVENT e, bool &unlocked) {
    switch (e) {
        case EVENT::KILL:
            countKills++;
            break;
        case EVENT::JUMP:
            countJumps++;
            break;
        case EVENT::BULLET_SHOT:
            countBulletsShot++;
            break;
        case EVENT::DEATH:
            countDeaths++;
            break;
        case EVENT::FALL:
            countFalls++;
            break;
        default:
            break;
    }

    unlocked = checkUnlocked();
}

bool Achievements::checkUnlocked() {
    bool unlocked = false;

    if(countKills >= N_KILLS && !totKills) {
        totKills = true;
        unlocked = true;
    }else if(countJumps >= N_JUMPS && !totJumps){
        totJumps = true;
        unlocked = true;
    }else if(countBulletsShot >= N_BULLETS && !totBulletsShot){
        totBulletsShot = true;
        unlocked = true;
    }else if(countDeaths >= N_DEATHS && !totDeaths){
        totDeaths = true;
        unlocked = true;
    }else if(countFalls >= N_FALLS && !totFalls){
        totFalls = true;
        unlocked = true;
    }

    return unlocked;
}

bool Achievements::isTotKills() const {
    return totKills;
}

void Achievements::setTotKills(bool totKills) {
    Achievements::totKills = totKills;
}

bool Achievements::isTotJumps() const {
    return totJumps;
}

void Achievements::setTotJumps(bool totJumps) {
    Achievements::totJumps = totJumps;
}

bool Achievements::isTotBulletsShot() const {
    return totBulletsShot;
}

void Achievements::setTotBulletsShot(bool totBulletsShot) {
    Achievements::totBulletsShot = totBulletsShot;
}

bool Achievements::isTotDeaths() const {
    return totDeaths;
}

void Achievements::setTotDeaths(bool totDeaths) {
    Achievements::totDeaths = totDeaths;
}

bool Achievements::isTotFalls() const {
    return totFalls;
}

void Achievements::setTotFalls(bool totFalls) {
    Achievements::totFalls = totFalls;
}

int Achievements::getCountKills() const {
    return countKills;
}

void Achievements::setCountKills(int countKills) {
    Achievements::countKills = countKills;
}

int Achievements::getCountJumps() const {
    return countJumps;
}

void Achievements::setCountJumps(int countJumps) {
    Achievements::countJumps = countJumps;
}

int Achievements::getCountBulletsShot() const {
    return countBulletsShot;
}

void Achievements::setCountBulletsShot(int countBulletsShot) {
    Achievements::countBulletsShot = countBulletsShot;
}

int Achievements::getCountDeaths() const {
    return countDeaths;
}

void Achievements::setCountDeaths(int countDeaths) {
    Achievements::countDeaths = countDeaths;
}

int Achievements::getCountFalls() const {
    return countFalls;
}

void Achievements::setCountFalls(int countFalls) {
    Achievements::countFalls = countFalls;
}

const std::shared_ptr<Subject> &Achievements::getSubject() const {
    return subject;
}

void Achievements::setSubject(const std::shared_ptr<Subject> &subject) {
    Achievements::subject = subject;
}

Achievements::~Achievements() {

}

std::string Achievements::getAllToString() const {

    std::string app;

    if(totKills)
        app += "1\n";
    else
        app += "0\n";

    if(totJumps)
        app += "1\n";
    else
        app += "0\n";

    if(totBulletsShot)
        app += "1\n";
    else
        app += "0\n";

    if(totDeaths)
        app += "1\n";
    else
        app += "0\n";

    if(totFalls)
        app += "1\n";
    else
        app += "0\n";

    app += std::to_string(countKills) + "\n";
    app += std::to_string(countJumps) + "\n";
    app += std::to_string(countBulletsShot) + "\n";
    app += std::to_string(countDeaths) + "\n";
    app += std::to_string(countFalls) + "\n";

    return app;

}
