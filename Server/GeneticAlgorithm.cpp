/**
 * @file GeneticAlgorith.cpp
 * @author Luis Delgado
 * @brief Incluye el cpp con la declaración de los métodos de la clase GeneticAlgorithm.
 */

#include "GeneticAlgorithm.h"

/**
 * @brief CreateGenerations crea una generación con la cantidad de especies "size".
 * @param size
 */
void GeneticAlgorithm::CreateGeneration(int size) {
    List* gen = new List();

    for (int i = 0; i < size; ++i) {

        Node* temp = new Node();
        temp->value = (void*) new GenNode();
        ((GenNode*) temp->value)->SetInitVals(matSize, maxMoves, matrix);
        gen->Add(temp);
    }

    Node* genNode = new Node();
    genNode->value = (void*) gen;
    genList->Add(genNode);
    genNum++;
}

/**
 * @brief RunAlgorithm ejecuta todas las generaciones del algoritmo hasta el máximo especificado o hasta que se encuentre la solución.
 * @param species
 * @param gens
 */
void GeneticAlgorithm::RunAlgorithm(int species, int gens) {
    while (genNum < gens && !solved) {

        RunNextGen(species);
    }
}

/**
 * @brief RunNextGen ejecuta la siguiente generación de especies.
 * @param species
 */
void GeneticAlgorithm::RunNextGen(int species) {
    CreateGeneration(species);

    for (int i = 0; i < species; ++i) {
        ((GenNode*)genList->At(0)->value)->Run();
    }
}
