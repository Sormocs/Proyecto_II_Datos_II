#include <iostream>
#include "Button.h"
#include "TextBox.h"
#include "ImageParts.h"

#pragma once

class GenPuzzle {
private:
    static GenPuzzle* instance;
    bool selection;
    sf::Font font;
    int parts = 4;
    ImageParts* Parts = new ImageParts;
    GenPuzzle() = default;

public:
    static GenPuzzle* getInstance();
    bool Run();
    bool DivideImage(std::string);
    sf::Image ResizeImage(const sf::Image& originalImage, sf::Image& resizedImage);
    void DrawParts(sf::RenderWindow* win);
    void ShuffleParts();
};

