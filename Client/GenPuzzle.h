#include <iostream>
#include "Button.h"
#include "TextBox.h"

#pragma once

class GenPuzzle {
private:
    static GenPuzzle* instance;
    bool selection;
    sf::Font font;
    GenPuzzle() = default;

public:
    static GenPuzzle* getInstance();
    bool Run();
    void DivideImage();
};

