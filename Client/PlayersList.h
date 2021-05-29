/**
 * @file PlayerList.h
 * @author Sergio MB
 * @brief Lista enlazada para los jugadores en pantalla
 */

#include "SFML/Graphics.hpp"

#pragma once

/**
 * @brief Clase de jugador que actua como nodo de lista enlazada.
 */
class Player {
private:
    Player *next;
    Player *prev;
    sf::Sprite* obj;

public:
    int index, jindex;
    Player* GetNext();
    Player* GetPrev();
    sf::Sprite* GetObj();
    void SetNext(Player* Next);
    void SetPrev(Player* Prev);
    void SetObj(sf::Sprite* img);
    void SetIndex(int posi,int posj);


};

/**
 * @brief Clase PlayerList que contiene elementos Player para formar una lista enlazada
 */
class PlayersList {
private:
    Player* start = nullptr;
    Player* end = nullptr;
    int size = 0;
public:

    PlayersList() = default;
    void Reset();
    void Insert(int x, int y, int posx, int posy);
    Player* GetStart();
    Player* GetEnd();
    int GetSize();

};

