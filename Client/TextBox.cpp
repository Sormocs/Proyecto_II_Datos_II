/**
 * @file TextBox.cpp
 * @author Sergio MB
 * @brief Definicion de metodos de la clase TextBox
 */

#include "TextBox.h"

/**
 * @brief Constructor de la clase textbox, recibe posicion, largo y alto, ajuste para la letra.
 * @param Posx
 * @param Posy
 * @param Width
 * @param Height
 * @param Fsize
 */
TextBox::TextBox(int Posx, int Posy, int Width, int Height, int Fsize) {
    posy = Posy;
    posx = Posx;
    width = Width;
    height = Height;
    fsize = Fsize;
    charlim = 10;
    currchar = 0;

    Build();
}

/**
 * @brief Metodo para generar el area y texto iniciales del cuadro de texto.
 */
void TextBox::Build() {

    sf::RectangleShape box(sf::Vector2f(width,height));
    box.setPosition(posx,posy);
    box.setFillColor(sf::Color(128,128,128));

    if (selected){
        box.setOutlineColor(sf::Color::White);
        box.setOutlineThickness(4);
    } else{
        box.setOutlineColor(sf::Color(255,255,255,0));
    }

    area = box;

    if (!font.loadFromFile("../Fonts/FontdinerSwanky.ttf")) std::cout << "Failed to load font" << std::endl;

    text.setFont(font);
    text.setCharacterSize(fsize);
    text.setColor(sf::Color::White);
    text.setPosition(sf::Vector2f(posx+5,posy+5));
    text.setString("");

}

/**
 * @brief Metodo para ver si el cuadro esta seleccionado, retorna true o false
 * @return bool
 */
bool TextBox::isSelected() {
    return selected;
}

/**
 * @brief Metodo para escribir lo que introduzca el usuario con el teclado
 * @param val
 */
void TextBox::Wrtie(char val) {

    if (currchar < charlim){
        std::string character = std::string(1,val);
        std::string valstr = text.getString();
        valstr += character;
        text.setString(valstr);
        currchar += 1;
    }
}

/**
 * @brief Metodo que se encarga de colocar en pantalla el cuadro y el texto. Recibe el puntero a la ventana.
 * @param win
 */
void TextBox::Draw(sf::RenderWindow* win) {
    win->draw(area);
    win->draw(text);
}

/**
 * @brief Metodo que revisa la posicion donde se haya dado click en la ventana para actiivar o desactivar el cuadro de texto.
 * @param x
 * @param y
 */
void TextBox::CheckClick(int x, int y) {

    if (posx < x && x < posx + width && posy < y && y < posy + height){

        selected = true;
        area.setOutlineColor(sf::Color::White);
        area.setOutlineThickness(4);

    } else {

        selected = false;
        area.setOutlineColor(sf::Color(255,255,255,0));
    }

}

/**
 * @brief Metodo para eliminar la ultima letra del texto en el objeto.
 */
void TextBox::Delete() {
    if (text.getString() != ""){
        std::string valstr = text.getString();
        valstr.erase(valstr.end() - 1,valstr.end());
        text.setString(valstr);
        currchar -= 1;
    }
}

std::string TextBox::GetString() {
    return text.getString();
}



