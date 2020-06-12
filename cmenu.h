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
#define WINDOW_HEIGHT 600
#define WINDOW_WIDTH 600

class cmenu
{
public:
    /**
     * @brief Konstruktor klasy cmenu
     */
    cmenu();
    /**
     * @brief Funkcja wyswietlajaca dostepne opcje w menu
     * @param window Okno, na ktorym wyswietlamy menu
     * @param start Indeks, od ktorego wyswietlamy opcje
     * @param how_many Ile opcji wyswietlamy na menu
     */
    void draw(sf::RenderWindow &window, int start, int how_many); //drawing available menu options
    /**
     * @brief Zmienia wybrana opcje z menu o 1 w gore
     * @param range Odpowiada za gorna granice wyswietlanych opcji
     */
    void MoveUp(int range); // move up chosed option
    /**
     * @brief Zmienia wybrana opcje z menu o 1 w dol
     * @param range Odpowiada za dolna granice wyswietlanych opcji
     */
    void MoveDown(int range); //move down chosed option
    /**
     * @brief Funkcja zwracajaca wybrana opcje z menu
     * @return Indeks wybranej opcji z menu
     */
    int GetPressedItem() { return selectedItemIndex; } //returns selected option ID
    /**
     * @brief Funkcja odpowiedzialna za ciagla prace menu
     */
    void loop(); //keeps menu running
    /**
     * @brief Funkcja wyswietlajaca oraz odczytujaca z pliku najlepsze wyniki graczy
     */
    void load_highscores(); //loading high scores from file
    /**
     * @brief save_highscores
     * @param player
     * @param score
     */
    void save_highscores(std::string player, int score);
    /**
     * @brief get_nickname
     * @param window
     * @return
     */
    std::string get_nickname(sf::RenderWindow &window);

private:
    int selectedItemIndex;
    sf::Font font;
    /**
     * @brief Tablica zawierajaca wszystkie wyswietlane opcje oraz najlepsze wyniki
     */
    sf::Text menu[MAX_NUMBER_OF_OPTIONS+MAX_NUMBER_OF_Highscores];
    /**
     * @brief high_scores
     */
    sf::Text high_scores[MAX_NUMBER_OF_Highscores];
    std::vector<std::string>hs_list;

};

#endif // CMENU_H
