#include <iostream>
#include "Button.h"

#pragma once

class BPGame {
private:
    bool selection = true;
    static BPGame* instance;
    bool avpos[9] = {false, false, false, false, false, false, false, false, false};
    sf::Font font;
    int players = 2;
    BPGame() = default;

public:
    static BPGame* getInstance();
    bool Run();

};

