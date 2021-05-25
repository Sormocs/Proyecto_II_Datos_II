#include "Button.h"
#include "BPGame.h"
#include "GenPuzzle.h"

#pragma once

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



