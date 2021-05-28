//
// Created by richmond on 27/5/21.
//

#include "NodeAStar.h"

NodeAStar::NodeAStar(int x, int y) {
    this->x = x;
    this->y = y;
    this->g = 0;
    this->f = 0;
    this->h = 0;
    this->father = NULL;
}

NodeAStar::NodeAStar(int x, int y, NodeAStar* father) {
    this->x = x;
    this->y = y;
    this->g = 0;
    this->f = 0;
    this->h = 0;
    this->father = father;
}