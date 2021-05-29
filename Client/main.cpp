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

/**
 * @brief Funcion main para correr el codigo
 * @return int
 */
int main() {
    //std::thread RunC (RunClient);

    GUI::getInstance()->Run();

    //RunC.join();
    return 0;
}
