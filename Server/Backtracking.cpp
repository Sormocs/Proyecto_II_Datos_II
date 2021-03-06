//
// Created by richmond on 27/5/21.
//

#include "Backtracking.h"
/**
 * @brief constructor
 * @param A int[][]
 */
Backtracking::Backtracking(int (*A)[12]) {
    CopyMatrix(A);
}
/*
 * @brief Genera la matriz
 */
void Backtracking::CopyMatrix(int (*A)[12]) {

    for (int i = 0; i < 5; ++i){
        for (int j = 0; j < 12; ++j) {
            matriz[i][j] = A[i][j];
            path[i][j] = 1;
        }
    }

}
/**
 * @brief verifica si la posición es correcta
 * @param i int
 * @param j int
 * @return bool
 */
bool Backtracking::ItsPossible(int i, int j) {
    if(i < 5 && j < 12 && i >= 0 && j >= 0 && matriz[i][j] == 0){
        return true;
    } else{
        return false;
    }
}
/**
 * @brief Encuentra al path actualizando la matriz
 * @param i int
 * @param j int
 * @param fi int
 * @param fj int
 * @param direction
 * @return bool
 */
bool Backtracking::FindPath(int i, int j, int fi, int fj, string direction) {

    if(i == fi && j == fj){
        path[i][j] = 0;
        return false;
    }

    if (ItsPossible(i,j)){

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

/**
 * @brief imprime la matriz
 */
void Backtracking::PrintPath() {

    for (int i = 0; i < 5; ++i){
        for (int j = 0; j < 12; j++) {
            cout << path[i][j] << " ";
        }
        cout << endl;
    }

}

/**
 * @brief Genera el string de un json con los datos a enviar
 * @return string
 */
std::string Backtracking::GenerateJsonString() {

    json obj;
    int index = 0;

    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 12; j++) {
            if (path[i][j] == 0){
                obj[std::to_string(index)]["i"] = i;
                obj[std::to_string(index)]["j"] = j;
                index++;
            }
        }
    }

    obj["size"] = index;

    return obj.dump(4);

}