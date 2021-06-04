#include "Lists.h"

class Specimen {
public:
    List* positions;
    char score;
    Specimen();
};

class GenAlgorithm {
private:
    List* allPossibleDivs;
    List* generations;
    List* lastGenBests;
    char divisionNum;
    int currentGen;

    void TwoRanParents(Specimen& father, Specimen& mother);
    List* SearchBests();
    char Score(List* positions);
    void Mutation(Specimen*& specimen, Specimen parents[2]);
    void Inheritance(Specimen*& specimen, Specimen parents[2]);

public:
    GenAlgorithm();
    void SetDivisionNum(int divisions);
    void CreateSpecimen(Specimen parents[2]);
};