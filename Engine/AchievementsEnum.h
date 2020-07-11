//
// Created by lorenzo on 11/07/20.
//

#ifndef ALIENATOR_ACHIEVEMENTSENUM_H
#define ALIENATOR_ACHIEVEMENTSENUM_H

#define N_KILLS 10
#define N_JUMPS 5
#define N_BULLETS 100
#define N_DEATHS 10
#define N_FALLS 5

#define N_KILLS_STR "10"
#define N_JUMPS_STR "5"
#define N_BULLETS_STR "100"
#define N_DEATHS_STR "10"
#define N_FALLS_STR "5"

enum class EVENT{
    KILL,
    JUMP,
    BULLET_SHOT,
    DEATH,
    FALL
};

#endif //ALIENATOR_ACHIEVEMENTSENUM_H
