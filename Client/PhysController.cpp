/**
 * @file PhysController.cpp
 * @author Luis Delgado
 * @brief Archivo cpp de la clase PhysController.
 */

#include "PhysController.h"

PhysController* PhysController::instance = nullptr;

/**
 * @brief deltaTime retorna el tiempo transcurrido desde la última llamada, por ejemplo, el tiempo pasado desde el último fame.
 * @return deltaTime
 */
float PhysController::deltaTime() {
    if (lastTime == nullptr) *lastTime = Time::now();
    time_p newTime = Time::now();
    return (std::chrono::duration_cast<ms>(newTime - *lastTime)).count();
}

/**
 * @brief CheckColl revisa si colisiona la bola con algún jugador.
 */
void PhysController::CheckColl() {
    char collision = char();
    for (int i = 0; i < playerList->Lenght(); ++i) {
        collision = playerList->Get(i)->WhereCollition(ball->pos);
        if (collision == NO_COLLITION) continue;

        else {
            ball->Bounce(collision);
        }
    }
}

/**
 * @brief MoveBall cambia la posición de la bola para mostrarla en pantalla.
 */
void PhysController::MoveBall() {
    CheckColl();
    ball->Friction(deltaTime());
    ball->pos[0] += std::cos((ball->degree * M_PI) / 180) * ball->speed;
    ball->pos[1] += std::sin((ball->degree * M_PI) / 180) * ball->speed;
}

/**
 * @brief Instance obtiene la instancia del sigleton.
 * @return instancia de PhysController
 */
PhysController *PhysController::Instance() {
    if (instance == nullptr) instance = new PhysController();
    return instance;
}

/**
 * @brief ResetTime reinicia el tiempo de la última vez que se movió la bola.
 */
void PhysController::ResetTime() {
    lastTime = nullptr;
}

/**
 * @brief ResetPlayers reinicia la lista de los jugadores.
 */
void PhysController::ResetPlayers() {
    playerList = nullptr;
}

/**
 * @brief ResetBall reinicia la bola.
 */
void PhysController::ResetBall() {
    ball = nullptr;
}

/**
 * @brief ResetAll crea otra instancia del controlador completamente nueva.
 */
void PhysController::ResetAll() {
    PhysController::instance = new PhysController();
}


