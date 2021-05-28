//
// Created by richmond on 27/5/21.
//

#include "Backtracking.h"

Backtracking::Backtracking(int (*A)[12]) {
    CopyMatrix(A);
}

void Backtracking::CopyMatrix(int (*A)[12]) {

    for (int i = 0; i < 5; ++i){
        for (int j = 0; j < 12; ++j) {
            matriz[i][j] = A[i][j];
            path[i][j] = 1;
        }
    }

}

bool Backtracking::ItsPossible(int i, int j, int fi, int fj) {
    if(i <= fi && j <= fj && i >= 0 && j >= 0 && matriz[i][j] == 0){
        return true;
    } else{
        return false;
    }
}

bool Backtracking::FindPath(int i, int j, int fi, int fj, string direction) {

    if(i == fi && j == fj){
        path[i][j] = 0;
        return false;
    }

    if (ItsPossible(i,j,fi,fj)){

        path[i][j] = 0;

        if (direction != "up" && FindPath(i+1,j,fi,fj,"down") == 0){
            return false;
        }
        if (direction != "left" && FindPath(i,j+1,fi,fj,"right")== 0) {
            return false;
        }

        if (direction != "down" && FindPath(i-1,j,fi,fj,"up")== 0){
            return false;
        }
        if (direction != "right" && FindPath(i,j-1,fi,fj,"left")== 0) {
            return false;
        }

        path[i][j] = 1;
        return  true;
    }
    return  true;
}

void Backtracking::PrintPath() {

    for (int i = 0; i < 5; ++i){
        for (int j = 0; j < 12; j++) {
            cout << path[i][j] << " ";
        }
        cout << endl;
    }

}