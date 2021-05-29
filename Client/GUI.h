/**
 * @file GUI.h
 * @author Sergio MB
 * @brief Definicion de los metodos de la clase GUI
 */

#include "Button.h"
#include "BPGame.h"
#include "GenPuzzle.h"

#pragma once

/**
 * @brief Clase GUI que conforma la interfaz principal del programa
 */
class GUI {

private:
    static GUI* instance;
    GUI() = default;
    BPGame* bpgame = BPGame::getInstance();
    GenPuzzle* gpuzzle = GenPuzzle::getInstance();

public:
    static GUI* getInstance();
    void Run();

};



