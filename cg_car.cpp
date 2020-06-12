#include "cg_car.h"

cg_car::cg_car(ccar *car)
{
    sf::RectangleShape shape;
    shape.setSize(sf::Vector2f(30, 30));
    shape.setFillColor(sf::Color::Cyan);
    shape.setPosition(sf::Vector2f(car->get_x(), car->get_y()));
    this->shape = shape;
    this->car = car;
}
