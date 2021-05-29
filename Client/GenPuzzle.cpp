#include "GenPuzzle.h"

GenPuzzle* GenPuzzle::instance = nullptr;

GenPuzzle *GenPuzzle::getInstance() {
    if (instance == nullptr){
        instance = new GenPuzzle;
    }
    return instance;
}

bool GenPuzzle::Run() {

    selection = true;

    if (!font.loadFromFile("../Fonts/FontdinerSwanky.ttf")) std::cout << "Failed to load font" << std::endl;

    sf::RenderWindow window(sf::VideoMode(1000, 700), "Genetic Puzzle", sf::Style::Titlebar | sf::Style::Close);
    sf::Vector2i centerwin(0, 0);
    window.setPosition(centerwin);
    float mouse[2] = {};
    sf::RenderWindow *winptr = &window;

    //TEXTS
    sf::Text title1;
    title1.setString("Picture name:");
    title1.setFont(font);
    title1.setCharacterSize(50);
    title1.setColor(sf::Color::White);
    title1.setPosition(20, 10);

    //TEXT BOX
    TextBox entry = TextBox(20,100,250,55,28);


    while (window.isOpen()) {
        sf::Event event;
        mouse[0] = sf::Mouse::getPosition(window).x;
        mouse[1] = sf::Mouse::getPosition(window).y;

        if (selection) {
            while (window.pollEvent(event)) {

                if (event.type == sf::Event::Closed) {
                    window.close();
                    return true;

                } if (event.type == sf::Event::MouseButtonReleased){
                    entry.CheckClick(mouse[0],mouse[1]);

                } if (event.type == sf::Event::TextEntered){

                    if (entry.isSelected()){
                        if (event.text.unicode == 8){
                            entry.Delete();
                        } else if (event.text.unicode == 13){
                            entry.CheckClick(0,0);
                        } else {
                            char letter = static_cast<char>(event.text.unicode);
                            entry.Wrtie(letter);
                        }
                    }

                }
                window.clear();

                window.draw(title1);
                entry.Draw(winptr);

                window.display();
            }
        } else {
            while (window.pollEvent(event)) {

                if (event.type == sf::Event::Closed) {
                    window.close();
                    return true;
                }
            }
        }
    }
    return false;
}
