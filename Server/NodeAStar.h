//
// Created by richmond on 27/5/21.
//



#include <iostream>
using namespace std;

class NodeAStar {

public:

    int x;
    int y;
    int g;
    int f;
    int h;

    NodeAStar* father;

    NodeAStar(int x, int y);
    NodeAStar(int x, int y, NodeAStar* father);

};


