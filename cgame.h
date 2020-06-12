#ifndef CGAME_H
#define CGAME_H
#include <SFML/Graphics.hpp>
#include "cmenu.h"
#include "cobject.h"
#include "clog.h"
#include "clane.h"
#include "cmoving_object.h"
#include "ccar.h"
#include "cfrog.h"
#include "cfinish.h"
#include "cg_lane.h"
#include "cg_car.h"
#include "cg_log.h"
#include "cg_frog.h"
#include "cg_finish.h"
#include<iostream>

#define MIN_NUM_OF_CARS 5
#define MIN_NUM_OF_LOGS 10
#define MIN_NUM_OF_LANES 5
#define MIN_NUM_OF_WATER 5

#define FROG_TEXTURE_Y 30
#define FROG_TEXTURE_X 30
#define CAR_TEXTURE_Y 30
#define CAR_TEXTURE_X 30
#define LOG_TEXTURE_Y 30
#define LOG_TEXTURE_X 80
#define FINISH_TEXTURE_X 30
#define FINISH_TEXTURE_Y 30

class cgame //manage all objects and keeps going all game
{
public:
    /**
     * @brief Konstruktor klasy cgame
     * @param difficult Poziom trudności gry
     */
    cgame(int difficult);
    /**
     * @brief Funkcja odpwiedzialna za ciagla prace gry
     * @param window Okno, na ktorym wyswietlamy gre
     */
    void loop(sf::RenderWindow &window); //function that's keeping game going
    /**
     * @brief Inicjacja poczatkowa wszystkich obiektow na mapie
     */
    void load_lanes(); //initialise all lanes and starting objects
    /**
     * @brief Funkcja sprawdzajaca kolizje miedzy dwoma obiektami
     * @param obj1 Pierwszy obiekt
     * @param obj2 Drugi obiekt
     * @param width Szerokosc obiektu drugiego
     * @return Prawda jesli wykryto kolizje miedzy obiektami
     */
    bool check_collision(cmoving_object *obj1, cobject *obj2, int width); //detecting collision between two objects
    /**
     * @brief Funkcja zwracajaca wynik
     * @return Wynik gracza
     */
    int get_score();
    /**
     * @brief Funkcja zwiekszajaca wynik gracza
     * @param dod Wartosc dodawana do aktualnej liczby punktow
     */
    void add_score(int dod);
    /**
     * @brief Funkcja usuwajaca vector linii i obiektow nieruchomych
     */
    void del_lane_list();
    /**
     * @brief Funkcja usuwajaca vector grafik linii i obiektow nieruchomych
     */
    void del_glane_list();
    /**
     * @brief Funkcja usuwajaca vector obiektow ruchomych
     */
    void del_mov_list();
    /**
     * @brief Funkcja usuwajaca vector grafik obiektow ruchomych
     */
    void del_gmov_list();

private:
    int score = 0;
    int difficult;
    int number_of_water;
    int number_of_streets;
    std::vector <cobject*> lane_list; //list of all lines
    std::vector <cg_object*> glane_list; //list of graphics for lines
    std::vector <cmoving_object*> mov_list; //list of all moving objects
    std::vector <cg_object*> gmov_list; //list of graphics for all objects
};

#endif // CGAME_H
