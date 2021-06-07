
#pragma once

class Position{
public:
    Position()=default;
    int pos;
    Position* next;
    Position* prev;


};

class Gen{
public:
    Gen() = default;
    int gennum;
    Position* start;
    Position* end;
    Gen* next;
    Gen* prev;
    void Insert(int num);
};

class GenLists {
private:
    Gen* start;
    Gen* end;

public:

    int len = 0;
    GenLists() = default;
    void Insert();
    Gen* GetStart();


};

