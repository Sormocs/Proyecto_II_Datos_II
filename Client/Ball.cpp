//
// Created by tiquillo on 26/5/21.
//

#include "Ball.h"

void Ball::RedSpeed(float deltaTime) {
    if (speed > 0) this->speed -= (float) (speed - (uk * (ballMass * gravity))) * deltaTime;

    else if (speed < 0) speed = 0;
}

void Ball::Kick(float force, float direction) {
    this->speed = force * (us * (ballMass * gravity));
    this->direction = direction
}

void Ball::Move() {

}
