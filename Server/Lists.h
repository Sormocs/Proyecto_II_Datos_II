/**
 * @file Lists.h
 * @author Luis Delgado
 * @brief Incluye las clases Node, List, GenMatrix y GenList para el control de la matriz.
 */

/**
 * @brief Node es una clase base que sirve de nodo para listas enlazadas.
 */
class Node {
public:
    Node* next;
    void* value;

    void Delete();
};

/**
 * @brief List es una clase base para las listas.
 */
class List {
private:
    Node* first;
    int length;

public:
    void Add(Node* node);
    Node* At(int index);

    int Length();

    void Reset();
};

/**
 * @brief GenList es una clase de lista enlazada que almacena un vector de una fila de la matriz.
 */
class GenList : public List {

};

/**
 * GenMatrix es una clase que contiene vectores con elementos de la matriz del algoritmo genético.
 */
class GenMatrix : List {
};