/**
 * @file Button.cpp
 * @author Sergio MB
 * @brief Definicion de los metodos de la clase Button.
 */

#include "Button.h"

/**
 * @brief Consiste en el constructor del boton, recibe los datos para su posicion, ancho y alto, ajustes de letra, texto
 * del boton y el color del area del fondo de este.
 * @param Posx
 * @param Posy
 * @param Width
 * @param Height
 * @param Fsize
 * @param Text
 * @param Color
 */
Button::Button(int Posx, int Posy, int Width, int Height,int Fsize ,std::string Text, sf::Color Color) {

    posx = Posx;
    posy = Posy;
    width = Width;
    height = Height;
    text = Text;
    color = Color;
    fsize = Fsize;

    Build();

}

/**
 * @brief Metodo build que se encarga de construir las figuras y asignar los valores respectivos a cada una apenas se crea
 * el texto. Utiliza una formula para que el texto siempre se encuentre centrado en el boton.
 */
void Button::Build() {

    sf::RectangleShape figure(sf::Vector2f(width,height));
    figure.setPosition(posx,posy);
    figure.setFillColor(color);
    figure.setOutlineColor(sf::Color(0,0,0));
    figure.setOutlineThickness(3);

    font.loadFromFile("../Fonts/consolas.ttf");
    sText.setString(this->text);
    sText.setCharacterSize(fsize);
    sText.setFont(font);
    sText.setPosition(posx+(width/2-sText.getLocalBounds().width/2),posy+(height/2-sText.getLocalBounds().height/2)-8);
    sText.setFillColor(sf::Color(255,255,255,255));

    this->area = figure;

}

/**
 * @brief Metodo que se encarga de revisar si se da click en el area del boton, recibe la posicion "x" y "y" donde sucedio el click.
 * @param x
 * @param y
 * @return
 */
bool Button::Clicked(int x, int y) {
    if(enabled) {
        if (posx < x && x < posx + width && posy < y && y < posy + height) {
            return true;

        } else {
            return false;
        }
    }
}

/**
 * @brief Revisa si la posicion del mouse es encima del boton, para resaltar el color del borde.
 * @param x
 * @param y
 */
void Button::MouseOver(int x, int y) {
    if(enabled) {
        if (posx < x && x < posx + width && posy < y && y < posy + height) {

            area.setOutlineColor(sf::Color(255, 255, 255, 255));


        } else {

            area.setOutlineColor(sf::Color(0, 0, 0, 255));

        }
    }
}

/**
 * Dibuja tanto el area como el texto del boton en la interfaz, recibe el puntero de la ventana de GUI.
 * @param win
 */
void Button::Draw(sf::RenderWindow *win) {

    win->draw(area);
    win->draw(sText);

}

/**
 * Retorna true o false dependiendo del caso para verificar si el boton se encuentra desactivado.
 * @return
 */
bool Button::isEnabled() {
    return enabled;
}

/**
 * Activa o desactiva el boton segun el valor booleano que reciba del flag.
 * @param flag
 */
void Button::SetEnabled(bool flag) {

    if (flag) area.setFillColor(color);
    else area.setFillColor(sf::Color(128,128,128,255));
    enabled = flag;

}


