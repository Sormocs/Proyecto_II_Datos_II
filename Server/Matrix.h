//
// Created by richmond on 27/5/21.
//

#include <cstdio>
#include "Backtracking.h"
#include "Astar.h"

#define N 5
#define M 12

class Matrix {

private:

    int i;
    int j;
    int matrix[N][M];
    int path[N][M];
    Backtracking *b;
    Astar *a;

public:

    void Update(int i, int j);
    Matrix(int x, int y);
    void GenerateMatrix();
    void PrintM();
    std::string AlgBackttracking(int i, int j);
    std::string AlAStart(int i,int j);
};

