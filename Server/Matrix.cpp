//
// Created by richmond on 27/5/21.
//

#include "Matrix.h"

Matrix::Matrix(int x, int y) {

    this->i = x;
    this->j = y;
    GenerateMatrix();

}

void Matrix::GenerateMatrix() {
    for (int k = 0; k < i; ++k) {
        for (int l = 0; l < j; ++l) {
            matrix[k][l] = 0;
            path[k][l] = 0;
        }

    }
}

void Matrix::Update(int i, int j) {
    this->matrix[i][j] = 1;
}

void Matrix::PrintM() {
    for (int k = 0; k < 5; ++k) {
        for (int l = 0; l < 12; ++l) {
            cout << matrix[k][l] << " ";
        }
        cout << endl;
    }
}

std::string Matrix::AlgBackttracking(int i, int j) {

    b = new Backtracking(matrix);
    b->FindPath(i,j,3,11,"right");
    std::string path = b->GenerateJsonString();
    delete b;
    return path;

}

std::string Matrix::AlAStart(int i, int j) {

    a = new Astar(matrix);
    a->Do(i,j);
    std::string path = a->path;
    delete a;
    return path;

}

