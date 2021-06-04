
#include "GenAlgorithm.h"
#include <random>

/**
 * @brief GenAlgorithm es el constructor de la clase.
 */
GenAlgorithm::GenAlgorithm() {
    allPossibleDivs = new List();
    generations = new List();
    divisionNum = 0;
    currentGen = 0;
}

/**
 * @brief SetDivisionNum establece la cantidad de pedazos en los que se dividió la imagen.
 * @param divisions
 */
void GenAlgorithm::SetDivisionNum(int divisions) {
    if (allPossibleDivs == nullptr) allPossibleDivs = new List();

    for (int i = 0; i < divisions; ++i) {
        allPossibleDivs->Add(new Node((void*)(new char(i))));
    }
    divisionNum = divisions;
}


/**
 * @brief CreateSpecimen es el generador de especímenes de una generación.
 */
void GenAlgorithm::CreateSpecimen() {
    Specimen* specimen = new Specimen();
    if (currentGen == 0) {
        for (int i = 0; i < divisionNum; ++i) {


            specimen->positions;


        }
    }
    ((List*)generations->At(currentGen-1)->value)->Add(new Node((void*) specimen));
}


//#################################################### ↓ SPECIMEN ↓ ####################################################//

Specimen::Specimen() {
    positions = new List();
    score = 0;
}
