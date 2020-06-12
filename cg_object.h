#ifndef CG_OBJECT_H
#define CG_OBJECT_H
#include <SFML/Graphics.hpp>
#include "cmoving_object.h"

class cg_object //class for storing graphics for objects
{
public:
    cg_object();
    void draw(sf::RenderWindow &window);
    sf::RectangleShape load_shape();
    void update(int x, int y);

//protected:
    sf::RectangleShape shape;
};

#endif // CG_OBJECT_H
