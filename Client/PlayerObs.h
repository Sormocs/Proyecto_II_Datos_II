/**
 * @file PlayerObs.h
 * @author Luis Delgado
 * @brief Archivo header de las clases PlayerObs y PlayerList.
 */

#ifndef CLIENT_PLAYEROBS_H
#define CLIENT_PLAYEROBS_H

#include "Constants.h"

/**
 * @brief Clase PlayerObs encargada de representar los jugadores que sirven de obstáculos para el balón.
 */
class PlayerObs {
private:
    float pos[2];

    bool inside(float pos);
    bool colliding(float pos);
    bool aboutToCollide(float pos);
    bool outside(float pos);
public:
    PlayerObs* next;


    PlayerObs();
    char WhereCollition(float pos[]);

    PlayerObs* GetNext();
};

// ############################################################################################################

/**
 * @brief Clase PlayerList que sirve para almacenar los obstáculos o jugadores.
 */
class PlayerList {
private:
    PlayerObs* first;
    int lenght;

public:

    void Add(PlayerObs* player);
    PlayerObs* Get(int index);

    int Lenght() { return lenght; };
};


#endif //CLIENT_PLAYEROBS_H
