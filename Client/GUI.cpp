
#include "GUI.h"

GUI* GUI::instance = nullptr;

GUI *GUI::getInstance() {
    if (instance == nullptr){
        instance = new GUI;
    }
    return instance;
}

void GUI::Run() {
    sf::RenderWindow window(sf::VideoMode(1000, 700), "Let's PLay", sf::Style::Titlebar | sf::Style::Close);
    sf::Vector2i centerwin(0, 0);
    window.setPosition(centerwin);
    float mouse[2] = {};
    sf::RenderWindow *winptr = &window;

    sf::Color color = sf::Color(0,128,128,255);

    Button game1 = Button(window.getSize().x/2-75,window.getSize().y/2-150,150,75,18,"BP Game",color);

    Button game2 = Button(window.getSize().x/2-75,window.getSize().y/2-50,150,75,18,"Genetic Puzzle",color);

        while (window.isOpen()) {
            sf::Event event;
            mouse[0] = sf::Mouse::getPosition(window).x;
            mouse[1] = sf::Mouse::getPosition(window).y;
            while (window.pollEvent(event)) {

                if (event.type == sf::Event::Closed) {
                    window.close();

                } else if (event.type == sf::Event::MouseButtonReleased) {
                    if (game1.Clicked(mouse[0], mouse[1])) {

                        //CODE FOR TO LAUNCH GAME 1
                        if(!bpgame->getInstance()->Run()) continue;

                    } else if (game2.Clicked(mouse[0], mouse[1])) {

                        //CODE to LAUNCH GAME 2
                        if(!gpuzzle->getInstance()->Run()) continue;

                    }
                } else if (event.type == sf::Event::MouseMoved) {
                    game1.MouseOver(mouse[0], mouse[1]);
                    game2.MouseOver(mouse[0], mouse[1]);
                }

            }
            window.clear();

            game1.Draw(winptr);
            game2.Draw(winptr);
            window.display();

        }
    exit(0);
}

