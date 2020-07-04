//
// Created by Lorenzo Massa on 27/05/2020.
//

#ifndef ALIENATOR_OBSERVERGAME_H
#define ALIENATOR_OBSERVERGAME_H


class ObserverGame {
public:
    virtual void update(int i) = 0;

protected:
    virtual ~ObserverGame() = default;
};


#endif //ALIENATOR_OBSERVERGAME_H
