/**
 * @file PlayerList.cpp
 * @author Sergio MB
 * @brief Declaracion de los metodos de las clases Player y PlayerList
 */

#include "PlayersList.h"

//NODE
/**
 * @breif Obtiene el nodo siguiente
 * @return Player*
 */
Player *Player::GetNext() {
    return next;
}

/**
 * @breif Obtiene el nodo previo
 * @return PLayer*
 */
Player *Player::GetPrev() {
    return prev;
}

/**
 * @brief Obtiene el objeto sprite que contiene la imagen del jugador
 * @return  sf::Sprite
 */
sf::Sprite *Player::GetObj() {
    return obj;
}

/**
 * @brief Asigna el nodo siguiente
 * @param Next
 */
void Player::SetNext(Player *Next) {

    next = Next;
}

/**
 * @brief Asigna el nodo previo
 * @param Prev
 */
void Player::SetPrev(Player *Prev) {

    prev = Prev;

}

/**
 * @brief Asgina el objeto
 * @param img
 */
void Player::SetObj(sf::Sprite *img) {

    obj = img;

}

/**
 * @brief Asigna el indice en la matriz del juego
 * @param posi
 * @param posj
 */
void Player::SetIndex(int posi, int posj) {

    index = posi;
    jindex = posj;

}

//LIST
/**
 * @brief Obtiene el nodo inicial
 * @return PlayerList*
 */
Player *PlayersList::GetStart() {
    return start;
}

/**
 * @breif Obtiene el nodo final
 * @return PlayerList*
 */
Player *PlayersList::GetEnd() {
    return end;
}

/**
 * @brief Resetea la lista
 */
void PlayersList::Reset() {
    this->start = nullptr;
    this->end = nullptr;
    this->size = 0;
}

/**
 * @brief Obtiene el size de la lista
 * @return
 */
int PlayersList::GetSize() {
    return this->size;
}

/**
 * @brief Metodo para insertar un jugador en la lista, recibe la posicion para la ventana y en la matriz.
 * @param x
 * @param y
 * @param posx
 * @param posy
 */
void PlayersList::Insert(int x, int y, int posx, int posy) {
    sf::Texture* img = new sf::Texture;
    img->loadFromFile("../Pictures/player.png");
    sf::Sprite* sprite = new sf::Sprite;
    sprite->setTexture(*img);
    sprite->setPosition(sf::Vector2f (x,y));

    if (start == nullptr){

        Player* temp = new Player;
        temp->SetIndex(posx,posy);
        temp->SetNext(nullptr);
        temp->SetPrev(nullptr);
        temp->SetObj(sprite);
        start = temp;
        end = temp;

    } else{

        Player* temp = new Player;
        temp->SetIndex(posx,posy);
        temp->SetNext(nullptr);
        temp->SetPrev(end);
        temp->SetObj(sprite);
        end->SetNext(temp);
        end = temp;

    }

    this->size++;
}
