//
// Created by richmond on 5/6/21.
//

#include "CirclesList.h"
Circle* Circle::GetNext() {
    return next;
}

sf::CircleShape* Circle::GetCircle() {
    return obj;
}

void Circle::SetNext(Circle *Next) {
    next = Next;
}

void Circle::SetObj(sf::CircleShape *circle) {
    obj = circle;
}

void CirclesList::Reset() {
    size = 0;
    start = nullptr;
}

void CirclesList::Insert(int posx, int posy) {

    sf::CircleShape *tempC = new sf::CircleShape;
    tempC->setRadius(4);
    tempC->setPosition(posx,posy);
    tempC->setFillColor(sf::Color(255,0,0,125));

    if(start == nullptr){
        Circle *temp = new Circle;
        temp->SetObj(tempC);
        start = temp;
    } else{
        Circle *temp = new Circle;
        temp->SetObj(tempC);
        temp->SetNext(start);
        start = temp;
    }

}



