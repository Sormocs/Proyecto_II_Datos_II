//
// Created by richmond on 27/5/21.
//

#ifndef SERVER_FACADESERVER_H
#define SERVER_FACADESERVER_H

#include <iostream>
#include "json.hpp"
#include "Matrix.h"

using json = nlohmann::json;

class FacadeServer {

private:

    Matrix *matrix;
    std::string send;
    bool flag;

public:

    FacadeServer();
    void ReciveInfo(string data);
    void GameBP(string data);
    void UpdateMatrix(json obj);
    void BackAlg(json obj);
    void StarAlg(json obj);
    std::string GetSend();
    bool GetFlag();

};


#endif //SERVER_FACADESERVER_H
