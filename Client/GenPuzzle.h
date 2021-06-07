#include <iostream>
#include "Button.h"
#include "TextBox.h"
#include "ImageParts.h"
#include "GenLists.h"
#include "json.hpp"
#include "ClientSock.h"
#pragma once
using json = nlohmann::json;

class GenPuzzle {
private:
    static GenPuzzle* instance;
    bool selection;
    sf::Font font;
    int parts = 4;
    int currGen = 0;
    GenLists* positions = new GenLists;
    ImageParts* Parts = new ImageParts;
    GenLists* generations = new GenLists;
    GenPuzzle() = default;
    ClientSock *client = ClientSock::getInstance();

public:
    static GenPuzzle* getInstance();
    bool Run();
    bool DivideImage(std::string);
    sf::Image ResizeImage(const sf::Image& originalImage, sf::Image& resizedImage);
    void DrawParts(sf::RenderWindow* win);
    void ShuffleParts();
    void IWillHaveOrder();
    void SendParts();
    void ResetSprites();
};

