#ifndef CMENU_H
#define CMENU_H
#pragma once
#include "SFML/Graphics.hpp"
#include <fstream>
#define MAX_NUMBER_OF_ITEMS 3
#define MAX_NUMBER_OF_Highscores 10
#define MAX_NUMBER_OF_OPTIONS 5
#define MAX_NUMBER_OF_DIFFICULT 3
#include "cgame.h"

class cmenu
{
public:
    cmenu(float width, float height);
    void draw(sf::RenderWindow &window, int start, int how_many);
    void draw_high_scores(sf::RenderWindow &window);
    void MoveUp(int range);
    void MoveDown(int range);
    int GetPressedItem() { return selectedItemIndex; }
    void loop();
    void load_highscores(int width, int height);

private:
    int selectedItemIndex;
    sf::Font font;
    sf::Text menu[MAX_NUMBER_OF_OPTIONS+MAX_NUMBER_OF_Highscores];
    sf::Text high_scores[MAX_NUMBER_OF_Highscores];

};

#endif // CMENU_H
