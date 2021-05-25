#include <iostream>
#include "Button.h"

#pragma once

class GenPuzzle {
private:
    static GenPuzzle* instance;
    GenPuzzle() = default;

public:
    static GenPuzzle* getInstance();
    bool Run();
};

