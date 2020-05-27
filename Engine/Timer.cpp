//
// Created by th3lo on 27/05/2020.
//

#include "Timer.h"

Timer* Timer::myTimer = nullptr;

void Timer::registerObserver(Observer* o) {
    observers.emplace_back(o);

}

void Timer::removeObserver(Observer* o) {
    observers.remove(o);
}

void Timer::notifyObservers() const {
    for(auto &i : observers)
        i->update();
}

void Timer::clearObservers() {
    observers.clear();
}

void Timer::resetTime() {
    mainClock.restart();
}

float Timer::getTime() {
    return mainClock.getElapsedTime().asSeconds();
}



void Timer::check() {
    if(clock.getElapsedTime().asMilliseconds() >= 100){
        clock.restart();
        notifyObservers();
    }
}

Timer & Timer::getTimer() {
    if(myTimer == nullptr)
        myTimer = new Timer();
    return *myTimer;
}

