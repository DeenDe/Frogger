#include "cg_finish.h"

cg_finish::cg_finish(cfinish *finish)
{
    sf::RectangleShape shape;
    shape.setSize(sf::Vector2f(30, 30));
    shape.setFillColor(sf::Color::Green);
    shape.setPosition(sf::Vector2f(finish->get_x(), finish->get_y()));
    this->shape = shape;
    this->finish = finish;
}
