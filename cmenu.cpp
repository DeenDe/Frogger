#include "cmenu.h"

cmenu::cmenu(float width, float height)
{
    if (!font.loadFromFile("arial.ttf"))
    {
        // handle error
    }

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

void cmenu::draw_high_scores(sf::RenderWindow &window)
{
    for (int i = 0; i < MAX_NUMBER_OF_Highscores; i++)
    {
        window.draw(high_scores[i]);
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

void cmenu::load_highscores(int width, int height)
{
    std::fstream file;
    std::string lane;
    file.open("high_scores.txt", std::ios::in);
    if(file.good()==true)
    {
        int i=MAX_NUMBER_OF_OPTIONS+2;
        int j=0;
        while(!file.eof())
        {
            std::getline(file, lane);
            menu[i].setFont(font);
            menu[i].setColor(sf::Color::White);
            menu[i].setString(lane);
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

void cmenu::loop()
{
    sf::RenderWindow window(sf::VideoMode(600, 600), "Frogger");

    cmenu cmenu(window.getSize().x, window.getSize().y);

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
                            cmenu.load_highscores(window.getSize().x, window.getSize().y);
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
                          game.load_lanes(1,window.getSize().y);
                          game.loop(window);
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
