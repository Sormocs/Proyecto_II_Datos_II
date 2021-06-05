#include "Lists.h"
#include <random>

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
    bool solved;
    bool stop;

    void TwoRanParents(Specimen& father, Specimen& mother);
    List* SearchBests();
    char Score(List* positions);
    void Mutation(Specimen*& specimen, Specimen parents[2]);
    void Inheritance(Specimen*& specimen, Specimen parents[2]);
    void SetDivisionNum(int divisions);
    void CreateSpecimen(Specimen parents[2]);
    void CreateGen()
    void CreateGen(int size);

public:
    GenAlgorithm();
    void Run(int maxGen = 500, int maxSpec = 700);

    List* getGenerations() const;

    int getCurrentGen() const;

    bool isSolved() const;

};