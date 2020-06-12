#ifndef CMOVING_OBJECT_H
#define CMOVING_OBJECT_H
#include "cobject.h"
#include <iostream>


class cmoving_object : public cobject //base class for moving objects
{
public:
    /**
     * @brief Konstruktor klasy cmoving_object
     */
    cmoving_object();
    /**
     * @brief Funkcja ustawiajaca predkosc obiektu
     */
    void set_speed(int speed);
    /**
     * @brief Funkcja ustawiajaca kierunek ruchu obiektu
     */
    void set_direction(std::string dir);
    /**
     * @brief Funkcja zwracajaca predkosc obiektu
     * @return Predkosc obiektu
     */
    int get_speed();
    /**
     * @brief Funkcja zwracajaca kierunek ruchu obiektu
     * @return Kierunek ruchu obiektu
     */
    std::string get_direction();
    /**
     * @brief Witualna funkcja do poruszania obiektami po mapie, z wykorzystaniem polimorfizmu
     */
    virtual void move() = 0; //use of polymorphizm

private:
    int speed;
    std::string direction;
};

#endif // CMOVING_OBJECT_H
