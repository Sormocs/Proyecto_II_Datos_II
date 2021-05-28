/**
 * @file Ball.cpp
 * @author Luis Delgado
 * @brief Archivo cpp de la clase Ball.
 */

#include "Ball.h"
/**
 * @brief Friction disminuye la velocidad de la bola con el paso del tiempo con base en su fricción.
 * @param deltaTime
 */
void Ball::Friction(float deltaTime) {
    if (speed > 0) this->speed -= (float) (speed - (UK * (BALL_MASS * GRAVITY))) * deltaTime;

    else if (speed < 0) speed = 0;
}

/**
 * @brief Throw da los valores iniciales a la bola cuando esta es lanzada por el ordenador o por el jugador.
 * @param force
 * @param degrees
 */
void Ball::Throw(float force, float degrees) {
    this->speed = force * (US * (BALL_MASS * GRAVITY));
    this->degree = degrees;
}

/**
 * @brief Bounce calcula la dirección y la velocidad después de un impacto contra una superficie.
 * @param direction
 */
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