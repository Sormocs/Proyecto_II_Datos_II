/**
 * @file Generation.cpp
 * @author Luis Delgado
 * @brief Incluye la clase GenNode y GenList.
 */

#include "Generation.h"

bool GenNode::Run() {

}

void GenNode::SetInitVals(int size, int moves, GenMatrix *matrix) {
    this->matSize = size;
    this->maxMoves = moves;
}
