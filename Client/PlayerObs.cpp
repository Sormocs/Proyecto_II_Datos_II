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
 * @brief WhereCollition revisa si la colisión es vertical, horizontal o diagonal.
 * @param pos
 * @return char 'd', 'h', 'v'.
 */
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

/**
 * @brief GetNext obtiene el siguiente elemento enlazado
 * @return el siguiente PlayerObs
 */
PlayerObs* PlayerObs::GetNext() {
    return next;
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








//#######################################################################################################################################



/**
 * @brief Add añade un jugador al inicio de la lista.
 * @param player
 */
void PlayerList::Add(PlayerObs *player) {
    if (first == nullptr) first == player;

    else{
        player->next = first;
        first = player;
    }

    lenght ++;
}

/**
 * @brief Get retorna el jugador en el índice.
 * @param index
 * @return PlayerObs en el índice
 */
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

