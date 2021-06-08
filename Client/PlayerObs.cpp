/**
 * @file PlayerObs.cpp
 * @author Luis Delgado
 * @brief Archivo cpp de las clases PlayerObs y PlayerList.
 */

#include "PlayerObs.h"
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
char PlayerObs::WhereCollision(float *pos, float& degrees) {

    float dist[2];

    // Obtiene la distancia entre los puntos en la horizontal y en la vertical por separado.
    dist[0] = pos[0] - this->xPos;
    dist[1] = pos[1] - this->yPos;

    if (LeftColl(dist, degrees) || RightColl(dist, degrees)) return HORIZONTAL_COLLISION;

    else if (UpColl(dist, degrees) || DownColl(dist, degrees)) return VERTICAL_COLLISION;

    else return NO_COLLISION;
}

PlayerObs::PlayerObs(float X, float Y) {
    xPos = X;
    yPos = Y;
    next = nullptr;
}

bool PlayerObs::LeftColl(float* dist, float& degrees) {
    // si la distancia es negativa, está a la izquierda
    // si el radio es menor o igual al valor absoluto de la distancia, lo está tocando
    // si el ángulo está en el segundo o cuarto cuadrante, se dirige hacia él
    // si el valor absoluto de la distancia en y es menor al radio, están alineados
    return dist[0] < 0 && std::abs(dist[0]) <= PLAYER_RADIUS && (degrees < 90 || degrees > 270) && std::abs(dist[1]-BALL_RADIUS) <= PLAYER_RADIUS;
}

bool PlayerObs::RightColl(float* dist, float& degrees) {
    // si la distancia es positiva, está a la derecha
    // si el radio es menor o igual al valor absoluto de la distancia, lo está tocando
    // si el ángulo está en el primer o cuarto cuadrante, se dirige hacia él
    // si el valor absoluto de la distancia en y es menor al radio, están alineados
    return dist[0] > 0 && std::abs(dist[0]) <= 2*PLAYER_RADIUS && degrees > 90 && degrees < 270 && std::abs(dist[1]-BALL_RADIUS) <= PLAYER_RADIUS;
}

bool PlayerObs::UpColl(float *dist, float& degrees) {
    // si la distancia es negativa, está arriba
    // si el radio es menor o igual al valor absoluto de la distancia, lo está tocando
    // si el ángulo está en el primer o segundo cuadrante, se dirige hacia él
    // si el valor absoluto de la distancia en y es menor al radio, esá a la misma línea que él
    return dist[1] < 0 && std::abs(dist[1]) <= PLAYER_RADIUS && degrees > 0 && degrees < 180 && std::abs(dist[0]-BALL_RADIUS) <= PLAYER_RADIUS;
}

bool PlayerObs::DownColl(float *dist, float& degrees) {
    // si la distancia es positiva, está abajo
    // si el radio es menor o igual al valor absoluto de la distancia, lo está tocando
    // si el ángulo está en el tercer o cuarto cuadrante, se dirige hacia él
    // si el valor absoluto de la distancia en y es menor al radio, están alineados
    return dist[1] > 0 && std::abs(dist[1]) <= 2*PLAYER_RADIUS + BALL_RADIUS/2.0 && degrees > 180 && degrees < 360 && std::abs(dist[0]-BALL_RADIUS) <= PLAYER_RADIUS;
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

