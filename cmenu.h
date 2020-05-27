#ifndef CMENU_H
#define CMENU_H
#pragma once
#include "SFML/Graphics.hpp"
#include <fstream>
#include "cgame.h"
#define MAX_NUMBER_OF_ITEMS 3
#define MAX_NUMBER_OF_Highscores 10
#define MAX_NUMBER_OF_OPTIONS 5
#define MAX_NUMBER_OF_DIFFICULT 3

class cmenu
{
public:
    cmenu(float width, float height);
    void draw(sf::RenderWindow &window, int start, int how_many); //drawing available menu options
    void draw_high_scores(sf::RenderWindow &window); //draw high scores from file
    void MoveUp(int range); // move up chosed option
    void MoveDown(int range); //move down chosed option
    int GetPressedItem() { return selectedItemIndex; } //returns selected option ID
    void loop(); //keeps menu running
    void load_highscores(int width, int height); //loading high scores from file

private:
    int selectedItemIndex;
    sf::Font font;
    sf::Text menu[MAX_NUMBER_OF_OPTIONS+MAX_NUMBER_OF_Highscores];
    sf::Text high_scores[MAX_NUMBER_OF_Highscores];

};

#endif // CMENU_H
