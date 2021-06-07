
#include "GeneticAlgorithm.h"


//#################################################### ↓ GenAlgorithm ↓ ####################################################//

/**
 * @brief GenAlgorithm es el constructor de la clase.
 */
GenAlgorithm::GenAlgorithm() {
    allPossibleDivs = new PosList();
    generations = new GenList();
    gensBests = new SpecList;
    divisionNum = 0;
    currentGen = -1;
    currGenBest = -1;
    solved = false;
    stop = false;
    time = 0.0;
}

/**
 * @brief SetDivisionNum establece la cantidad de pedazos en los que se dividió la imagen.
 * @param divisions
 */
void GenAlgorithm::SetDivisionNum(char divisions) {
    if (allPossibleDivs == nullptr) allPossibleDivs = new PosList();

    for (int i = 0; i < divisions; ++i) {
        allPossibleDivs->AddBack(new Node(i));
    }
    divisionNum = divisions;
}

void GenAlgorithm::TwoRanParents(Specimen& father, Specimen& mother) {
//    SpecList* bestSpeciesList = SearchBests();
//
//    father = *bestSpeciesList->At(rand() % (bestSpeciesList->Length()));
//    mother = *bestSpeciesList->At(rand() % (bestSpeciesList->Length()));
    father = *generations->At(currentGen-1)->At(rand() % generations->At(currentGen-1)->Length());
    mother = *generations->At(currentGen-1)->At(rand() % generations->At(currentGen-1)->Length());

}

SpecList *GenAlgorithm::SearchBests() {
    SpecList* genSpecimens = generations->At(currentGen - 1);
    auto* newGenSpecimens = new SpecList();

    char bestScore = 0;
    int bestIndex = 0;

    for (int i = 0; i < generations->At(currentGen)->Length(); ++i) {
        char score = generations->At(currentGen)->At(i)->score;
        if (score > bestScore) {
            bestScore = generations->At(currentGen)->At(i)->score;
            bestIndex = i;
        }
    }
    gensBests->AddBack(generations->At(currentGen)->At(bestIndex));
    currGenBest = bestIndex;
//
//    if (bestScore >= 1) {
//        for (int i = 0; i < genSpecimens->Length(); ++i) {
//
//            if (genSpecimens->At(i)->score > bestScore / 2) newGenSpecimens->AddBack(genSpecimens->At(i));
//        }
//    } else newGenSpecimens = genSpecimens;
//
//    newGenSpecimens->AddBack(generations->At(currentGen)->At(bestIndex));
//
//    return newGenSpecimens;
}

char GenAlgorithm::Score(PosList *positions) {
    char score = 0;
    char currentPos = 0;
    bool repeated = false;
    char checkedPos[positions->Length()];

    for (int i = 0; i < positions->Length(); ++i) {

        currentPos = positions->At(i)->value;

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
            specimen->positions->AddBack(new Node(rand() % len));

        } else if (i % 2 == 0) {
            specimen->positions->AddBack(new Node(parents[0].positions->At(i)->value));

        } else {
            specimen->positions->AddBack(new Node(parents[1].positions->At(i)->value));
        }
    }
}

void GenAlgorithm::Inheritance(Specimen *&specimen, Specimen parents[]) {
    char len = parents[0].positions->Length();

    for (int i = 0; i < len; ++i) {

        if (i < len / 3) {
            specimen->positions->AddBack(new Node(parents[0].positions->At(i)->value));

        } else {
            specimen->positions->AddBack(new Node(parents[1].positions->At(i)->value));
        }
    }
}

/**
 * @brief CreateSpecimen es el generador de especímenes de una generación.
 */
void GenAlgorithm::CreateSpecimen() {
    auto* specimen = new Specimen;


    char posArray[allPossibleDivs->Length()];
    for (int i = 0; i < allPossibleDivs->Length(); ++i) {
        posArray[i] = -1;
    }

    if (currentGen == 0) {
        for (int i = 0; i < divisionNum; ++i) {
            char leng = allPossibleDivs->Length();
            char ranIndex = rand() % leng;

            while (inArray(posArray, allPossibleDivs->Length(), ranIndex)) {
                ranIndex = rand() % leng;
                printf("--------------------------------------------\n--------------------------------------------\n");
                printf("El elemento %d ya existe.\n--------------------------------------------\n", ranIndex);
            }
            posArray[i] = ranIndex;

            char posVal = allPossibleDivs->At(ranIndex)->value;
            specimen->positions->AddBack(new Node(posVal));
        }
        specimen->score = Score(specimen->positions);
        this->generations->At(currentGen)->AddBack(specimen);
        printf("Añadido a la cola un nuevo espécimen de generación %d.\n", currentGen);
        printf("El mejor puntaje es %d. Mientras la división es %d\n", specimen->score, divisionNum);
    } else {
        Specimen parents[2];
        TwoRanParents(parents[0], parents[1]);
        if (random() % 10 == 0) { // uno de cada diez especímenes será mutado
            Mutation(specimen, parents);
        } else {
            Inheritance(specimen, parents);
        }
        specimen->score = Score(specimen->positions);
        this->generations->At(currentGen)->AddBack(specimen);
        printf("Añadido a la cola un nuevo espécimen de generación %d.\n", currentGen);

    }
}


void GenAlgorithm::CreateGen(int maxSpec) {
    generations->AddBack(new SpecList);
    for (int i = 0; i < maxSpec; ++i) {
        CreateSpecimen();
        SearchBests();
        if (generations->At(currentGen)->At(currGenBest)->score == divisionNum) solved = true;
        printf("El mejor puntaje es %d. Mientras la división es %d\n", generations->At(currentGen)->At(currGenBest)->score, divisionNum);
    }
}


void GenAlgorithm::Run(int maxGen, int maxSpec) {
    time_p now = Time::now();
    while (!(solved || stop)) {
        currentGen++;
        printf("generación actual: %d\n", currentGen);
        CreateGen(maxSpec);

        if (generations->At(currentGen)->At(currGenBest)->score == divisionNum) solved = true;

    }
    time = std::chrono::duration_cast<ms>(Time::now()-now).count() * 0.001;
}

GenList* GenAlgorithm::getGenerations() const {
    return generations;
}

int GenAlgorithm::getLastGen() const {
    return currentGen;
}

bool GenAlgorithm::isSolved() const {
    return solved;
}

float GenAlgorithm::getTime() const {
    return time;
}

bool GenAlgorithm::inArray(char *posArray, int len, char ranIndex) {
    for (int i = 0; i < len; ++i) {
        if (posArray[1] == ranIndex) return true;
    }
    return false;
}