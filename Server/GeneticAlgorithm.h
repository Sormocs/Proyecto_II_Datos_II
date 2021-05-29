/**
 * @file GeneticAlgorith.h
 * @author Luis Delgado
 * @brief Incluye el header de la clase GeneticAlgorithm.
 */

#include "Generation.h"
#include "Lists.h"

/**
 * @brief GeneticAlgorithm se encarga de ordenar la imagen del rompecabezas con el uso de generaciones.
 */
class GeneticAlgorithm {
private:
    GenMatrix* matrix;
    List* bestMoves;
    List* genList;
    int maxMoves;
    bool solved;
    int matSize;
    int genNum;

    void

public:
    void CreateGeneration(int size);
    void RunAlgorithm(int species = 1000, int gens = 100);
    void RunNextGen(int species);
};

