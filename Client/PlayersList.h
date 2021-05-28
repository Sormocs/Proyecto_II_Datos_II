#include "SFML/Graphics.hpp"

#pragma once

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

