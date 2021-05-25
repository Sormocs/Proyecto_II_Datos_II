/**
 * @file Button.h
 * @author Sergio MB
 * @brief Declaracion de la clase Button, que corresponde a los botones utilizados en el codigo.
 */

#include <SFML/Graphics.hpp>
#pragma once

/**
 * @brief Declaracion de la clase boton, la cual define un area y un texto que cuando se da click en su posicion retorna true.
 *  Puede activarse y desactivarse.
 */
class Button {

private:

    int posx, posy, width, height, fsize;
    sf::Color bgcolor;
    std::string text = "";
    sf::Text sText;
    sf::Font font;
    sf::RectangleShape area;
    sf::Color color;
    bool enabled = true;

public:

    Button(int Posx, int Posy, int Width, int Height, int Fsize, std::string Text, sf::Color Color);
    void Build();
    bool Clicked(int, int);
    void MouseOver(int, int);
    void Draw(sf::RenderWindow*);
    bool isEnabled();
    void SetEnabled(bool flag);


};



