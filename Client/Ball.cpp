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
    if (energy > 0) this->energy -= (UK * (BALL_MASS * GRAVITY)) * deltaTime;

    else if (energy < 0) energy = 0;

    this->speed = energy / BALL_MASS;
}

/**
 * @brief Throw da los valores iniciales a la bola cuando esta es lanzada por el ordenador o por el jugador.
 * @param force
 * @param degrees
 */
void Ball::Throw(float force, float degrees) {
    this->energy = force - (US * (BALL_MASS * GRAVITY));
    this->speed = (force / BALL_MASS);
    this->degree = degrees;
}

/**
 * @brief Bounce calcula la dirección y la velocidad después de un impacto contra una superficie.
 * @param direction
 */
void Ball::Bounce(char direction) {
    if (direction == DIAGONAL_COLLISION) {
//        pos[0] = -pos[0];
//        pos[1] = -pos[1];

        this->degree += 180.0f;
    } else if (direction == HORIZONTAL_COLLISION) {
//        pos[0] = -pos[0];

        if (this->degree > 270) this->degree = 180 + (360 - this->degree);
//              |
//              |
//        ______|_____
//     a aquí / | \ de aquí
//         < /  |  \ >

        else if (this->degree < 90) this->degree = 180 - this->degree;
//         < \  |  / >
//     a aquí \ | / de aquí
//        ______|_____
//              |
//              |

        else if (this->degree < 180) this->degree = 180 - this->degree;
//         < \  |  / >
//    de aquí \ | / a aquí
//        ______|_____
//              |
//              |
        else this->degree = 360 - (this->degree - 180);
//              |
//              |
//        ______|_____
//    de aquí / | \ a aquí
//         < /  |  \ >
    } else if (direction == VERTICAL_COLLISION) {
        this->degree = 360 - this->degree;
//        pos[1] = -pos[1];
//
//        if (this->degree < 90 || this->degree > 270)  this->degree = 360 - this->degree;
// //              |  / >
// //              | /
// //        ______|______
// //              | \
// //              |  \ >
//
//        else if (this->degree < 180) this->degree = 180 + (180 - this->degree);
// //         < \  |
// //    de aquí \ |
// //        ______|______
// //     a aquí / |
// //         < /  |
//
//        else this->degree = 180 - (this->degree - 180);
// //         < \  |
// //     a aquí \ |
// //        ______|______
// //    de aquí / |
// //         < /  |
    }

    if (this->degree >= 360) this->degree -= 360.0f;
    energy -= energy * ENERGY_LOSS;
}

bool Ball::Clicked(int x, int y) {

    if (pos[0] - 20 < x && x < pos[0] + 40 && pos[1] - 20 < y && y < pos[1] + 40) {
        return true;
    }
    return false;
}

Ball::Ball() {
    this->pos[0] = 0.0;
    this->pos[1] = 0.0;
    this->energy = 0.0;
    this->speed = 0.0;
    this->degree = 0.0;
}
