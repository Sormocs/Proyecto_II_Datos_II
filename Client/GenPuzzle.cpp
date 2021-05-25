#include "GenPuzzle.h"

GenPuzzle* GenPuzzle::instance = nullptr;

GenPuzzle *GenPuzzle::getInstance() {
    if (instance == nullptr){
        instance = new GenPuzzle;
    }
    return instance;
}

bool GenPuzzle::Run() {
    sf::RenderWindow window(sf::VideoMode(1000, 700), "Genetic Puzzle", sf::Style::Titlebar | sf::Style::Close);
    sf::Vector2i centerwin(0, 0);
    window.setPosition(centerwin);
    float mouse[2] = {};
    sf::RenderWindow *winptr = &window;

    while (window.isOpen()) {
        sf::Event event;
        mouse[0] = sf::Mouse::getPosition(window).x;
        mouse[1] = sf::Mouse::getPosition(window).y;
        while (window.pollEvent(event)) {

            if (event.type == sf::Event::Closed) {
                window.close();
                return true;
            }
        }
    }
    return false;
}
