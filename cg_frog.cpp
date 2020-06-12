#include "cg_frog.h"

cg_frog::cg_frog(cfrog *frog)
{
    sf::RectangleShape shape;
    shape.setSize(sf::Vector2f(30, 30));
    shape.setFillColor(sf::Color::Magenta);
    shape.setPosition(sf::Vector2f(frog->get_x(), frog->get_y()));
    this->shape = shape;
    this->frog = frog;
}
