/**
 * @file Ball.h
 * @author Luis Delgado
 * @brief Archivo header de la clase Ball.
 */

#ifndef CLIENT_BALL_H
#define CLIENT_BALL_H

#include "Constants.h"
/**
 * @brief Clase Ball encargada del control de la ubicación de la bola.
 */
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
