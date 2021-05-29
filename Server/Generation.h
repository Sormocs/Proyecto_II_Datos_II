/**
 * @file Generation.cpp
 * @author Luis Delgado
 * @brief Incluye la clase GenNode y GenList.
 */

#include "Lists.h"

/**
 * @brief GenNode es la case para las especies de cada generación.
 */
class GenNode {
private:
    void Move();
    void CheckCompleted();

public:
    // atributos el desarrollo del algoritmo.
    bool finished;
    int matSize;
    int maxMoves;
    List* moves;

    // métodos para la función del algorirmo.
    bool Run();
    void SetInitVals(int size, int moves, GenMatrix* matrix);
};

