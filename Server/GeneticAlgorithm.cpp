
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
    currGenBestIndex = -1;
    currGenBestScore = 0;
    prevGenBestScore = 0;
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

/**
 * @brief TwoRanParents selecciona dos padres aleatorios para la siguiente generación.
 * @param father
 * @param mother
 */
void GenAlgorithm::TwoRanParents(Specimen& father, Specimen& mother) {
    auto* bestList = new SpecList;
//    int* array = new int(0);
    for (int i = 0; i < generations->At(0)->Length(); ++i) {
        if (generations->At(currentGen-1)->At(i)->score >= prevGenBestScore/3) {
            Specimen temp = *generations->At(currentGen-1)->At(i);
            bestList->AddBack(&temp);
        }
    }

    if (bestList->Length() < 2){
        father = *generations->At(currentGen-1)->At(rand() % generations->At(currentGen-1)->Length());
        mother = *generations->At(currentGen-1)->At(rand() % generations->At(currentGen-1)->Length());

    } else {
        father = *bestList->At(rand() % bestList->Length());
        mother = *bestList->At(rand() % bestList->Length());
    }

}

/**
 * @brief SearchBest busca el mejor de los especímenes para guardar el puntaje del mejor, con base en él se seleccionan los descendientes.
 */
void GenAlgorithm::SearchBests() {

    char bestScore = 0;
    int bestIndex = 0;

    for (int i = 0; i < generations->At(currentGen)->Length(); ++i) {
        char score = generations->At(currentGen)->At(i)->score;
        if (score > bestScore) {
            bestScore = score;
            bestIndex = i;
            if (score > currGenBestScore) {
                currGenBestIndex = bestIndex;
                currGenBestScore = score;
            }
        }

    }
}

/**
 * @brief Score obtiene el puntaje del espécimen al que pertenecen las posiciones pasadas por parámetro.
 * @param positions
 * @return score
 */
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

/**
 * @brief Mutation se encarga de la mutación de cierto porcentaje de los especímenes.
 * @param specimen
 * @param parents
 */
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

/**
 * @brief Inheritance provoca la herencia de los genes de dos padres, que corresponden a las posiciones.
 * @param specimen
 * @param parents
 */
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
            }
            posArray[i] = ranIndex;

            char posVal = allPossibleDivs->At(ranIndex)->value;
            specimen->positions->AddBack(new Node(posVal));
        }
        specimen->score = Score(specimen->positions);
        this->generations->At(currentGen)->AddBack(specimen);
//        printf("Añadido a la cola un nuevo espécimen de generación %d.\n", currentGen);
//        printf("El puntaje es %d. Mientras la división es %d\n", specimen->score, divisionNum);
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
//        printf("Añadido a la cola un nuevo espécimen de generación %d.\n", currentGen);

    }
}

/**
 * @brief CreateGen crea las generaciones con sus especímenes.
 * @param maxSpec
 */
void GenAlgorithm::CreateGen(int maxSpec) {
    generations->AddBack(new SpecList);
    for (int i = 0; i < maxSpec; ++i) {
        CreateSpecimen();
        SearchBests();
        if (generations->At(currentGen)->At(currGenBestIndex)->score == divisionNum) solved = true;
//        printf("El mejor puntaje es %d. Mientras la división es %d\n", generations->At(currentGen)->At(currGenBestIndex)->score, divisionNum);
    }
    gensBests->AddBack(generations->At(currentGen)->At(currGenBestIndex));
    prevGenBestScore = currGenBestScore;
}

/**
 * @brief Run ejecuta el algoritmo la cantidad de generaciones especificada como máximo y con los individuos especificados.
 * @param maxGen
 * @param maxSpec
 */
void GenAlgorithm::Run(int maxGen, int maxSpec) {
    time_p now = Time::now();
    int count = 0;
    while (!(solved || stop)) {
        currentGen++;
        printf("generación actual: %d\n", currentGen);
        CreateGen(maxSpec);

        if (generations->At(currentGen)->At(currGenBestIndex)->score == divisionNum) solved = true;
        count++;
        stop = count >= maxGen;
    }
    auto* spec = new Specimen;
    for (char i = 0; i < maxSpec; ++i) {
        spec->positions->AddBack(new Node(i));
    }
    spec->score = maxSpec;
    time = std::chrono::duration_cast<ms>(Time::now()-now).count() * 0.001;
}

/**
 * @brief getGenerations retorna la lista de las generaciones.
 * @return generations
 */
GenList* GenAlgorithm::getGenerations() const {
    return generations;
}

/**
 * @brief getLastGen retorna el número de la última generación.
 * @return lastGen
 */
int GenAlgorithm::getLastGen() const {
    return currentGen;
}

/**
 * @brief isSolved retorna si la ejecución finalizó.
 * @return
 */
bool GenAlgorithm::isSolved() const {
    return solved || stop;
}

/**
 * @brief getTime retorna el tiempo de ejecución del algoritmo.
 * @return time
 */
float GenAlgorithm::getTime() const {
    return time;
}

/**
 *
 * @param posArray retorna si un índice está en el arreglo.
 * @param len
 * @param ranIndex
 * @return bool
 */
bool GenAlgorithm::inArray(char *posArray, int len, char ranIndex) {
    for (int i = 0; i < len; ++i) {
        if (posArray[1] == ranIndex) return true;
    }
    return false;
}

/**
 * @brief getBestIndex retorna el índice del mejor espécimen de la generación actual.
 * @return
 */
int GenAlgorithm::getBestIndex() const {
    return currGenBestIndex;
}
