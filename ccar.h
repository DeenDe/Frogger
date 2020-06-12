#ifndef CCAR_H
#define CCAR_H
#include "cmoving_object.h"
#include <iostream>

class ccar : public cmoving_object
{
public:
    /**
     * @brief Konstrukto klasy ccar
     * @param x Wspolrzedna x obiektu
     * @param y Wspolrzedna y obiektu
     * @param speed Wartosc predkosci obiektu
     * @param dir Kierunek ruchu obiektu
     */
    ccar(int x, int y, int speed, std::string dir);
    /**
     * @brief Funkcja implementujaca sposob poruszania sie samochodu
     */
    virtual void move();
private:
    int size;
};


#endif // CCAR_H
