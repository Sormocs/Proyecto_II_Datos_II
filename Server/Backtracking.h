//
// Created by richmond on 27/5/21.
//


#include <iostream>

#define N 5
#define M 12

using namespace std;

class Backtracking {

private:

    int matriz[N][M];
    int path[N][M];

public:

    Backtracking(int A[N][M]);
    void CopyMatrix(int A[N][M]);
    bool ItsPossible(int i, int j, int fi, int fj);
    bool FindPath(int i, int j, int fi, int fj, string direction);
    void PrintPath();


};



