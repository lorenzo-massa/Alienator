//
// Created by Lorenzo Massa on 04/07/20.
//

#ifndef ALIENATOR_SUBJECT_H
#define ALIENATOR_SUBJECT_H

#include "Observer.h"

class Subject {
public:
    virtual void registerObserver(Observer *o) = 0;

    virtual void removeObserver(Observer *o) = 0;

    virtual void notifyObservers() const = 0;

protected:
    virtual ~Subject() = default;
};

#endif //ALIENATOR_SUBJECT_H
