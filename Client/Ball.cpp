//
// Created by tiquillo on 26/5/21.
//

#include "Ball.h"

void Ball::ChangeSpeed(float deltaTime) {
    if (speed > 0){
        this->speed -= (speed - (uk * (ballMass * gravity))) * deltaTime;
    }

}