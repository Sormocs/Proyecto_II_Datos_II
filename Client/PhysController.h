#ifndef CLIENT_PHYSCONTROLLER_H
#define CLIENT_PHYSCONTROLLER_H

#include <chrono>

#define HORIZONTAL_COLLITION 'h'
#define VERTICAL_COLLITON 'v'
#define DIAGONAL_COLLITION 'd'
#define NO_COLLITION '-'

using namespace std::chrono;

class PhysController {
private:
    static std::chrono::time_point<std::chrono::system_clock, duration<long, std::ratio<1, 1000000000>>>* lastTime;
public:
    static int abs(int num);
    static float abs(float num);

    static float deltaTime();

    static void CheckColl(float pos[]);
};




#endif //CLIENT_PHYSCONTROLLER_H
