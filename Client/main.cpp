#include <iostream>
#include "ClientSock.h"

void RunClient(){
    ClientSock::getInstance()->Start();
}

int main() {
    std::thread RunC (RunClient);

    RunC.join();
    return 0;
}
