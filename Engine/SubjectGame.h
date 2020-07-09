//
// Created by Lorenzo Massa on 27/05/2020.
//

#ifndef ALIENATOR_SUBJECTGAME_H
#define ALIENATOR_SUBJECTGAME_H

#include <memory>
#include <list>
#include "ObserverGame.h"

class SubjectGame {
public:
    virtual ~SubjectGame() = default;

    virtual void registerObserver(std::shared_ptr<ObserverGame> observer) = 0;

    virtual void removeObserver(std::shared_ptr<ObserverGame> observer) = 0;

    virtual void notifyObservers(int i) const = 0;

protected:

};

#endif //ALIENATOR_SUBJECTGAME_H
