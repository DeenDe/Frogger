#ifndef CLANE_H
#define CLANE_H
#include "cobject.h"

class clane : public cobject
{
public:
    /**
     * @brief Konstruktor klasy clane
     * @param x Wspolrzedna x obiektu
     * @param y Wspolrzedna y obiektu
     * @param type Rodzaj linii: trawa, woda lub ulica
     */
    clane(int x, int y, int type);
    /**
     * @brief Funkcja zwracajaca typ linii
     * @return Typ linii
     */
    int get_type();
    /**
     * @brief Funkcja kontrolujaca prawidlowe wpisywanie linii
     * @param t Typ linii
     */
    void set_type(int t);
private:
    int type; // Define type of lane: grass, water or street
};

#endif // CLANE_H
