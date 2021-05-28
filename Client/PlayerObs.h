//
// Created by tiquillo on 27/5/21.
//

#ifndef CLIENT_PLAYEROBS_H
#define CLIENT_PLAYEROBS_H

#include "Constants.h"


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
