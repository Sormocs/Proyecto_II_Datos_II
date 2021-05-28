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