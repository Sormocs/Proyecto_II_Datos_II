#include "SFML/Graphics.hpp"

#pragma once

class Player{
private:
    Player* next;
    Player* prev;
    sf::CircleShape* obj;

public:
    Player* GetNext();
    Player* GetPrev();
    sf::CircleShape* GetObj();


};




class PlayersList {

};

