#include "Lists.h"
#include <random>
#include <chrono>

typedef std::chrono::high_resolution_clock Time;
typedef std::chrono::milliseconds ms;
typedef std::chrono::time_point<std::chrono::system_clock, std::chrono::duration<long, std::ratio<1, 1000000000>>> time_p;


class GenAlgorithm {
private:
    PosList* allPossibleDivs;
    GenList* generations;
    SpecList* gensBests;
    char divisionNum;
    int currentGen;
    int currGenBest;
    bool solved;
    bool stop;
    float time;

    bool inArray(char* posArray, int len, char ranIndex);

    void TwoRanParents(Specimen& father, Specimen& mother);
    SpecList* SearchBests();
    char Score(PosList* positions);
    void Mutation(Specimen*& specimen, Specimen parents[2]);
    void Inheritance(Specimen*& specimen, Specimen parents[2]);
    void CreateSpecimen();
    void CreateGen(int maxSpec);

public:
    GenAlgorithm();

    void SetDivisionNum(char divisions);

    void Run(int maxGen = 500, int maxSpec = 700);

    GenList* getGenerations() const;

    int getLastGen() const;

    bool isSolved() const;

    float getTime() const;

};