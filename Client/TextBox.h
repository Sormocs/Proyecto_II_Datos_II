/**
 * @file TextBox.h
 * @author Sergio MB
 * @brief Declaracion de la clase textbox.
 */

#include "SFML/Graphics.hpp"
#include <iostream>
#pragma once

/**
 * @brief Clase text box que permite al usuario introducir texto en alguna parte del programa que se solicite
 */
class TextBox {
private:
    int posx, posy, width, height, fsize, charlim, currchar;
    bool selected;
    sf::RectangleShape area;
    sf::Text text;
    sf::Font font;

public:
    TextBox(int Posx, int Posy, int Width, int Height, int Fsize);
    void Build();
    bool isSelected();
    void Wrtie(char val);
    void Draw(sf::RenderWindow* win);
    void CheckClick(int x, int y);
    void Delete();
};



