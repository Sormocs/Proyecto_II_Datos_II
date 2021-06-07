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

    sf::Text title2;
    title2.setString("Amount of cuts: ");
    title2.setFont(font);
    title2.setCharacterSize(50);
    title2.setColor(sf::Color::White);
    title2.setPosition(280, 160);

    sf::Text cuts;
    if (parts < 10) cuts.setString("0" + std::to_string(parts));
    else cuts.setString(std::to_string(parts));
    cuts.setFont(font);
    cuts.setCharacterSize(170);
    cuts.setPosition(390, 230);


    //TEXT BOX
    TextBox entry = TextBox(20,100,250,55,28);

    //BUTTONS
    sf::Color btncolor = sf::Color(0, 128, 128, 255);
    Button accept = Button(400, 520, 180, 75, 26, "Begin", btncolor);
    Button addc = Button(500, 450, 80, 50, 32, "MORE", btncolor);
    Button removec = Button(400, 450, 80, 50, 32, "LESS", btncolor);

    //BUTTONS FOR SECOND PART
    Button next = Button(800, 450, 90, 50, 32, "Next", btncolor);
    Button prev = Button(800, 390, 90, 50, 32, "Prev", btncolor);

    //SHAPE
    sf::RectangleShape bg = sf::RectangleShape(sf::Vector2f (1000,700));
    bg.setFillColor(sf::Color(154,205,50,255));
    bg.setPosition(0,0);

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

                    if (accept.Clicked(mouse[0],mouse[1])){
                        if (entry.GetString() != "") {
                            if (DivideImage(entry.GetString())) {
                                selection = false;
                                ShuffleParts();
                            }
                        }
                    } if (addc.Clicked(mouse[0],mouse[1])){
                        if (parts < 18) {
                            parts += 2;
                            if (parts < 10) cuts.setString("0" + std::to_string(parts));
                            else cuts.setString(std::to_string(parts));
                        }
                    } if (removec.Clicked(mouse[0],mouse[1])){
                        if (parts > 4) {
                            parts -= 2;
                            if (parts < 10) cuts.setString("0" + std::to_string(parts));
                            else cuts.setString(std::to_string(parts));
                        }
                    }

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

                } if (event.type == sf::Event::MouseMoved){
                    accept.MouseOver(mouse[0],mouse[1]);
                    addc.MouseOver(mouse[0],mouse[1]);
                    removec.MouseOver(mouse[0],mouse[1]);
                }
                window.clear();

                window.draw(title1);
                window.draw(title2);
                window.draw(cuts);
                addc.Draw(winptr);
                removec.Draw(winptr);
                entry.Draw(winptr);
                accept.Draw(winptr);

                window.display();
            }
        } else {
            while (window.pollEvent(event)) {

                if (event.type == sf::Event::Closed) {
                    window.close();
                    return true;
                }
                if (event.type == sf::Event::MouseButtonReleased){
                    if (next.Clicked(mouse[0],mouse[1]) && currGen < Parts->GetLen()){

                        currGen ++;
                        ResetSprites();

                    }
                    if (prev.Clicked(mouse[0],mouse[1]) && currGen >= 0){

                        currGen --;
                        ResetSprites();
                    }
                }
                if (event.type == sf::Event::MouseMoved){
                    next.MouseOver(mouse[0],mouse[1]);
                    prev.MouseOver(mouse[0],mouse[1]);
                }
            }
            window.clear();

            window.draw(bg);
            DrawParts(winptr);
            next.Draw(winptr);
            prev.Draw(winptr);

            window.display();
        }
    }
    return false;
}

bool GenPuzzle::DivideImage(std::string name) {

    sf::Image image;
    image.create(600,600);

    sf::Image original;
    if (!original.loadFromFile("../LoadedImages/"+name+".jpg")) return false;

    sf::Image *img= new sf::Image;
    *img = ResizeImage(original,image);

    sf::Texture* texture = new sf::Texture;
    texture->loadFromImage(*img);

    int y = 35;

    int real_parts = parts/2;

    int y_part = 0;

    int div = 600/real_parts;

    int num = 0;

    for (int i = 0; i != real_parts; i++){

        int x_part = 0;
        int x = 15;

        for (int j = 0; j != real_parts; j++){

            sf::Sprite* part = new sf::Sprite;
            part->setTexture(*texture);
            part->setTextureRect(sf::IntRect(x_part,y_part,div,div));
            part->setPosition(x,y);
            Parts->Insert(x,y,num,part);

            x_part += div;
            x += div + 1;

            num++;
        }
        y_part += div;
        y += div + 1;

    }

    return true;
}

sf::Image GenPuzzle::ResizeImage(const sf::Image &originalImage, sf::Image &resizedImage) {

    const sf::Vector2u originalImageSize{ originalImage.getSize() };
    const sf::Vector2u resizedImageSize{ resizedImage.getSize() };
    for (unsigned int y{ 0u }; y < resizedImageSize.y; ++y)
    {
        for (unsigned int x{ 0u }; x < resizedImageSize.x; ++x)
        {
            unsigned int origX{ static_cast<unsigned int>(static_cast<double>(x) / resizedImageSize.x * originalImageSize.x) };
            unsigned int origY{ static_cast<unsigned int>(static_cast<double>(y) / resizedImageSize.y * originalImageSize.y) };
            resizedImage.setPixel(x, y, originalImage.getPixel(origX, origY));
        }
    }

    return resizedImage;

}

void GenPuzzle::DrawParts(sf::RenderWindow *win) {

    Part* temp = Parts->GetStart();
    while (temp != nullptr){

        win->draw(*temp->getPart());
        temp = temp->GetNext();

    }

}

void GenPuzzle::ShuffleParts() {

    int pLen = Parts->GetLen();
    int pos_parts[pLen][2];
    bool av_pos[pLen];
    int offpos[pLen];

    Part* temp = Parts->GetStart();
    for (int i = 0; i < pLen; i++){ //GET POSITIONS

        pos_parts[i][0] = temp->getPart()->getPosition().x;
        std::cout << "// x = " << pos_parts[i][0] << " ";
        pos_parts[i][1] = temp->getPart()->getPosition().y;
        std::cout << "y = " << pos_parts[i][0] << " ";
        av_pos[i] = true;
        temp = temp->GetNext();

    }
    std::cout << "" << std::endl;
    positions->Insert();
    positions->Insert();
    for (int i = 0; i < pLen; i++){

        positions->GetStart()->Insert(pos_parts[i][0]);
        positions->GetEnd()->Insert(pos_parts[i][1]);


    }

    temp = Parts->GetStart();
    while (temp != nullptr){
        int randi = rand()%pLen;
        if (av_pos[randi]){

            temp->getPart()->setPosition(pos_parts[randi][0],pos_parts[randi][1]);
            av_pos[randi] = false;
            offpos[randi] = temp->GetNum();
            temp = temp->GetNext();

        } else continue;
    }

    generations->Insert();

    for (int i = 0; i < pLen; i++) {

        generations->GetStart()->Insert(offpos[i]);

    }

    IWillHaveOrder();

}

void GenPuzzle::IWillHaveOrder() {

    bool isDone[Parts->GetLen()];
    for (int i = 0; i < Parts->GetLen(); i++){
        isDone[i] = false;
    }

    int i = 0;
    while (i < Parts->GetLen()) {
        int currPos[Parts->GetLen()];

        Position *temp = generations->GetEnd()->start;
        for (int i2 = 0; i2 < Parts->GetLen(); i2++) {
            currPos[i2] = temp->pos;
            temp = temp->next;
        }

        if (i != currPos[i]){
            int toSwitch = currPos[i];
            for (int j =0; j < Parts->GetLen(); j++){
                if (currPos[j] == i){
                    currPos[j] = toSwitch;
                } else continue;
            }
        }
        currPos[i] = i;

        for (int i = 0; i < Parts->GetLen(); i++) {
            std::cout << currPos[i];
        }

        generations->Insert();

        for (int i = 0; i < Parts->GetLen(); i++) {
            generations->GetEnd()->Insert(currPos[i]);
        }

        i ++;
        std::cout <<" " <<i << std::endl;
    }

    Gen* temp = generations->GetStart();
    while (temp != nullptr) {
        Position *temp2 = temp->start;
        while (temp2 != nullptr) {
            std::cout << temp2->pos << " ";
            temp2 = temp2->next;
        }
        temp = temp->next;
        std::cout << " = Full Gen" << std::endl;
    }
}

void GenPuzzle::ResetSprites() {

    int pos_parts[Parts->GetLen()][2];

    Position* temp1 = positions->GetStart()->start;
    Position* temp2 = positions->GetEnd()->start;
    for (int i = 0; i < Parts->GetLen(); i++){

        pos_parts[i][0] = temp1->pos;
        std::cout << "// x = " << pos_parts[i][0] << " ";
        pos_parts[i][1] = temp2->pos;
        std::cout << " y = " << pos_parts[i][1] << " ";

        temp1 = temp1->next;
        temp2 = temp2->next;

    }
    std::cout << "" << std::endl;

    Gen* temp = generations->GetStart();
    while (temp != nullptr){

        if (temp->gennum == currGen){

            Position* newTemp = temp->start;
            Part* tempart = Parts->GetStart();
            while (tempart != nullptr){

                tempart->getPart()->setPosition(pos_parts[newTemp->pos][0],pos_parts[newTemp->pos][1]);
                newTemp = newTemp->next;
                tempart = tempart->GetNext();

            }
            break;

        } else temp = temp->next;

    }

}

void GenPuzzle::SendParts() {

    json obj;

    obj["game"] = "Gen";
    obj["action"] = "Parts";
    obj["parts"] = parts;

    client->Send(obj.dump(4));

}