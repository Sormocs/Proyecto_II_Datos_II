/**
 * @file PlayerObs.cpp
 * @author Luis Delgado
 * @brief Archivo cpp de las clases PlayerObs y PlayerList.
 */

#include "PlayerObs.h"

#include <cmath>
/**
 * @brief Constructor para PlayerObs.
 */
PlayerObs::PlayerObs() {
    next = nullptr;
}

/**
 * @brief WhereCollision revisa si la colisión es vertical, horizontal o diagonal.
 * @param pos
 * @return char 'd', 'h', 'v'.
 */
char PlayerObs::WhereCollision(float *pos) {

    // Obtiene la distancia entre los puntos en la horizontal y en la vertical por separado.
    float xDist = pos[0] - this->xPos;
    //float yDist = std::sqrt(std::abs((pos[1] * pos[1]) + (this->yPos * this->yPos)));
    float yDist = pos[1] - this->yPos;

    // si ambos están tocando a la vez, está golpeando en diagonal
    if (outside(xDist) & outside(yDist)) return NO_COLLISION;

    else if (colliding(xDist) && colliding(yDist)) return DIAGONAL_COLLISION;

    // si la horizontal es más pequeña, está golpeando de costado.
    else if (colliding(xDist) && aboutToCollide(yDist)) return HORIZONTAL_COLLISION;

    // si la vertical es más pequeña, está golpeando arriba o abajo.
    else if (aboutToCollide(xDist) && colliding(yDist)) return VERTICAL_COLLISION;

    else return NO_COLLISION;
}

/**
 * @brief outside revisa si el jugador está fuera del radio.
 * @param pos
 * @return si el jugador está fuera del radio
 */
bool PlayerObs::outside(float pos) {
    return (pos > PLAYER_RADIUS);
}

/**
 * @brief colliding revisa si la posición colisiona con el jugador
 * @param pos
 * @return si la posición colisiona con el jugador
 */
bool PlayerObs::colliding(float pos) {
    return (pos <= PLAYER_RADIUS && pos > 2*PLAYER_RADIUS/3.0);
}

/**
 * @brief inside si la posición está dentro del radio
 * @param pos
 * @return si la posición está dentro del radio
 */
bool PlayerObs::inside(float pos) {
    return (pos <= 2*PLAYER_RADIUS/3.0);
}

/**
 * @brief aboutToCollide revisa si la posición dada está a punto de colisionar.
 * @param pos
 * @return si la posición dada está a punto de colisionar
 */
bool PlayerObs::aboutToCollide(float pos) {
    return (pos <= PLAYER_RADIUS + (PLAYER_RADIUS*0.1));
}

PlayerObs::PlayerObs(float X, float Y) {
    xPos = X;
    yPos = Y;
}








//#######################################################################################################################################



/**
 * @brief Add añade un jugador al inicio de la lista.
 * @param player
 */
void PlayerList::Add(PlayerObs *player) {
    if (first == nullptr) first = player;

    else{
        player->next = first;
        first = player;
    }

    length ++;
}

/**
 * @brief Get retorna el jugador en el índice.
 * @param index
 * @return PlayerObs en el índice
 */
PlayerObs *PlayerList::Get(int index) {
    if (first == nullptr || length == 0) return nullptr;

    else if (index == 0) return first;

    else {
        PlayerObs* temp = first;
        for (int i = 0; i < length - 1; ++i) {
            if (i == index) return temp;
            else temp = temp->next;
        }

        return temp;
    }
}

