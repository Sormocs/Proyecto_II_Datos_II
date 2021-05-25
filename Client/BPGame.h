#include <iostream>
#include "Button.h"

#pragma once

class BPGame {
private:
    bool selection = true;
    static BPGame* instance;
    BPGame() = default;

public:
    static BPGame* getInstance();
    bool Run();
};

