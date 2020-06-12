#include "cmenu.h"

cmenu::cmenu()
{
    if (!font.loadFromFile("arial.ttf"))
    {

    }
    int height = WINDOW_HEIGHT;
    int width = WINDOW_WIDTH;
    menu[0].setFont(font);
    menu[0].setColor(sf::Color::Red);
    menu[0].setString("Play");
    menu[0].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 1));

    menu[1].setFont(font);
    menu[1].setColor(sf::Color::White);
    menu[1].setString("High scores");
    menu[1].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 2));

    menu[2].setFont(font);
    menu[2].setColor(sf::Color::White);
    menu[2].setString("Exit");
    menu[2].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 3));

    menu[3].setFont(font);
    menu[3].setColor(sf::Color::White);
    menu[3].setString("Easy");
    menu[3].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 1));

    menu[4].setFont(font);
    menu[4].setColor(sf::Color::White);
    menu[4].setString("Medium");
    menu[4].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 2));

    menu[5].setFont(font);
    menu[5].setColor(sf::Color::White);
    menu[5].setString("Hard");
    menu[5].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 3));

    selectedItemIndex = 0;
}



void cmenu::draw(sf::RenderWindow &window, int start, int how_many)
{
    for (int i = start; i < start + how_many; i++)
    {
        window.draw(menu[i]);
    }
}


void cmenu::MoveUp(int range)
{
    if (selectedItemIndex - 1 >= range)
    {
        menu[selectedItemIndex].setColor(sf::Color::White);
        selectedItemIndex--;
        menu[selectedItemIndex].setColor(sf::Color::Red);
    }
}

void cmenu::MoveDown(int range)
{
    if (selectedItemIndex + 1 < range)
    {
        menu[selectedItemIndex].setColor(sf::Color::White);
        selectedItemIndex++;
        menu[selectedItemIndex].setColor(sf::Color::Red);
    }
}

void cmenu::load_highscores()
{
    int width = WINDOW_WIDTH;
    int height = WINDOW_HEIGHT;
    std::fstream file;
    std::string lane;
    file.open("high_scores.txt", std::ios::in);
    if(file.good()==true)
    {
        int i=MAX_NUMBER_OF_OPTIONS+2;
        int j=0;
        while(!file.eof() && j <10)
        {
            std::getline(file, lane);
            hs_list.push_back(lane);
            menu[i].setFont(font);
            menu[i].setColor(sf::Color::White);
            menu[i].setString(std::to_string(i-6)+". " + lane);
            menu[i].setPosition(sf::Vector2f(width / 4, height / (MAX_NUMBER_OF_Highscores + 1) * (j)));
            i++;
            j++;
        }
        menu[MAX_NUMBER_OF_OPTIONS+1].setFont(font);
        menu[MAX_NUMBER_OF_OPTIONS+1].setColor(sf::Color::Red);
        menu[MAX_NUMBER_OF_OPTIONS+1].setString("Back");
        menu[MAX_NUMBER_OF_OPTIONS+1].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_Highscores + 1) * MAX_NUMBER_OF_Highscores));
        selectedItemIndex = MAX_NUMBER_OF_OPTIONS+1;
        file.close();
    }
}

void cmenu::save_highscores(std::string player, int score)
{
    int pom = -1;
    int size = hs_list.size() - 1;
    bool space = 0;
    std::string last = "";
    for(int j = 0; j< int(hs_list[size].size()); j++)
    {
        if(hs_list[size][j] == ' ')
            space = 1;
        if(space == 1)
        {
            last.push_back(hs_list[size][j]);
        }
    }
    if(std::stoi(last) > score)
        return;

    for(int i = size; i >=0; i--)
    {
        std::string pom2;
        bool space = 0;
        for(int j = 0; j< int(hs_list[i].size()); j++)
        {
            if(hs_list[i][j] == ' ')
                space = 1;
            if(space == 1)
            {
                pom2.push_back(hs_list[i][j]);
            }
        }
        if(std::stoi(pom2) > score && i != int(hs_list.size() - 1))
            pom = i + 1;
        if(i==0 && std::stoi(pom2) < score)
            pom = 0;
    }
    for(int i = size; i >=0; i--)
    {
        if(i > pom)
        {
            hs_list[i] = hs_list[i-1];
        }
    }
    if(pom > 0)
    {
        hs_list[pom] = player + " " + std::to_string(score);
    }

    std::fstream file;
    file.open("high_scores.txt", std::ios::out);
    for(int i = 0; i < int(hs_list.size()); i++)
    {
        file<<hs_list[i]<<std::endl;
    }
    file.close();
}

std::string cmenu::get_nickname(sf::RenderWindow &window)
{
    std::string nick= "";
    bool enter = 0;
    sf::Text tekst, nickname;
    sf::Font font;
    font.loadFromFile("arial.ttf");
    tekst.setFont(font);
    nickname.setFont(font);
    tekst.setColor(sf::Color::Red);
    nickname.setColor(sf::Color::Red);
    tekst.setPosition(sf::Vector2f(WINDOW_WIDTH/10, WINDOW_HEIGHT-100));
    nickname.setPosition(sf::Vector2f(WINDOW_WIDTH/2 - 100, WINDOW_HEIGHT/2));
    tekst.setString("Type your nickname and press Enter");

    while(window.isOpen() && enter == 0)
    {
        sf::Event event;
    while(window.pollEvent(event)  && enter == 0)
    {
        switch (event.type)
        {
        case sf::Event::KeyReleased:
            switch (event.key.code)
            {
                case sf::Keyboard::Q:
                    nick.push_back('q');
                    break;
                case sf::Keyboard::W:
                    nick.push_back('w');
                    break;
                case sf::Keyboard::E:
                    nick.push_back('e');
                    break;
                case sf::Keyboard::R:
                    nick.push_back('r');
                    break;
                case sf::Keyboard::T:
                    nick.push_back('t');
                    break;
                case sf::Keyboard::Y:
                    nick.push_back('y');
                    break;
                case sf::Keyboard::U:
                    nick.push_back('u');
                    break;
                case sf::Keyboard::I:
                    nick.push_back('i');
                    break;
                case sf::Keyboard::O:
                    nick.push_back('o');
                    break;
                case sf::Keyboard::P:
                    nick.push_back('p');
                    break;
                case sf::Keyboard::A:
                    nick.push_back('a');
                    break;
                case sf::Keyboard::S:
                    nick.push_back('s');
                    break;
                case sf::Keyboard::D:
                    nick.push_back('d');
                    break;
                case sf::Keyboard::F:
                    nick.push_back('f');
                    break;
                case sf::Keyboard::G:
                    nick.push_back('g');
                    break;
                case sf::Keyboard::H:
                    nick.push_back('h');
                    break;
                case sf::Keyboard::J:
                    nick.push_back('j');
                    break;
                case sf::Keyboard::K:
                    nick.push_back('k');
                    break;
                case sf::Keyboard::L:
                    nick.push_back('l');
                    break;
                case sf::Keyboard::Z:
                    nick.push_back('z');
                    break;
                case sf::Keyboard::X:
                    nick.push_back('x');
                    break;
                case sf::Keyboard::C:
                    nick.push_back('c');
                    break;
                case sf::Keyboard::V:
                    nick.push_back('v');
                    break;
                case sf::Keyboard::B:
                    nick.push_back('b');
                    break;
                case sf::Keyboard::N:
                    nick.push_back('n');
                    break;
            case sf::Keyboard::M:
                    nick.push_back('m');
                    break;
            case sf::Keyboard::Backspace:
                nick.pop_back();
                break;
            case sf::Keyboard::Enter:
                enter = 1;
                break;
            }

        default:
            break;
        }
        }
    window.clear();
    nickname.setString(nick);
    window.draw(tekst);
    window.draw(nickname);
    window.display();
    }
    return nick;
}

void cmenu::loop()
{
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Frogger");

    cmenu cmenu;

    int start_drawing = 0;
    int min = selectedItemIndex;
    int max = MAX_NUMBER_OF_ITEMS;
    int stop_drawing = MAX_NUMBER_OF_ITEMS;
    while (window.isOpen())
    {
        sf::Event event;

        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::KeyReleased:
                switch (event.key.code)
                {
                    case sf::Keyboard::Up:
                        cmenu.MoveUp(min);
                        break;

                    case sf::Keyboard::Down:
                        cmenu.MoveDown(max);
                        break;

                    case sf::Keyboard::Enter:
                        switch (cmenu.GetPressedItem())
                    {
                        case 0:
                            start_drawing = MAX_NUMBER_OF_DIFFICULT;
                            min = min + MAX_NUMBER_OF_DIFFICULT;
                            max = max + MAX_NUMBER_OF_DIFFICULT;
                            for(int i=0; i<=MAX_NUMBER_OF_DIFFICULT; i++)
                            {
                                cmenu.MoveDown(max);
                            }
                        break;

                        case 1:
                        {
                            cmenu.load_highscores();
                            start_drawing = MAX_NUMBER_OF_OPTIONS+1;
                            stop_drawing = MAX_NUMBER_OF_OPTIONS+MAX_NUMBER_OF_Highscores;
                            min=MAX_NUMBER_OF_OPTIONS+1;
                            max=min;
                        }

                        break;

                        case 2:
                            window.close();
                        break;

                        case 3:
                        {
                          cgame game(1);
                          game.load_lanes();
                          game.loop(window);
                          load_highscores();
                          save_highscores(get_nickname(window), game.get_score());
                        }
                        break;

                        case 4:
                        {
                          cgame game(2);
                          game.load_lanes();
                          game.loop(window);
                          load_highscores();
                          save_highscores(get_nickname(window), game.get_score());
                        }
                        break;

                        case 5:
                        {
                          cgame game(3);
                          game.load_lanes();
                          game.loop(window);
                          load_highscores();                          
                          save_highscores(get_nickname(window), game.get_score());
                        }
                        break;

                        case MAX_NUMBER_OF_OPTIONS+1:
                        {
                            min = 0;
                            max = MAX_NUMBER_OF_ITEMS;
                            start_drawing = 0;
                            stop_drawing = MAX_NUMBER_OF_ITEMS;
                            for(int i=MAX_NUMBER_OF_OPTIONS+MAX_NUMBER_OF_Highscores; i>=0; i--)
                            {
                                cmenu.MoveUp(min);
                            }
                        }
                        break;
                    }

                    break;

                    case sf::Keyboard::Escape:
                    {
                        min = 0;
                        max = MAX_NUMBER_OF_ITEMS;
                        start_drawing = 0;
                        stop_drawing = MAX_NUMBER_OF_ITEMS;
                        for(int i=MAX_NUMBER_OF_OPTIONS+MAX_NUMBER_OF_Highscores; i>=0; i--)
                        {
                            cmenu.MoveUp(min);
                        }

                    }
                    break;

                }

                break;
            case sf::Event::Closed:
                window.close();

                break;

            }
        }


        window.clear();
        cmenu.draw(window, start_drawing, stop_drawing);
        window.display();

    }
}
