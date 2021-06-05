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

    //BUTTONS
    sf::Color btncolor = sf::Color(0, 128, 128, 255);
    Button accept = Button(400, 520, 180, 75, 26, "Begin", btncolor);

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
                            }
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

                }
                window.clear();

                window.draw(title1);
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
            }
            window.clear();

            window.draw(bg);
            DrawParts(winptr);

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
            part->setTextureRect(sf::IntRect(x_part,y_part,x_part+div,y_part+div));
            part->setPosition(x,y);
            Parts->Insert(x,y,num,part);

            x_part += div;
            x += div + 15;

            num++;
        }
        y_part += div;
        y += div + 15;

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
