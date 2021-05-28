//
// Created by tiquillo on 27/5/21.
//

#include "PlayerObs.h"

PlayerObs::PlayerObs() {
    next = nullptr;
}


char PlayerObs::WhereCollition(float pos[]) {

    // Obtiene la distancia entre los puntos en la horizontal y en la vertical por separado.
    float xDist = sqrt(PhysController::abs((pos[0] * pos[0]) + (this->pos[0] * this->pos[0])));
    float yDist = sqrt(PhysController::abs((pos[1] * pos[1]) + (this->pos[1] * this->pos[1])));

    // si ambos están a la misma distancia, está golpeando la diagonal
    if (xDist <= this->radius && yDist <= this->radius) return DIAGONAL_COLLITION;

    // si la horizontal es más pequeña, está golpeando de costado.
    else if (xDist <= this->radius) return HORIZONTAL_COLLITION;

    // si la vertical es más pequeña, está golpeando arriba o abajo.
    else if (yDist <= this->radius) return VERTICAL_COLLITON;

    // si ninguna coincide, no hay colisión.
    else return NO_COLLITION;
}

PlayerObs* PlayerObs::GetNext() {
    return next;
}

void PlayerList::Add(PlayerObs *player) {
    if (first == nullptr) first == player;

    else{
        player->next = first;
        first = player;
    }

    lenght ++;
}

PlayerObs *PlayerList::Get(int index) {
    if (first == nullptr or lenght == 0) return nullptr;

    else {
        PlayerObs* temp = first;
        for (int i = 1; i < lenght + 1; ++i) {
            if (i == index) return temp;
            else temp = temp->next;
        }

        return temp;
    }
}

