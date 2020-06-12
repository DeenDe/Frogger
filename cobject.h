#ifndef COBJECT_H
#define COBJECT_H

#define WINDOW_HEIGHT 600
#define WINDOW_WIDTH 600

class cobject // base abstract class for objects
{
public:
    /**
     * @brief Konstruktor klasy cobject
     */
    cobject();
    /**
     * @brief Funkcja zwracajaca wspolrzedna x obiektu
     * @return Wspolrzedna x obiektu
     */
    int get_x();
    /**
     * @brief Funkcja zwracajaca wspolrzedna y obiektu
     * @return Wspolrzedna y obiektu
     */
    int get_y();
    /**
     * @brief Funkcja zmieniajaca wartosc wspolrzednej x
     * @param x Wartosc wspolrzednej x, na ktora chcemy zmienic obecna wartosc
     */
    void set_x(int x);
    /**
     * @brief Funkcja zmieniajaca wartosc wspolrzednej y
     * @param y Wartosc wspolrzednej y, na ktora chcemy zmienic obecna wartosc
     */
    void set_y(int y);

private:
    int x;
    int y;
};

#endif // COBJECT_H
