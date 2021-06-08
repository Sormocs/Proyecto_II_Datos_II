#define GRAVITY 9.81

// fricción
#define US 0.75              // coeficiente de fricción estática del césped
#define UK 20.7              // coeficiente de fricción cinética del césped

// propiedades de la bola
#define BALL_MASS 0.45       // 450 g de masa del balón
#define ENERGY_LOSS 0.3      // Porcentaje de pérdidad de energía tras impacto
#define BALL_RADIUS 20       // Radio de la bola

// constantes de colisión
#define HORIZONTAL_COLLISION 'h'
#define VERTICAL_COLLISION 'v'
#define DIAGONAL_COLLISION 'd'
#define NO_COLLISION '-'

// constantes del jugador
#define PLAYER_RADIUS 25

// constantes matemáticas
#define PI 3.14159265359