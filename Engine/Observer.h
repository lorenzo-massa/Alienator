//
// Created by Lorenzo Massa on 04/07/20.
//

#ifndef ALIENATOR_OBSERVER_H
#define ALIENATOR_OBSERVER_H


#include "AchievementsEnum.h"

class Observer {
public:
    virtual void update(EVENT e, bool &unlocked) = 0;

protected:
    virtual ~Observer() = default;
};

#endif //ALIENATOR_OBSERVER_H
