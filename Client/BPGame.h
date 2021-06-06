/**
 * @file BPGame.h
 * @author Sergio MB
 * @brief Declaracion de metodos para la clase BPGame.
 */

#include <iostream>
#include <cstdlib>
#include "Button.h"
#include "PlayersList.h"
#include "json.hpp"
#include "ClientSock.h"
#include "PhysController.h"
#include "TextBox.h"
#include "Line.h"
#pragma once

using json = nlohmann::json;

/**
 * @brief Clase BPGame que forma la interfaz del primer juego.
 */
class BPGame {
private:
    bool selection = true;
    static BPGame* instance;
    bool avpos[5][12] = {

            {false, false, false, false, false, false, false, false, false, false, false, false},
            {false, false, false, false, false, false, false, false, false, false, false, false},
            {false, false, false, false, true, true, false, false, false, false, false, false},
            {false, false, false, false, false, false, false, false, false, false, false, false},
            {false, false, false, false, false, false, false, false, false, false, false, false}

    };
    bool pressed = false;
    sf::Font font;
    int players = 2;
    PlayersList* obst = new PlayersList;
    BPGame() = default;
    std::string playerName = "Guest";
    Line line;
    Line invertedLine;
    ClientSock *client = ClientSock::getInstance();


public:
    static BPGame* getInstance();
    bool Run();
    void CreatePlayers(int x, int y);
    void DrawObst(sf::RenderWindow* win);
    void Reset();
    void ResetMatrixPlayer();
    std::string StartGame();
};

