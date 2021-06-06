/**
 * @file main.cpp
 * @brief Archivo principal del proyecto
 */

#include <iostream>
#include "ClientSock.h"
#include "GUI.h"

/**
 * @brief Funcion para correr el thread del cliente
 */
void RunClient(){
    ClientSock::getInstance()->Start();
}

void a(){
    auto* b = new PlayerList();
    for (int i = 0; i < 100; ++i) {
        b->Add(new PlayerObs(i, i));
    }
    std::cout << b->Length() << std::endl;
    std::cout << "Posición x del objeto " << b->Get(random()%100)->getPos();
}

/**
 * @brief Funcion main para correr el codigo
 * @return int
 */
int main() {
//    a();
    //std::thread RunC (RunClient);
    srand(time(NULL));

    GUI::getInstance()->Run();

    //RunC.join();
    return 0;
}
