#include "Lists.h"

Specimen::Specimen() {
    positions = new PosList();
    score = 0;
}

/**
 * @brief Delete elimina todos los nodos enlazados y todos los elementos.
 */
 using namespace std;
void Node::Delete() {
    if (next != nullptr) next->Delete();
    delete this;
}

Node::Node(char value) {
    this->value = value;
}

/**
 * @brief AddFront añade un elemento al frente de la lista.
 * @param node
 */
void PosList::AddFront(Node *node) {
    if (first == nullptr or length == 0) first = node;

    else{
        node->next = first;
        first = node;
    }

    length ++;
}

/**
 * @brief At retorna el elemento en el índice.
 * @param index
 * @return Node
 */
Node* PosList::At(int index) {
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
int PosList::Length() {
    return length;
}

/**
 * Limpia la memoria asignada a los nodos de la lista.
 */
void PosList::Reset() {
    first->Delete();
    first = nullptr;
}

/**
 * @brief GetDelAt retorna el elemento en el índice y lo elimina.
 * @param index
 * @return Node
 */
Node *PosList::GetDelAt(int index) {
    Node* temp = nullptr;
    if (length == 0){
        temp = nullptr;

    } else if (index == 0) {
        if (length == 1){
            temp = first;
            first = nullptr;

        } else {
            temp = first;
            first = first->next;
            temp->next = nullptr;
        }

    } else {
        Node* temp1 = At(index-1);
        temp = temp1->next;
        if (index == length-1) temp1->next = nullptr;
        else temp1->next = temp1->next->next;
        temp->next = nullptr;
    }
    length--;
    return temp;
}

/**
 * @brief AddBack añade elementos al final de la lista
 * @param node
 */
void PosList::AddBack(Node *node) {
    if (length == 0) AddFront(node);

    else {
        Node *temp = At(length - 1);
        temp->next = node;
        length++;
    }
}

//####################################################################################################################

/**
 * @brief At retorna el elemento en el índice.
 * @param index
 * @return Specimen
 */
Specimen *SpecList::At(int index) {
    if (first == nullptr or length == 0) return nullptr;

    else if (index == 0) return first;

    else {
        Specimen* temp = this->first;
        for (int i = 0; i < length - 1; ++i) {
            if (i == index) return temp;
            else temp = temp->next;
        }

        return temp;
    }
}
/**
 * @brief AddFront añade un elemento al frente de la lista.
 * @param specimen
 */
void SpecList::AddFront(Specimen *specimen) {
    if (first == nullptr or length == 0) first = specimen;

    else{
        specimen->next = first;
        first = specimen;
    }

    length ++;
}

/**
 * @brief AddBack añade elementos al final de la lista
 * @param node
 */
void SpecList::AddBack(Specimen *specimen) {
    if (length == 0) AddFront(specimen);

    else {
        Specimen *temp = At(length - 1);
        temp->next = specimen;
        length++;
    }
}

/**
 * @brief Replace reemplaza el elemento en el índice con el nuevo elemento.
 * @param index
 * @param specimen
 */
void SpecList::Replace(int index, Specimen* specimen) {
    Specimen* temp = At(index-1);
    if (length-1 != index) specimen->next = temp->next->next;
    temp->next = specimen;
}

/**
 * @brief AddFront añade un elemento al frente de la lista.
 * @param gen
 */
void GenList::AddFront(SpecList *gen) {
    if (first == nullptr or length == 0) first = gen;

    else{
        gen->next = first;
        first = gen;
    }
    length ++;
}

/**
 * @brief AddBack añade elementos al final de la lista
 * @param node
 */
void GenList::AddBack(SpecList *gen) {
    if (length == 0) AddFront(gen);

    else {
        SpecList *temp = At(length - 1);
        temp->next = gen;
        length++;
    }
}

/**
 * @brief At retorna el elemento en el índice.
 * @param index
 * @return SpecList
 */
SpecList *GenList::At(int index) {
    if (first == nullptr or length == 0) return nullptr;

    else if (index == 0) return first;

    else {
        SpecList* temp = first;
        for (int i = 0; i < length - 1; ++i) {
            if (i == index) return temp;
            else temp = temp->next;
        }

        return temp;
    }
}
