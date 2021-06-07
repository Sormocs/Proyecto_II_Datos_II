/**
 * @file BPGame.h
 * @author Sergio MB
 * @brief Declaracion de metodos para la clase BPGame.
 */

#include <iostream>
#include <cstdlib>
#include <thread>
#include <math.h>
#include "Button.h"
#include "PlayersList.h"
#include "json.hpp"
#include "ClientSock.h"
#include "PhysController.h"
#include "TextBox.h"
#include "Line.h"
#include "CirclesList.h"
#pragma once

using json = nlohmann::json;

/**
 * @brief Clase BPGame que forma la interfaz del primer juego.
 */
class BPGame {
private:
    bool selection = true;
    bool playing = false;
    bool player1 = true;
    bool timing = false;
    bool computer = false;
    int goalP = 0;
    int goalC = 0;
    int win;
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
    float angle = 0;
    PlayersList* obst = new PlayersList;
    BPGame() = default;
    std::string playerName = "Guest";
    Line line;
    Line invertedLine;
    CirclesList *circles = new CirclesList;
    ClientSock *client = ClientSock::getInstance();
    sf::Sprite* ballsprite = new sf::Sprite;


public:
    static BPGame* getInstance();
    bool Run();
    void CreatePlayers(int x, int y);
    void DrawObst(sf::RenderWindow* win);
    void Reset();
    void ResetMatrixPlayer();
    void GeneratePath();
    std::string StartGame();
    std::string GetPath();
    int GetI(int posy);
    int GetJ(int posx);
    bool Goal();
    int Win();
    void MoveComputer();
};

