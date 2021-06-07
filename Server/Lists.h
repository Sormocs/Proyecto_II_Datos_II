/**
 * @file Lists.h
 * @author Luis Delgado
 * @brief Incluye las clases Node, PosList, GenList y SpecList para el control de la matriz.
 */



/**
 * @brief Node es una clase base que sirve de nodo para listas enlazadas.
 */
class Node {
public:
    Node* next;
    char value;

    Node() = default;
    explicit Node(char value);

    void Delete();
};

/**
 * @brief PosList es una clase base para las listas.
 */
class PosList {
private:
    Node* first;
    int length;

public:
    void AddFront(Node* node);
    void AddBack(Node* node);
    Node* At(int index);
    Node* GetDelAt(int index);

    int Length();

    void Reset();
};

class Specimen {
public:
    PosList* positions;
    Specimen* next;
    char score;
    Specimen();
};

/**
 * @brief SpecList es una clase de lista enlazada que almacena un vector de una fila de la matriz.
 */
class SpecList {
private:
    Specimen* first;
    int length;

public:
    SpecList* next;

    void AddFront(Specimen* specimen);
    void AddBack(Specimen* specimen);
    Specimen* At(int index);

    int Length() const { return length; }
    void Replace(int index, Specimen* specimen);
};

/**
 * GenList es una clase que contiene vectores con elementos de la matriz del algoritmo genético.
 */
class GenList {
private:
    SpecList* first;
    int length;

public:
    void AddFront(SpecList* gen);
    void AddBack(SpecList* gen);
    SpecList* At(int index);

    int Length() const { return length; }
};