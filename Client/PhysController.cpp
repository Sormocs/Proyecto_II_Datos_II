//
// Created by lujim on 27/5/2021.
//

#include "PhysController.h"

PhysController* PhysController::instance = nullptr;

float PhysController::deltaTime() {
    if (lastTime == nullptr) *lastTime = Time::now();
    time_p newTime = Time::now();
    return (std::chrono::duration_cast<ms>(newTime - *lastTime)).count();
}

void PhysController::CheckColl() {
    char collition = char();
    for (int i = 0; i < playerList->Lenght(); ++i) {
        collition = playerList->Get(i)->WhereCollition(ball->pos);
        if (collition == NO_COLLITION) continue;

        else {
            ball->Bounce(collition);
        }
    }
}

void PhysController::MoveBall() {
    CheckColl();
    ball->Friction(deltaTime());
    ball->pos[0] += std::cos((ball->degree * M_PI) / 180) * ball->speed;
    ball->pos[1] += std::sin((ball->degree * M_PI) / 180) * ball->speed;
}

PhysController *PhysController::Instance() {
    if (instance == nullptr) instance = new PhysController();
    return instance;
}

void PhysController::ResetTime() {
    lastTime = nullptr;
}

void PhysController::ResetPlayers() {
    playerList = nullptr;
}

void PhysController::ResetBall() {
    ball = nullptr;
}

void PhysController::ResetAll() {
    PhysController::instance = new PhysController();
}


