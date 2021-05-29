//
// Created by lujim on 28/5/2021.
//

#include "Lists.h"

/**
 * @brief Delete elimina todos los nodos enlazados y todos los elementos.
 */
void Node::Delete() {
    delete value;
    if (next != nullptr) next->Delete();
    delete this;
}

/**
 * @brief Add añade un elemento al frente de la lista.
 * @param node
 */
void List::Add(Node *node) {
    if (first == nullptr or length == 0) first = node;

    else{
        node->next = first;
        first = node;
    }

    length ++;
}

Node* List::At(int index) {
    if (first == nullptr or length == 0) return nullptr;

    else if (index == 0) return first;

    else {
        Node* temp = first;
        for (int i = 0; i < length - 1; ++i) {
            if (i == index) return temp;
            else temp = temp->next;
        }

        return temp;
    }
}

/**
 * @brief Length devuelve el largo de la lista.
 * @return length
 */
int List::Length() {
    return length;
}

/**
 * Limpia la memoria asignada a los nodos de la lista.
 */
void List::Reset() {
    first->Delete();
    first = nullptr;
}
