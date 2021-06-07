
#include "ImageParts.h"


//PARTS
sf::Sprite *Part::getPart() {
    return impart;
}

Part *Part::GetNext() {
    return next;
}

Part *Part::GetPrev() {
    return prev;
}

int Part::GetNum() {
    return pnum;
}

void Part::SetPart(sf::Sprite *Part) {

    impart = Part;

}

void Part::SetNext(Part *Next) {

    next = Next;

}

void Part::SetPrev(Part *Prev) {

    prev = Prev;

}

void Part::SetNum(int Pnum) {

    pnum = Pnum;

}

//LIST

void ImageParts::Insert(int x, int y, int num, sf::Sprite* part) {

    Part* part1 = new Part;
    part->setPosition(x,y);
    part1->SetNum(num);
    part1->SetPart(part);

    if (start == nullptr){

        part1->SetNext(nullptr);
        part1->SetPrev(nullptr);

        start = part1;
        end = part1;

    } else {

        part1->SetPrev(end);
        part1->SetNext(nullptr);

        end->SetNext(part1);
        end = part1;

    }
    len += 1;


}

Part *ImageParts::GetStart() {
    return start;
}

int ImageParts::GetLen() {
    return len;
}
