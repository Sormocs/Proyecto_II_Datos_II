#include "BPGame.h"

BPGame* BPGame::instance = nullptr;

BPGame *BPGame::getInstance() {
    if (instance == nullptr){
        instance = new BPGame;
    }
    return instance;
}

bool BPGame::Run() {

    sf::RenderWindow window(sf::VideoMode(1000, 700), "BP Game", sf::Style::Titlebar | sf::Style::Close);
    sf::Vector2i centerwin(0, 0);
    window.setPosition(centerwin);
    float mouse[2] = {};
    sf::RenderWindow *winptr = &window;

    if (!font.loadFromFile("../Fonts/FontdinerSwanky.ttf")) std::cout << "Failed to load font" << std::endl;

    sf::Color btncolor = sf::Color(0, 128, 128, 255);
    Button addp = Button(500, 450, 80, 50, 32, "MORE", btncolor);
    Button removep = Button(400, 450, 80, 50, 32, "LESS", btncolor);
    Button accept = Button(400, 520, 180, 75, 26, "Let's Play", btncolor);

    //TEXTS:
    sf::Text playernum;
    playernum.setString("0" + std::to_string(players));
    playernum.setFont(font);
    playernum.setCharacterSize(170);
    playernum.setColor(sf::Color::White);
    playernum.setPosition(390, 230);


    sf::Text title1;
    title1.setString("Amount of players:");
    title1.setFont(font);
    title1.setCharacterSize(50);
    title1.setColor(sf::Color::White);
    title1.setPosition(280, 160);

    sf::Text title2;
    title2.setString("Player 1:");
    title2.setFont(font);
    title2.setCharacterSize(50);
    title2.setColor(sf::Color::White);
    title2.setPosition(70, 300);

    sf::Text title3;
    title3.setString("Player 2:");
    title3.setFont(font);
    title3.setCharacterSize(50);
    title3.setColor(sf::Color::White);
    title3.setPosition(680, 300);

    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~/
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~/
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~/

    sf::RectangleShape field;
    field.setSize(sf::Vector2f(810,405)); // 405/3 = 135 para, cada cuadro de 135x135
    field.setPosition(90,150);
    field.setFillColor(sf::Color(102,204,0,255));

    while (window.isOpen()) {
        sf::Event event;
        mouse[0] = sf::Mouse::getPosition(window).x;
        mouse[1] = sf::Mouse::getPosition(window).y;

        if (selection) {

            while (window.pollEvent(event)) {

                if (event.type == sf::Event::Closed) {
                    window.close();
                    return true;
                } else if (event.type == sf::Event::MouseButtonReleased) {
                    if (addp.Clicked(mouse[0], mouse[1]) and players < 17) {

                        players += 2;
                        if (players > 9) playernum.setString(std::to_string(players));
                        else playernum.setString("0" + std::to_string(players));

                    } else if (removep.Clicked(mouse[0], mouse[1]) and players != 2) {

                        players -= 2;
                        if (players > 9) playernum.setString(std::to_string(players));
                        else playernum.setString("0" + std::to_string(players));

                    } else if (accept.Clicked(mouse[0], mouse[1])) {

                        //EXTRAS ?
                        selection = false;
                    }

                } else if (event.type == sf::Event::MouseMoved) {

                    addp.MouseOver(mouse[0], mouse[1]);
                    removep.MouseOver(mouse[0], mouse[1]);
                    accept.MouseOver(mouse[0], mouse[1]);

                }
            }
            window.clear();

            removep.Draw(winptr);
            addp.Draw(winptr);
            accept.Draw(winptr);
            window.draw(title1);
            window.draw(title2);
            window.draw(title3);
            window.draw(playernum);

            window.display();

        } else {
            while (window.pollEvent(event)) {

                if (event.type == sf::Event::Closed) {
                    window.close();
                    return true;
                } else if (event.type == sf::Event::MouseButtonReleased) {

                }
            }
            window.clear();

            window.draw(field);

            window.display();
        }
    }
    return false;

}
