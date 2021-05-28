//
// Created by tiquillo on 26/5/21.
//

#include "Ball.h"

void Ball::Friction(float deltaTime) {
    if (speed > 0) this->speed -= (float) (speed - (UK * (BALL_MASS * GRAVITY))) * deltaTime;

    else if (speed < 0) speed = 0;
}

void Ball::Throw(float force, float degrees) {
    this->speed = force * (US * (BALL_MASS * GRAVITY));
    this->degree = degrees;
}

void Ball::Bounce(char direction) {
    if (direction == DIAGONAL_COLLITION) {
        pos[0] = -pos[0];
        pos[1] = -pos[1];

        this->degree += 180.0f;
    }

    else if (direction == HORIZONTAL_COLLITION) {
        pos[0] = -pos[0];

        if (this->degree > 270) this->degree = 90 - (this->degree - 270);

        else if (this->degree < 90) this->degree = 270 + (90 - this->degree);

        else if (this->degree < 180) this->degree = 180 + (180 - this->degree);

        else this->degree = 180 - (this->degree - 180);
    }

    else if (direction == VERTICAL_COLLITON) {
        pos[1] = -pos[1];

        if (this->degree < 90)  this->degree = 180 - this->degree;

        else if (this->degree > 270) this->degree = 180 + (360 - this->degree);

        else if (this->degree < 180) this->degree = 180 - this->degree;

        else this->degree = 360 - (this->degree - 180);
    }

    if (this->degree >= 360) this->degree -= 360.0f;
    speed -= speed * ENERGY_LOSS;
}