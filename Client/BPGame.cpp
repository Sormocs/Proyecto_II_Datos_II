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
    Button computerPlay = Button(400, 600, 180, 75, 26, "Computer play", btncolor);

    //TEXTS:
    sf::Text playernum;
    if (players < 10) playernum.setString("0" + std::to_string(players));
    else playernum.setString(std::to_string(players));
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
    title2.setPosition(60, 300);

    //NAME TEXTBOX
    TextBox name_entry = TextBox(60,title2.getPosition().y + title2.getLocalBounds().height + 15, 260,55,28);

    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~/
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~/
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~/

    //TEXTS
    sf::Text playertxt;
    playertxt.setString("Player: "+playerName);
    playertxt.setFont(font);
    playertxt.setCharacterSize(30);
    playertxt.setColor(sf::Color::White);
    playertxt.setPosition(10, 10);

    sf::Text computertxt;
    computertxt.setString("Computer");
    computertxt.setFont(font);
    computertxt.setCharacterSize(30);
    computertxt.setColor(sf::Color::White);
    computertxt.setPosition(800, 10);

    sf::Text goalPlayer;
    goalPlayer.setString(std::to_string(goalP));
    goalPlayer.setFont(font);
    goalPlayer.setCharacterSize(30);
    goalPlayer.setColor(sf::Color::White);
    goalPlayer.setPosition(10, 40);

    sf::Text goalComputer;
    goalComputer.setString(std::to_string(goalC));
    goalComputer.setFont(font);
    goalComputer.setCharacterSize(30);
    goalComputer.setColor(sf::Color::White);
    goalComputer.setPosition(800, 40);


    //FIELD
    sf::Texture* fieldimg = new sf::Texture;
    fieldimg->loadFromFile("../Pictures/field.jpg");
    sf::Sprite* fields = new sf::Sprite;
    fields->setTexture(*fieldimg);
    fields->setPosition(sf::Vector2f(75,130));

    sf::RectangleShape bg = sf::RectangleShape(sf::Vector2f (1000,700));
    bg.setFillColor(sf::Color(50,205,50,255));
    bg.setPosition(0,0);

    //BALL
    sf::Texture* ball = new sf::Texture;
    ball->loadFromFile("../Pictures/ball.png");

    ballsprite->setTexture(*ball);
    ballsprite->setPosition(sf::Vector2f (840/2+40,405/2+80));


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
                } if (event.type == sf::Event::MouseButtonReleased) {
                    name_entry.CheckClick(mouse[0],mouse[1]);
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
                        if (name_entry.GetString() != ""){
                            playerName = name_entry.GetString();
                            playertxt.setString("Player: "+playerName);
                        }
                        std::string send2 = GetPath();
                        client->Send(send2);
                        playing = true;
                        GeneratePath();
                        player1 = true;
                        computer = false;
                    }

                } if (event.type == sf::Event::MouseMoved) {

                    addp.MouseOver(mouse[0], mouse[1]);
                    removep.MouseOver(mouse[0], mouse[1]);
                    accept.MouseOver(mouse[0], mouse[1]);

                } if (event.type == sf::Event::TextEntered){
                    if (name_entry.isSelected()){
                        if (event.text.unicode == 8){
                            name_entry.Delete();
                        } else if (event.text.unicode == 13){
                            name_entry.CheckClick(0,0);
                        } else {
                            char letter = static_cast<char>(event.text.unicode);
                            name_entry.Wrtie(letter);
                        }
                    }
                }
            }

            window.clear();

            removep.Draw(winptr);
            addp.Draw(winptr);
            accept.Draw(winptr);
            window.draw(title1);
            window.draw(title2);
            name_entry.Draw(winptr);
            window.draw(playernum);

            window.display();

        } else {

            while (window.pollEvent(event)) {

                if (event.type == sf::Event::Closed) {
                    window.close();
                    return true;
                }

                if(player1){

                    std::cout << "hola" << std::endl;

                    if (event.type == sf::Event::MouseButtonPressed) {
                        if (PhysController::Instance()->GetBall()->Clicked(mouse[0], mouse[1])) {

                            pressed = true;

                        }
                    }
                    if (event.type == sf::Event::MouseButtonReleased) {

                        if(computerPlay.Clicked(mouse[0],mouse[1]) and player1 == 0){
                            MoveComputer();
                        }

                        if (pressed) {
                            pressed = false;
                            playing = false;
                            player1 = false;
                            circles->Reset();
                            int force = std::sqrt(std::pow(line.getPoints().getBounds().width,2) + std::pow(line.getPoints().getBounds().height,2));
                            PhysController::Instance()->GetBall()->Throw(force, angle*(180/M_PI));
                            PhysController::Instance()->GetBall()->degree = PhysController::Instance()->FixAngle(PhysController::Instance()->GetBall()->degree);
                            int ballx = PhysController::Instance()->GetBall()->pos[0]-BALL_RADIUS;
                            int bally = PhysController::Instance()->GetBall()->pos[1]-BALL_RADIUS;
                            line = Line(ballx+15,bally+15,ballx+15,bally+15,sf::Color(255,255,255,255));
                            invertedLine = Line(ballx+15,bally+15,ballx+15,bally+15,sf::Color(255,255,255,255));
                            angle = 0;
                        }
                    }
                    if (event.type == sf::Event::MouseMoved) {
                        computerPlay.MouseOver(mouse[0], mouse[1]);
                        if (pressed) {

                            int ballx = PhysController::Instance()->GetBall()->pos[0]-BALL_RADIUS;
                            int bally = PhysController::Instance()->GetBall()->pos[1]-BALL_RADIUS;

                            line = Line(ballx+15,bally+15,mouse[0],bally-(bally-mouse[1]),sf::Color(255,255,255,255));

                            int x2 = ballx+15;
                            int y2 = bally+15;
                            if (mouse[0] > ballx+15 && mouse[1] < bally+15){

                                x2 = line.getPoints().getBounds().left-line.getPoints().getBounds().width;
                                y2 = line.getPoints().getBounds().top+line.getPoints().getBounds().height*2;

                                invertedLine = Line(ballx+15,bally+15,x2,y2,sf::Color::White);

                                angle = (-1)*atan(invertedLine.getPoints().getBounds().height/invertedLine.getPoints().getBounds().width) - M_PI;

                            } else if (mouse[0] < ballx+15 && mouse[1] < bally+15 ){

                                x2 = line.getPoints().getBounds().left+line.getPoints().getBounds().width*2;
                                y2 = line.getPoints().getBounds().top+line.getPoints().getBounds().height*2;

                                invertedLine = Line(ballx+15,bally+15,x2,y2,sf::Color::White);

                                angle = atan(invertedLine.getPoints().getBounds().height/invertedLine.getPoints().getBounds().width) + 2*M_PI;

                            } else if (mouse[0] < ballx+15 && mouse[1] > bally+15){

                                x2 = line.getPoints().getBounds().left+line.getPoints().getBounds().width*2;
                                y2 = line.getPoints().getBounds().top-line.getPoints().getBounds().height;

                                invertedLine = Line(ballx+15,bally+15,x2,y2,sf::Color::White);

                                angle = (-1)*atan(invertedLine.getPoints().getBounds().height/invertedLine.getPoints().getBounds().width);

                            } else{

                                x2 = line.getPoints().getBounds().left-line.getPoints().getBounds().width;
                                y2 = line.getPoints().getBounds().top-line.getPoints().getBounds().height;

                                invertedLine = Line(ballx+15,bally+15,x2,y2,sf::Color::White);

                                angle = atan(invertedLine.getPoints().getBounds().height/invertedLine.getPoints().getBounds().width) + M_PI;

                            }

                        }
                    }


                }




                if (PhysController::Instance()->GetBall()->speed < 1.0 && playing == 0){

                    std::string send = GetPath();
                    client->Send(send);
                    playing = true;
                    GeneratePath();

                }

            }

            if(Goal()){
                ballsprite->setPosition(sf::Vector2f (840/2+40,405/2+80));
                PhysController::Instance()->GetBall()->pos[0] = 840/2+40;
                PhysController::Instance()->GetBall()->pos[1] = 405/2+80;
                PhysController::Instance()->GetBall()->Throw(0.0,0.0);
                circles->Reset();
            }

            window.clear();

            PhysController::Instance()->MoveBall();

            ballsprite->setPosition(PhysController::Instance()->GetBall()->pos[0]-20,PhysController::Instance()->GetBall()->pos[1]-20);

            goalComputer.setString(std::to_string(goalC));
            goalPlayer.setString(std::to_string(goalP));
            window.draw(bg);
            window.draw(playertxt);
            window.draw(computertxt);
            window.draw(goalComputer);
            window.draw(goalPlayer);
            window.draw(*fields);
            window.draw(*ballsprite);
            DrawObst(winptr);
            computerPlay.Draw(winptr);
            if (playing){
                Circle* temp = circles->GetStart();
                while(temp != nullptr){
                    window.draw(*temp->GetCircle());
                    temp = temp->GetNext();
                }
            }
            if (pressed){
                window.draw(line);
                window.draw(invertedLine);
            }

            window.display();
        }
        // permite mostar solo 60 fps
        std::this_thread::sleep_for (std::chrono::milliseconds (16));
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

    PhysController::ResetAll();
    PhysController::Instance()->GetBall()->pos[0] = ballsprite->getPosition().x+BALL_RADIUS*2;
    PhysController::Instance()->GetBall()->pos[1] = ballsprite->getPosition().y+BALL_RADIUS*2;

    ResetMatrixPlayer();
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

            obst->Insert(x+15,y+17,randi,randj);
            PhysController::Instance()->playerList->Add(new PlayerObs(x+PLAYER_RADIUS, y+PLAYER_RADIUS));
            x = 75;
            y = 130;
            avpos[randi][randj] = true;
            p++;

        } else continue;

    }
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

            obst->Insert(x+15,y+17,randi2,randj2);
            PhysController::Instance()->playerList->Add(new PlayerObs(x+PLAYER_RADIUS, y+PLAYER_RADIUS));
            x = 75;
            y = 130;
            avpos[randi2][randj2] = true;
            p2++;

        } else continue;
    }
    std::cout << "Side 2 finished" << std::endl;
    avpos[3][5] = false;
    avpos[3][6] = false;

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

    goalC = 0;
    goalP = 0;
    selection = true;
    players = 2;
    circles->Reset();
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

int BPGame::GetI(int posy) {

    int y = 211;

    for (int i = 0; i < 5 ; i++) {

        if (posy < y) {
            return i;
        }
        y += 81;

    }
}

int BPGame::GetJ(int posx){

    int x = 145;

    for (int j = 0; j < 12; j++) {
        if(posx < x){
            return j;
        }
        x += 70;
    }

}

std::string BPGame::GetPath(){

    int i = GetI(PhysController::Instance()->GetBall()->pos[1]);
    int j = GetJ(PhysController::Instance()->GetBall()->pos[0]);

    json obj;

    obj["game"] = "BP";

    if(player1){
        obj["action"] = "StartA";
    }else{
        obj["action"] = "BackA";
    }

    obj["i"] = i;
    obj["j"] = j;
    obj["fi"] = 2;

    if (player1){
        obj["fj"] = 0;
    } else{
        obj["fj"] = 11;
    }

    return obj.dump(4);

}

void BPGame::GeneratePath() {

    std::string path;

    while (true){
        std::string temp = client->GetReceived();
        std::cout << temp << std::endl;
        if (temp != ""){
            path = temp;
            break;
        }
    }

    json obj = json::parse(path);

    int x = 110;
    int y = 170;

    for (int k = 0; k < obj["size"].get<int>(); k++) {

        int i = obj[std::to_string(k)]["i"].get<int>();
        int j = obj[std::to_string(k)]["j"].get<int>();

        circles->Insert(x + (70*j), y + (70*i));

    }

    timing = true;


}

bool BPGame::Goal() {

    int i = GetI(PhysController::Instance()->GetBall()->pos[1]);
    int j = GetJ(PhysController::Instance()->GetBall()->pos[0]);

    if(i == 2 && j == 11){
        goalC++;
        return true;
    } else if(i == 2 && j == 0){
        goalP++;
        return true;
    } else{
        return false;
    }

}

int BPGame::Win() {

    if (goalP == win ){
        return 1;
    } else if(goalC == win){
        return 2;
    } else {
        return 0;
    }

}

void BPGame::MoveComputer() {
    PhysController::Instance()->GetBall()->Throw(500.0,0);
    player1 = true;
    playing = false;
}