//
// Created by richmond on 27/5/21.
//

#include "Astar.h"


Astar::Astar(int a[N][M]){
    for (int i = 0; i < 5; ++i){
        for (int j = 0; j < 12; ++j) {
            matriz[i][j] = a[i][j];
        }
    }

}
Astar::~Astar()
{

}

void Astar::search(NodeAStar* startPos, NodeAStar* endPos){
    if (startPos->x < 0 || startPos->x > row || startPos->y < 0 || startPos->y >col ||
        endPos->x < 0 || endPos->x > row || endPos->y < 0 || endPos->y > col)
        return;
    NodeAStar* current;
    this->startPos = startPos;
    this->endPos = endPos;
    openList.push_back(startPos);
    //Mainly this piece, put the starting node into the openlist and start searching for the next 8 nodes. If the coordinates are too long or return in the closelist, then return. If there is already an openlist, compare the G value of the current node to the node traversed. The G value from the current node to the original parent node If the original G value is relatively large, don't care otherwise, re-assign the G value of the parent node and f. If a new node is added to the openlist until the oppellist is empty or the end point is found
    while (openList.size() > 0){
        current = openList[0];
        if (current->x == endPos->x && current->y == endPos->y){
            cout << "find the path" << endl;
            printMap();
            printPath(current);
            this->path = GetPath();
            openList.clear();
            closeList.clear();
            break;
        }
        NextStep(current);
        closeList.push_back(current);
        openList.erase(openList.begin());
        sort(openList.begin(), openList.end(), compare);
    }
}

void Astar::checkPoit(int x, int y, NodeAStar* father, int g){
    if (x < 0 || x > row || y < 0 || y > col)
        return;
    if (this->unWalk(x, y))
        return;
    if (isContains(&closeList, x, y) != -1)
        return;
    int index;
    if ((index = isContains(&openList, x, y)) != -1){
        NodeAStar *point = openList[index];
        if (point->g > father->g + g){
            point->father = father;
            point->g = father->g + g;
            point->f = point->g + point->h;
        }
    }
    else{
        NodeAStar * point = new NodeAStar(x, y, father);
        countGHF(point, endPos, g);
        openList.push_back(point);
    }
}

void Astar::NextStep(NodeAStar* current){
    checkPoit(current->x-1, current->y, current, WeightW);//Left
    checkPoit(current->x + 1, current->y, current, WeightW);//right
    checkPoit(current->x, current->y + 1, current, WeightW);//On
    checkPoit(current->x, current->y-1, current, WeightW);//Next
    checkPoit(current->x-1, current->y + 1, current, WeightWH);//top left
    checkPoit(current->x-1, current->y-1, current, WeightWH);//bottom left
    checkPoit(current->x + 1, current->y-1, current, WeightWH);//bottom right
    checkPoit(current->x + 1, current->y + 1, current, WeightWH);//top right
}

int Astar::isContains(vector<NodeAStar*>* Nodelist, int x, int y){
    for (int i = 0; i < Nodelist->size(); i++)
    {
        if (Nodelist->at(i)->x == x && Nodelist->at(i)->y == y)
        {
            return i;
        }
    }
    return -1;
}

void Astar::countGHF(NodeAStar* sNode, NodeAStar* eNode, int g){
    int h = (abs(sNode->x - eNode->x) + abs(sNode->y - eNode->y)) * WeightW;
    int currentg = sNode->father->g + g;
    int f = currentg + h;
    sNode->f = f;
    sNode->h = h;
    sNode->g = currentg;
}

bool Astar::compare(NodeAStar* n1, NodeAStar* n2){
    //printf("%d,%d",n1->f,n2->f);
    return n1->f < n2->f;
}

bool Astar::unWalk(int x, int y){
    if (matriz[x][y] == 1)
        return true;
    return false;
}

void Astar::printPath(NodeAStar* current){
    if (current->father != NULL)
        printPath(current->father);
    printf("(%d,%d)", current->x, current->y);
}

void Astar::printMap(){
    for (int i = 0; i <= row; i++){
        for (int j = 0; j <= col; j++){
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

std::string Astar::GetPath() {

    json obj;

    int indexPath = 0;

    for (int i = 0; i < closeList.size(); i++) {

        obj[std::to_string(indexPath)]["i"] = closeList.at(i)->x;
        obj[to_string(indexPath)]["j"] = closeList.at(i)->y;
        indexPath++;

    }

    obj[to_string(indexPath+1)]["i"] = 0;
    obj[to_string(indexPath+1)]["j"] = 2;

    obj["size"] = indexPath+1;

    return obj.dump(4);

}

void Astar::Do(int i, int j){

    NodeAStar *startPos = new NodeAStar(i, j);
    NodeAStar *endPos = new NodeAStar(2, 0);
    search(startPos,endPos);

}