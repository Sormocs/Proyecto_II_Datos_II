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
double PhysController::deltaTime() {
    if (lastTime == nullptr) {
        lastTime = new time_p;
        *lastTime = Time::now();
    }
    time_p newTime = Time::now();
    return (std::chrono::duration_cast<ms>(newTime - *lastTime)).count() * 0.001;
//    return 0.16;
}

/**
 * @brief CheckColl revisa si colisiona la bola con algún jugador.
 */
void PhysController::CheckColl() {
    char collision = char();
    for (int i = 0; i < playerList->Length(); ++i) {
        collision = playerList->Get(i)->WhereCollision(ball->pos);
        if (collision == NO_COLLITION) continue;

        else {
            ball->Bounce(collision);
        }
    }

    if (ball->pos[0] < 80) {
        // si colisiona con el borde izquierdo
        if (ball->degree > 90 && ball->degree < 270) {
//             y el vector está
//                   |
//              aquí |
//              _____|______
//            o aquí |
//                   |
//
            ball->Bounce(HORIZONTAL_COLLITION);
        }
    } else if (ball->pos[0] > 890) {
        // sino, si colisiona con el borde izquierdo
        if (ball->degree < 90 || ball->degree > 270) {
//            y el vector está
//                   |
//                   |   aquí
//            _______|_______
//                   | o aquí
//                   |
            ball->Bounce(HORIZONTAL_COLLITION);
        }

    } else if (ball->pos[1] < 135) {
        // sino, si colisiona con el borde superior
        if (ball->degree > 0 && ball->degree < 180) {
//            y el vector está
//                   |
//              aquí | o aquí
//            _______|_______
//                   |
//                   |
            ball->Bounce(VERTICAL_COLLITON);
        }
    }else if (ball->pos[1] > 530) {
        // sino, si colisiona con el borde inferior
        if (ball->degree > 180 && ball->degree < 360){
//            y el vector está
//                   |
//                   |
//            _______|_______
//              aquí | o aquí
//                   |
            ball->Bounce(VERTICAL_COLLITON);
        }
    }
    FixAngle(ball->degree);
}

/**
 * @brief MoveBall cambia la posición de la bola para mostrarla en pantalla.
 */
void PhysController::MoveBall() {
//    if (this->ball->energy == 0) return;
    CheckColl();
    ball->Friction(deltaTime());
    ball->pos[0] += ((std::cos((ball->degree * PI) / 180) * ball->energy)/BALL_MASS) * deltaTime();
    ball->pos[1] += ((std::sin((ball->degree * PI) / 180) * ball->energy)/BALL_MASS) * deltaTime();

    *lastTime = Time::now();
}
/**
 * @brief getAngleInDeg obtiene el ángulo de un vector con las componentes X y Y.
*/
float PhysController::getAngleInDeg(float xDist, float yDist) {
    if (xDist == 0) {
        if (yDist > 0) return 270;
        else return 90;

    } else if (xDist < 0) {
        return FixAngle((std::atan(yDist/xDist) * 180 / PI) + 180);

    } else return FixAngle(std::atan(yDist/xDist) * 180 / PI);
}

/**
 * @brief FixAngle mantiene el ángulo entre 0 y 360.
 * @param angle
 * @return angle
 */
float PhysController::FixAngle(float angle){

    while (angle < 0 && 360 <= angle){

        if (angle < 0) angle += 360;

        else if (angle >= 360) angle -= 360;
    }
    return angle;
}

/**
 * @brief Instance obtiene la instancia del sigleton.
 * @return instancia de PhysController
 */
PhysController *PhysController::Instance() {
    if (instance == nullptr) {
        instance = new PhysController;
    }
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

Ball *PhysController::GetBall() {
    return ball;
}

PhysController::PhysController() {
    this->lastTime = nullptr;
    this->ball = new Ball;
}


