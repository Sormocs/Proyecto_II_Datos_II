/**
 * @file PlayerObs.h
 * @author Luis Delgado
 * @brief Archivo header de las clases PlayerObs y PlayerList.
 */

#include "Constants.h"

/**
 * @brief Clase PlayerObs encargada de representar los jugadores que sirven de obstáculos para el balón.
 */
class PlayerObs {
private:
    float xPos;
    float yPos;

    bool LeftColl(float* dist, float degrees);
    bool RightColl(float* dist, float degrees);
    bool UpColl(float* dist, float degrees);
    bool DownColl(float* dist, float degrees);
public:
    PlayerObs(float X,float Y);
    PlayerObs* next;

    PlayerObs();
    char WhereCollision(float *pos, float degrees);
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

