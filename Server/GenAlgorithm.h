#include "Lists.h"

class GenAlgorithm {
private:
    List* allPossibleDivs;
    List* generations;
    char divisionNum;
    int currentGen;
public:
    GenAlgorithm();
    void SetDivisionNum(int divisions);
    void CreateSpecimen();
};

class Specimen {
public:
    List* positions;
    char score;
    Specimen();
};