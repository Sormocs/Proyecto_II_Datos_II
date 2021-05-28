//
// Created by lujim on 27/5/2021.
//

#include "PhysController.h"

std::chrono::time_point<std::chrono::system_clock, duration<long, std::ratio<1, 1000000000>>>* PhysController::lastTime = nullptr;

int PhysController::abs(int num){
    if (num < 0) num * -1;
    return num;
}

float PhysController::abs(float num){
    if (num < 0) num * -1;
    return num;
}

float PhysController::deltaTime() {
    if (lastTime == nullptr) *lastTime = std::chrono::system_clock::now();
    //return std::chrono::high_resolution_clock::now() - *lastTime;
    return 0.16;
}


