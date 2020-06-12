#ifndef CG_OBJECT_H
#define CG_OBJECT_H
#include <SFML/Graphics.hpp>
#include "cmoving_object.h"

class cg_object //class for storing graphics for objects
{
public:
    /**
     * @brief Konstruktor klasy cg_object
     */
    cg_object();
    /**
     * @brief Funkcja rysujaca obiekt na oknie
     * @param window Okna, na ktorym rysujemy obiekt
     */
    void draw(sf::RenderWindow &window);
    /**
     * @brief Funkcja definiujaca ksztalt obiektu
     * @return Ksztalt obiektu
     */
    sf::RectangleShape load_shape();
    /**
     * @brief Funkcja aktualizujaca polozenie wyswietlanych obiektow
     * @param x Zmieniona wspolrzedna x
     * @param y Zmieniona wspolrzedna y
     */
    void update(int x, int y);

//protected:
    sf::RectangleShape shape;
};

#endif // CG_OBJECT_H
