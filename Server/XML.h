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
    GenList* genList = nullptr;
    std::string infoMaker();
    XML() = default;
    std::string GenBuilder(const std::string& info);
public:
    static XML* GetInstance();
    void SetList(GenList* list);
    void Build();
};



