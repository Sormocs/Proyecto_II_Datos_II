/**
 * @file PhysController.h
 * @author Luis Delgado
 * @brief Archivo header de la clase PhysController.
 */

#include <chrono>
#include <cmath>
#include "PlayerObs.h"
#include "Ball.h"

#pragma once

typedef std::chrono::high_resolution_clock Time;
typedef std::chrono::milliseconds ms;
typedef std::chrono::time_point<std::chrono::system_clock, std::chrono::duration<long, std::ratio<1, 1000000000>>> time_p;

/**
 * @brief Controla el movimiento de la bola.
 */

class PhysController {
private:
    PhysController() = default;
    static PhysController* instance;
    time_p* lastTime;
    Ball* ball;
public:

    PhysController* Instance();
    void ResetTime();
    void ResetPlayers();
    void ResetBall();
    void ResetAll();

    PlayerList* playerList;

    float deltaTime();

    void MoveBall();

    void CheckColl();
};



