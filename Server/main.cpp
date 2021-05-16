#include <iostream>
#include <thread>
#include "ServerSocket.h"

void RunServer(){
    std::cout << "Server starting please wait a few seconds..." <<std::endl;
    ServerSocket::getInstance()->Start();
}

int main() {

    std::thread RunS (RunServer);

    RunS.join();

    return 0;
}
