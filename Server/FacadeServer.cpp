//
// Created by richmond on 27/5/21.
//

#include "FacadeServer.h"
/**
 * @brief constructor de FacadeServer
 */
FacadeServer::FacadeServer() {
    matrix = new Matrix(5,12);
}

/**
 * @brief Divide a cual juego pertece la peditición
 * @param data string
 */
void FacadeServer::ReciveInfo(string data) {
    cout << data << endl;
    json obj = json::parse(data);
    std::string game = obj["game"].get<string>();

    if(game == "BP"){
        GameBP(data);
    } else{
        //codigo otro jueguito sergio yamete kudasai
    }

}

/**
 * @brief eligue la opcion del juego
 * @param data string
 */
void FacadeServer::GameBP(string data) {

    json obj = json::parse(data);
    std::string action = obj["action"].get<string>();

    if (action == "StartBP"){
        UpdateMatrix(obj);
    } else if(action == "StartA"){
        StarAlg(obj);
    } else if(action == "BackA"){
        BackAlg(obj);
    }
}

/**
 * @brief Actualiza la matriz
 * @param obj json
 */
void FacadeServer::UpdateMatrix(json obj) {

    int size = obj["size"].get<int>();

    matrix->GenerateMatrix();

    for (int i = 0; i < size; i++) {

        int index = obj[std::to_string(i)]["i"].get<int>();
        int jindex = obj[std::to_string(i)]["j"].get<int>();

        matrix->Update(index,jindex);
    }

    matrix->PrintM();
    cout << endl;
    this->flag = false;

}

/**
 * @brief Llama al algoritmo backtracking
 * @param obj json
 */
void FacadeServer::BackAlg(json obj) {

    int i = obj["i"].get<int>();
    int j = obj["j"].get<int>();
    int fi = obj["fi"].get<int>();
    int fj = obj["fj"].get<int>();

    std::string path = matrix->AlgBackttracking(i,j,fi,fj);

    this->send = path;
    this->flag = true;

}

/**
 * @brief Llama al algoritmo pathfiding A*
 * @param obj json
 */
void FacadeServer::StarAlg(json obj) {

    int i = obj["i"].get<int>();
    int j = obj["j"].get<int>();
    int fi = obj["fi"].get<int>();
    int fj = obj["fj"].get<int>();

    std::string path = matrix->AlAStart(i,j,fi,fj);

    this->send = path;
    this->flag = true;

}

/**
 * @brief retorna el mensaje a enviar
 * @return string
 */
std::string FacadeServer::GetSend() {
    return send;
}
/**
 * @brief retorna el flag
 * @return bool
 */
bool FacadeServer::GetFlag() {
    return flag;
}