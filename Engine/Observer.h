//
// Created by th3lo on 27/05/2020.
//

#ifndef ALIENATOR_OBSERVER_H
#define ALIENATOR_OBSERVER_H


class Observer {
public:
    virtual void update() = 0;

protected:
    virtual ~Observer() = default;
};


#endif //ALIENATOR_OBSERVER_H
