//
// Created by richmond on 27/5/21.
//



#include <cstdio>
#define N 5
#define M 12

class Matrix {

private:

    int i;
    int j;
    int matrix[N][M];
    int path[N][M];

public:

    Matrix(int x, int y);
    void GenerateMatrix();


};

