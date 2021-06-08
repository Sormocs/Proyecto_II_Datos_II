/**
 * @file PlayerObs.h
 * @author Luis Delgado
 * @brief Archivo header de las clases PlayerObs y PlayerList.
 */

#include "Constants.h"
#include <iostream>

/**
 * @brief Clase PlayerObs encargada de representar los jugadores que sirven de obstáculos para el balón.
 */
class PlayerObs {
private:
    float xPos;
    float yPos;

    static bool LeftColl(float* dist, float& degrees);
    static bool RightColl(float* dist, float& degrees);
    static bool UpColl(float* dist, float& degrees);
    static bool DownColl(float* dist, float& degrees);
public:
    PlayerObs(float X,float Y);
    PlayerObs* next;

    PlayerObs();
    char WhereCollision(float *pos, float& degrees);
    float getXPos() {
        return xPos;
    }
    float getYPos() {
        return yPos;
    }
};

// ############################################################################################################

/**
 * @brief Clase PlayerList que sirve para almacenar los obstáculos o jugadores.
 */
class PlayerList {
private:
    PlayerObs* first;
    int length;

public:

    void Add(PlayerObs* player);
    PlayerObs* Get(int index);

    int Length() const { return length; };
};

