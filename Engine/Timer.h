//
// Created by th3lo on 27/05/2020.
//

#ifndef ALIENATOR_TIMER_H
#define ALIENATOR_TIMER_H


#include <list>
#include <SFML/System/Clock.hpp>
#include "Observer.h"
#include "Subject.h"

class Timer : public Subject {
public:
    static Timer& getTimer();

    void registerObserver(Observer* o) override;
    void removeObserver(Observer* o) override;
    void notifyObservers() const override;
    void clearObservers();
    void check();
    float getTime();
    void resetTime();
    std::list<Observer*> observers;
private:
    static Timer* myTimer;
    Timer() = default;
    sf::Clock clock;
    sf::Clock mainClock;
};


#endif //ALIENATOR_TIMER_H
