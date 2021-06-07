#include <iostream>
#include "tinyxml2.h"
#include "Lists.h"

#pragma once


using namespace tinyxml2;
class XML {
private:
    XMLDocument doc;
    int gennum = 0;
    static XML* instance;
    List* genList = nullptr;
    XML() = default;
public:
    static XML* GetInstance();
    void SetList(List* list);
    void Builder();

};



