//
// Created by tiquillo on 26/5/21.
//

#ifndef CLIENT_BALL_H
#define CLIENT_BALL_H

#define gravity = 9.81

// fricción
#define us 0.75             // coeficiente de fricción estática del césped
#define uk 0.57             // coeficiente de fricción cinética del césped

#define ballMass 0.450      // 450 g de masa del balón

#define energyLoss 10       // Porcentege de pérdidad de energía tras impacto

class Ball {
private:
    float pos[2];
    float speed;

    void ChangeSpeed(float deltaTime);

public:
    void Kick(float energy, float degrees);
};


#endif //CLIENT_BALL_H
