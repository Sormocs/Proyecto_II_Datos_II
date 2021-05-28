//
// Created by tiquillo on 27/5/21.
//

#include "PlayerObs.h"

#include <cmath>

PlayerObs::PlayerObs() {
    next = nullptr;
}


char PlayerObs::WhereCollition(float pos[]) {

    // Obtiene la distancia entre los puntos en la horizontal y en la vertical por separado.
    float xDist = std::abs(pos[0] - this->pos[0]);
    float yDist = std::sqrt(std::abs((pos[1] * pos[1]) + (this->pos[1] * this->pos[1])));

    // si ambos están tocando a la vez, está golpeando en diagonal
    if (outside(xDist) & outside(yDist)) return NO_COLLITION;

    else if (colliding(xDist) && colliding(yDist)) return DIAGONAL_COLLITION;

    // si la horizontal es más pequeña, está golpeando de costado.
    else if (colliding(xDist) && aboutToCollide(yDist)) return HORIZONTAL_COLLITION;

    // si la vertical es más pequeña, está golpeando arriba o abajo.
    else if (aboutToCollide(xDist) && colliding(yDist)) return VERTICAL_COLLITON;
}

PlayerObs* PlayerObs::GetNext() {
    return next;
}

bool PlayerObs::outside(float pos) {
    return (pos > PLAYER_RADIUS);
}

bool PlayerObs::colliding(float pos) {
    return (pos <= PLAYER_RADIUS && pos > 2*PLAYER_RADIUS/3.0);
}

bool PlayerObs::inside(float pos) {
    return (pos <= 2*PLAYER_RADIUS/3.0);
}

bool PlayerObs::aboutToCollide(float pos) {
    return (pos <= PLAYER_RADIUS + (PLAYER_RADIUS*0.1));
}








//#######################################################################################################################################




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

    else if (index == 0) return first;

    else {
        PlayerObs* temp = first;
        for (int i = 0; i < lenght - 1; ++i) {
            if (i == index) return temp;
            else temp = temp->next;
        }

        return temp;
    }
}

