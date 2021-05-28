//
// Created by richmond on 27/5/21.
//

#include "FacadeServer.h"

FacadeServer::FacadeServer() {
    matrix = new Matrix(5,12);
}

void FacadeServer::ReciveInfo(string data) {
    json obj = json::parse(data);
    std::string game = obj["game"].get<string>();

    if(game == "BP"){
        GameBP(data);
    } else{
        //codigo otro jueguito sergio yamete kudasai
    }

}

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

void FacadeServer::UpdateMatrix(json obj) {

    int size = obj["size"].get<int>();

    matrix->GenerateMatrix();

    for (int i = 0; i < size; i++) {

        int index = obj[std::to_string(i)]["i"].get<int>();
        int jindex = obj[std::to_string(i)]["j"].get<int>();

        matrix->Update(index,jindex);
    }

    matrix->PrintM();

    this->flag = false;

}

void FacadeServer::BackAlg(json obj) {

    int i = obj["i"].get<int>();
    int j = obj["j"].get<int>();

    std::string path = matrix->AlgBackttracking(i,j);

    this->send = path;
    this->flag = true;

}

void FacadeServer::StarAlg(json obj) {

    int i = obj["i"].get<int>();
    int j = obj["j"].get<int>();

    std::string path = matrix->AlAStart(i,j);

    this->send = path;
    this->flag = true;

}

std::string FacadeServer::GetSend() {
    return send;
}

bool FacadeServer::GetFlag() {
    return flag;
}