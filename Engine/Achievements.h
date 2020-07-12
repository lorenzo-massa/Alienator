//
// Created by Lorenzo Massa on 11/07/20.
//

#ifndef ALIENATOR_ACHIEVEMENTS_H
#define ALIENATOR_ACHIEVEMENTS_H

#include "Subject.h"
#include <memory>
#include <list>
#include "AchievementsEnum.h"

class Achievements : public Observer{
public:

    Achievements();

    ~Achievements();

    void update(EVENT e, bool &unlocked) override;

    bool isTotKills() const;

    void setTotKills(bool totKills);

    bool isTotJumps() const;

    void setTotJumps(bool totJumps);

    bool isTotBulletsShot() const;

    void setTotBulletsShot(bool totBulletsShot);

    bool isTotDeaths() const;

    void setTotDeaths(bool totDeaths);

    bool isTotFalls() const;

    void setTotFalls(bool totFalls);

    int getCountKills() const;

    void setCountKills(int countKills);

    int getCountJumps() const;

    void setCountJumps(int countJumps);

    int getCountBulletsShot() const;

    void setCountBulletsShot(int countBulletsShot);

    int getCountDeaths() const;

    void setCountDeaths(int countDeaths);

    int getCountFalls() const;

    void setCountFalls(int countFalls);

    const std::shared_ptr<Subject> &getSubject() const;

    void setSubject(const std::shared_ptr<Subject> &subject);

    std::string getAllToString() const;

private:
    bool checkUnlocked();

    bool totKills;
    bool totJumps;
    bool totBulletsShot;
    bool totDeaths;
    bool totFalls;

    int countKills;
    int countJumps;
    int countBulletsShot;
    int countDeaths;
    int countFalls;

    std::shared_ptr<Subject> subject;

};


#endif //ALIENATOR_ACHIEVEMENTS_H
