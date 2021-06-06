#include <iostream>
#include <thread>
#include "ServerSocket.h"
#include "GeneticAlgorithm.h"

using namespace std;

void GeneticTest() {

    auto* genAlgo = new GenAlgorithm();
    genAlgo->SetDivisionNum(3);
    genAlgo->Run();

    while (!genAlgo->isSolved());
    cout << "Tardó: " << genAlgo->getTime() << "s. Encontrado en generación: " << genAlgo->getLastGen();
}



void RunServer(){
    std::cout << "Server starting please wait a few seconds..." <<std::endl;
    ServerSocket::getInstance()->Start();
}

int main() {

    GeneticTest();
//    std::thread RunS (RunServer);

//    RunS.join();

    return 0;
}
