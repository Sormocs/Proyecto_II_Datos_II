#include <iostream>
#include <cstdlib>
#include "Button.h"
#include "PlayersList.h"

#pragma once

class BPGame {
private:
    bool selection = true;
    static BPGame* instance;
    bool avpos[5][12] = {

            {false, false, false, false, false, false, false, false, false, false, false, false},
            {false, false, false, false, false, false, false, false, false, false, false, false},
            {false, false, false, false, false, false, false, false, false, false, false, false},
            {false, false, false, false, false, false, false, false, false, false, false, false},
            {false, false, false, false, false, false, false, false, false, false, false, false}

    };
    sf::Font font;
    int players = 2;
    PlayersList* obst = new PlayersList;
    BPGame() = default;

public:
    static BPGame* getInstance();
    bool Run();
    void CreatePlayers(int x, int y);
    void DrawObst(sf::RenderWindow* win);
    void Reset();
};

