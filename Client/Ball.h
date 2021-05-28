//
// Created by tiquillo on 26/5/21.
//

#ifndef CLIENT_BALL_H
#define CLIENT_BALL_H

#include "Constants.h"

class Ball {
public:
    float pos[2];
    float speed;
    float degree;
    void Throw(float force, float direction);
    void Bounce(char direction);
    void Friction(float deltaTime);
};


#endif //CLIENT_BALL_H
