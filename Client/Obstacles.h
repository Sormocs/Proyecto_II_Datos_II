/**
 * @file Obstacles.h
 * @author Luis Delgado
 * @brief Archivo header de las clases Obstacles y ObstacleList.
 */

#include "Constants.h"
#include <iostream>

/**
 * @brief Clase Obstacles encargada de representar los jugadores que sirven de obstáculos para el balón.
 */
class Obstacles {
private:
    float xPos;
    float yPos;

    static bool LeftColl(float *dist, float &degrees);

    static bool RightColl(float *dist, float &degrees);

    static bool UpColl(float *dist, float &degrees);

    static bool DownColl(float *dist, float &degrees);

public:
    Obstacles(float X, float Y);

    Obstacles *next;

    Obstacles();

    char WhereCollision(float *pos, float &degrees);

    float getXPos() {
        return xPos;
    }

    float getYPos() {
        return yPos;
    }
};

// ############################################################################################################

/**
 * @brief Clase ObstacleList que sirve para almacenar los obstáculos o jugadores.
 */
class ObstacleList {
private:
    Obstacles *first;
    int length;

public:

    void Add(Obstacles *player);

    Obstacles *Get(int index);

    int Length() const { return length; };
};

