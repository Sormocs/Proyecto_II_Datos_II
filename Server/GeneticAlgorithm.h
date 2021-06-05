#include "Lists.h"
#include <random>
#include <chrono>

typedef std::chrono::high_resolution_clock Time;
typedef std::chrono::milliseconds ms;
typedef std::chrono::time_point<std::chrono::system_clock, std::chrono::duration<long, std::ratio<1, 1000000000>>> time_p;

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
    float time;

    void TwoRanParents(Specimen& father, Specimen& mother);
    List* SearchBests();
    char Score(List* positions);
    void Mutation(Specimen*& specimen, Specimen parents[2]);
    void Inheritance(Specimen*& specimen, Specimen parents[2]);
    void SetDivisionNum(int divisions);
    Specimen* CreateSpecimen();
    void CreateGen(int maxSpec);

public:
    GenAlgorithm();
    void Run(int maxGen = 500, int maxSpec = 700);

    List* getGenerations() const;

    int getCurrentGen() const;

    bool isSolved() const;

};