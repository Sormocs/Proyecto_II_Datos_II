//
// Created by richmond on 27/5/21.
//


#include "json.hpp"
#include <iostream>
#include <queue>
#include <vector>
#include <stack>
#include <algorithm>
#include "NodeAStar.h"

#define N 5
#define M 12

using json = nlohmann::json;

class Astar {

public:

    std::string path;
    int matriz[N][M];
    vector<NodeAStar *> openList;
    vector<NodeAStar *> closeList;
    NodeAStar *startPos;
    NodeAStar *endPos;
    static const int WeightW = 10;
    static const int WeightWH = 14;
    static const int row = 4;
    static const int col = 11;

    Astar(int a[N][M]);
    ~Astar();
    void search(NodeAStar *startPos, NodeAStar *endPos);
    void checkPoit(int x, int y, NodeAStar *father, int g);
    void NextStep(NodeAStar *currentPoint);
    int isContains(vector<NodeAStar *> *Nodelist, int x, int y);
    void countGHF(NodeAStar *sNode, NodeAStar *eNode, int g);
    static bool compare(NodeAStar *n1, NodeAStar *n2);
    bool unWalk(int x, int y);
    void printPath(NodeAStar *current);
    void printMap();
    std::string GetPath();
    void Do(int i, int j);




};

