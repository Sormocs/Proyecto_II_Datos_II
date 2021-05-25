#include <iostream>
#include "ClientSock.h"
#include "GUI.h"

void RunClient(){
    ClientSock::getInstance()->Start();
}


int main() {
    //std::thread RunC (RunClient);

    GUI::getInstance()->Run();
    //RunC.join();
    return 0;
}
