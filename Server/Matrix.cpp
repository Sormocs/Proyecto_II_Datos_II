//
// Created by richmond on 27/5/21.
//

#include "Matrix.h"

/**
 * @brief Constructor de matrix
 * @param x int cantidad filas
 * @param y int cantidad columans
 */

Matrix::Matrix(int x, int y) {

    this->i = x;
    this->j = y;
    GenerateMatrix();

}

/**
 * @brief Genera las 2 matrices
 */

void Matrix::GenerateMatrix() {
    for (int k = 0; k < i; ++k) {
        for (int l = 0; l < j; ++l) {
            matrix[k][l] = 0;
            path[k][l] = 0;
        }

    }
}

/**
 * @briefActualiza la matriz
 * @param i int
 * @param j int
 */
void Matrix::Update(int i, int j) {
    this->matrix[i][j] = 1;
}

/**
 * @brief Imprime la matriz
 */
void Matrix::PrintM() {
    for (int k = 0; k < 5; ++k) {
        for (int l = 0; l < 12; ++l) {
            cout << matrix[k][l] << " ";
        }
        cout << endl;
    }
}

/**
 * @brief Ejecuta el algoritmo backtracking
 * @param i int
 * @param j int
 * @param fi int
 * @param fj int
 * @return string
 */
std::string Matrix::AlgBackttracking(int i, int j,int fi, int fj) {

    b = new Backtracking(matrix);
    b->FindPath(i,j,fi,fj,"right");
    std::string path = b->GenerateJsonString();
    delete b;
    return path;

}

/**
 * @brief Ejecuta el algoritmo pathfinding A*
 * @param i int
 * @param j int
 * @param fi int
 * @param fj int
 * @return string
 */
std::string Matrix::AlAStart(int i, int j,int fi, int fj) {

    a = new Astar(matrix);
    a->Do(i,j,fi,fj);
    std::string path = a->path;
    delete a;
    return path;

}

