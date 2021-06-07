#include <iostream>
#pragma once

class Position{
public:
    Position()=default;
    int pos;
    int i;
    Position* next;
    Position* prev;


};

class Gen{
public:
    Gen() = default;
    int gennum;
    int index = 0;
    Position* start = nullptr;
    Position* end = nullptr;
    Gen* next;
    Gen* prev;
    void Insert(int num);
};

class GenLists {
private:
    Gen* start = nullptr;
    Gen* end = nullptr;

public:

    int len = 0;
    GenLists() = default;
    void Insert();
    Gen* GetStart();
    Gen* GetEnd();


};

