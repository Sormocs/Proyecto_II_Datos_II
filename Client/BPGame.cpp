/**
 * @file BPGame.cpp
 * @author Sergio MB & David Richmond
 * @brief Definicion de los metodos de la clase BPGame para el funcionamiento de la ventana del juego.
 */

#include "BPGame.h"

BPGame* BPGame::instance = nullptr;

/**
 * @brief Metodo para obtener la instancia de la ventana
 * @return BPGame*
 */
BPGame *BPGame::getInstance() {
    if (instance == nullptr){
        instance = new BPGame;
    }
    return instance;
}

/**
 * Metodo para correr la ventana
 * @return bool
 */
bool BPGame::Run() {

    selection = true;

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

    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~/
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~/
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~/

    sf::RectangleShape field;
    field.setSize(sf::Vector2f(840,405)); // 420/6 = 70, 405/5 = 81 para cada cuadro de 70x81
    field.setPosition(75,130);
    field.setFillColor(sf::Color(102,204,0,255));

    while (window.isOpen()) {
        sf::Event event;
        mouse[0] = sf::Mouse::getPosition(window).x;
        mouse[1] = sf::Mouse::getPosition(window).y;

        if (selection) {

            while (window.pollEvent(event)) {

                if (event.type == sf::Event::Closed) {
                    window.close();
                    Reset();
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


                        CreatePlayers(75,130);
                        std::cout << "Players Created" << std::endl;
                        std::string send = StartGame();
                        client->Send(send);
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
            DrawObst(winptr);

            window.display();
        }
    }
    return false;

}

/**
 * @brief Metodo para crear la cantidad de jugadores seleccionados por el usuario en la matriz del juego.
 * @param x
 * @param y
 */
void BPGame::CreatePlayers(int x, int y) {
    obst->Reset();
    ResetMatrixPlayer();
    srand(time(NULL));
    std::cout << "Srand initiated" << std::endl;
    int p = 0;
    while (p < players/2){
        int randi = rand()%5;
        int randj = rand()%5+1;
        if (!avpos[randi][randj]){
            int i = 0;
            while (i<5){
                if (i == randi) break;
                else y += 81;
                i++;
            }
            int j = 0;
            while (j<6){
                if (j==randj) break;
                else x += 70;
                j++;
            }

            obst->Insert(x,y,randi,randj);
            x = 75;
            y = 130;
            avpos[randi][randj] = true;
            //std::cout << avpos << std::endl;
            p++;

        } else continue;

    }
    std::cout << "Side 1 finished" << std::endl;
    int p2 = 0;
    while (p2 < players/2){
        int randi2 = rand()%5;
        int randj2 = rand()%6 + 6;
        if (randj2 == 11) randj2 -=1;
        if (!avpos[randi2][randj2]){
            int i = 0;
            while (i<5){
                if (i == randi2) break;
                else y += 81;
                i++;
            }
            int j = 0;
            while (j<12){
                if (j==randj2) break;
                else x += 70;
                j++;
            }

            obst->Insert(x,y,randi2,randj2);
            x = 75;
            y = 130;
            avpos[randi2][randj2] = true;
            //std::cout << avpos << std::endl;
            p2++;

        } else continue;
    }
    std::cout << "Side 2 finished" << std::endl;

}

/**
 * @brief Metodo para dibujar los obstaculos (jugadores) creados en la ventana.
 * @param win
 */
void BPGame::DrawObst(sf::RenderWindow *win) {

    if (obst->GetStart() != nullptr){

        Player* temp = obst->GetStart();
        while (temp != nullptr){
            win->draw(*temp->GetObj());
            temp = temp->GetNext();
        }

    }

}

/**
 * @brief Metodo para reestablecer los valores de la ventana
 */
void BPGame::Reset() {

    selection = true;
    players = 2;
    obst = new PlayersList;

}

/**
 * @brief Metodo que hace reset de la matriz del juego.
 */
void BPGame::ResetMatrixPlayer() {
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 12; ++j) {
            this->avpos[i][j] = false;
        }

    }
}

/**
 * @brief Metodo para formar el json con la matriz del juegoo para enviar al server
 * @return
 */
std::string BPGame::StartGame() {

    json obj;

    obj["game"] = "BP";
    obj["action"] = "StartBP";
    obj["size"] = obst->GetSize();

    if (obst->GetStart() != nullptr){
        int itemp = 0;
        Player* temp = obst->GetStart();
        while (temp != nullptr){

            obj[std::to_string(itemp)]["i"] = temp->index;
            obj[std::to_string(itemp)]["j"] = temp->jindex;
            itemp++;

            temp = temp->GetNext();
        }

    }

    return obj.dump(4);

}
