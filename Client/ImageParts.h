#include <iostream>
#include "SFML/Graphics.hpp"

#pragma once

class Part{
private:
    Part *next;
    Part *prev;
    sf::Sprite* impart;
    int pnum;

public:
    Part() = default;
    sf::Sprite* getPart();
    Part* GetNext();
    Part* GetPrev();
    int GetNum();

    void SetPart(sf::Sprite* Part);
    void SetNext(Part* Next);
    void SetPrev(Part* Prev);
    void SetNum(int Pnum);
};


class ImageParts {
private:
    Part* start;
    Part* end;
public:
    ImageParts() = default;
    void Insert(int x, int y, int num, sf::Sprite* part);
    Part* GetStart();

};

