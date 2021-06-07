//
// Created by sormocs on 6/6/21.
//

#include "GenLists.h"

void Gen::Insert(int num) {

    if (start == nullptr){

        Position* temp = new Position;
        temp->pos = num;
        temp->prev = nullptr;
        temp->next = nullptr;

        start = temp;
        end = temp;

    } else {

        Position* temp = new Position;
        temp->pos = num;
        temp->prev = end;
        temp->next = nullptr;

        end = temp;

    }

}


void GenLists::Insert() {

    if (start == nullptr){

        Gen* temp = new Gen;
        temp->gennum = len;
        temp->next = nullptr;
        temp->prev = nullptr;

        end = temp;
        start = temp;

    } else {

        Gen* temp = new Gen;
        temp->gennum = len;
        temp->next = nullptr;
        temp->prev = end;

        end = temp;

    }
    len ++;

}

Gen *GenLists::GetStart() {
    return start;
}
