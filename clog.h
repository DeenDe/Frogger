#ifndef CLOG_H
#define CLOG_H
#include "cmoving_object.h"

class clog : public cmoving_object
{
public:
    /**
     * @brief Konstruktor klasy clog
     * @param x Wspolrzedna x obiektu
     * @param y Wspolrzedna y obiektu
     * @param speed Wartosc predkosci obiektu
     * @param dir Kierunek ruchu obiektu
     */
    clog(int x, int y, int speed, std::string dir);
    /**
     * @brief Funkcja implementujaca sposob poruszania sie klody
     */
    virtual void move();
};

#endif // CLOG_H
