
#include "GeneticAlgorithm.h"


Specimen::Specimen() {
    positions = new List();
    score = 0;
}

//#################################################### ↓ GenAlgorithm ↓ ####################################################//

/**
 * @brief GenAlgorithm es el constructor de la clase.
 */
GenAlgorithm::GenAlgorithm() {
    allPossibleDivs = new List();
    generations = new List();
    lastGenBests = new List();
    divisionNum = 0;
    currentGen = 0;
    solved = false;
    stop = false;
    time = 0.0;
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

void GenAlgorithm::TwoRanParents(Specimen& father, Specimen& mother) {
    List* bestSpeciesList = SearchBests();

    father = *(Specimen*)bestSpeciesList->At(random() % bestSpeciesList->Length())->value;
    mother = *(Specimen*)bestSpeciesList->At(random() % bestSpeciesList->Length())->value;
}

List *GenAlgorithm::SearchBests() {
    List genSpecimens = *(List*)generations->At(currentGen-1)->value;
    List* newGenSpecimens = new List();

    char bestScore = 0;
    int bestIndex = 0;

    for (int i = 0; i < genSpecimens.Length(); ++i) {

        if (((Specimen*)genSpecimens.At(i)->value)->score > bestScore) bestScore = ((Specimen*)genSpecimens.At(i)->value)->score;
    }

    for (int i = 0; i < genSpecimens.Length(); ++i) {

        if (((Specimen*)genSpecimens.At(i)->value)->score > bestScore / 2) newGenSpecimens->Add(genSpecimens.At(i));
    }

    return newGenSpecimens;
}

char GenAlgorithm::Score(List *positions) {
    char score = 0;
    char currentPos = 0;
    bool repeated = false;
    char checkedPos[positions->Length()];

    for (int i = positions->Length(); i > 0; --i) {

        currentPos = *(char*)positions->At(i)->value;

        for (char pos : checkedPos) if (currentPos == pos) repeated = true;

        if (repeated) score = 0;

        else if (currentPos == i) score += 1;
    }
    return score;
}

void GenAlgorithm::Mutation(Specimen *&specimen, Specimen parents[]) {

    char len = parents[0].positions->Length();

    for (int i = 0; i < len; ++i) {

        if (i % 3 == 0){
            specimen->positions->Add(new Node((void*)new char(random() % len)));

        } else if (i % 2 == 0) {
            specimen->positions->Add(new Node((void*)parents[0].positions->At(len - 1 - i)));

        } else {
            specimen->positions->Add(new Node((void*)parents[1].positions->At(len - 1 - i)));
        }
    }
}

void GenAlgorithm::Inheritance(Specimen *&specimen, Specimen *parents) {
    char len = parents[0].positions->Length();

    for (int i = 0; i < len; ++i) {

        if (i < len / 3) {
            specimen->positions->Add(new Node((void*)parents[0].positions->At(len - 1 - i)));

        } else {
            specimen->positions->Add(new Node((void*)parents[1].positions->At(len - 1 - i)));
        }
    }
}

/**
 * @brief CreateSpecimen es el generador de especímenes de una generación.
 */
Specimen* GenAlgorithm::CreateSpecimen() {
    auto* specimen = new Specimen();
    if (currentGen == 0) {
        for (int i = 0; i < divisionNum; ++i) {

            specimen->positions->Add(new Node((void*) new char(*((char*)allPossibleDivs->GetDelAt(random() % allPossibleDivs->Length())->value))));
        }
    } else {
        Specimen parents[2];
        TwoRanParents(parents[0], parents[1]);
        if (random() % 10 == 0) { // uno de cada diez especímenes será mutado
            Mutation(specimen, parents);
        } else {
            Inheritance(specimen, parents);
        }
    }
    specimen->score = Score(specimen->positions);
    ((List*)generations->At(currentGen)->value)->Add(new Node((void*) specimen));
    if (specimen->score == divisionNum) solved = true;
}


void GenAlgorithm::CreateGen(int maxSpec) {
    generations->Add(new Node((void*) new List()));
    for (int i = 0; i < maxSpec; ++i) {
        CreateSpecimen();
    }
}


void GenAlgorithm::Run(int maxGen, int maxSpec) {
    time_p now = Time::now();
    while (!(solved || stop)) {

        CreateGen(maxSpec);

        currentGen++;
        if (currentGen >= maxGen) stop = true;
    }
    time = std::chrono::duration_cast<ms>(Time::now()-now).count() * 0.001;
}

List* GenAlgorithm::getGenerations() const {
    return generations;
}

int GenAlgorithm::getCurrentGen() const {
    return currentGen;
}

bool GenAlgorithm::isSolved() const {
    return solved;
}