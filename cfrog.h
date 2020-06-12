#ifndef CFROG_H
#define CFROG_H
#include "cmoving_object.h"
#include <iostream>

#define FROG_TEXTURE_Y 30
#define FROG_TEXTURE_X 30

class cfrog : public cmoving_object
{
public:
    /**
     * @brief Konstruktor klasy cfrog
     * @param x Wspolrzedna x obiektu
     * @param y Wspolrzedna y obiektu
     * @param speed Wartosc predkosci obiektu
     */
    cfrog(int x, int y, int speed);
    /**
     * @brief Witualna funkcja do poruszania obiektami po mapie, z wykorzystaniem polimorfizmu
     */
    virtual void move();
};

#endif // CFROG_H
