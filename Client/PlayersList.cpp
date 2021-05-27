#include "PlayersList.h"

//NODE
Player *Player::GetNext() {
    return next;
}

Player *Player::GetPrev() {
    return prev;
}

sf::Sprite *Player::GetObj() {
    return obj;
}

void Player::SetNext(Player *Next) {

    next = Next;
}

void Player::SetPrev(Player *Prev) {

    prev = Prev;

}

void Player::SetObj(sf::Sprite *img) {

    obj = img;

}

void Player::SetIndex(int posi, int posj) {

    index = posi;
    jindex = posj;

}

//LIST
Player *PlayersList::GetStart() {
    return start;
}

Player *PlayersList::GetEnd() {
    return end;
}

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
}
