//
// Created by richmond on 5/6/21.
//

#include "SFML/Graphics.hpp"

#pragma once


class Circle{
private:
    Circle* next;
    sf::CircleShape *obj;

public:

    Circle* GetNext();
    sf::CircleShape* GetCircle();
    void SetNext(Circle* Next);
    void SetObj(sf::CircleShape* circle);

};


class CirclesList {

private:

    Circle* start = nullptr;
    int size = 0;

public:

    CirclesList() = default;
    void Reset();
    void Insert(int posx, int posy);
    Circle* GetStart();
    int GetSize();

};


