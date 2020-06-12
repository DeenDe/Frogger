#include "cg_object.h"

cg_object::cg_object()
{

}

void cg_object::draw(sf::RenderWindow &window)
{
    window.draw(shape);
}

sf::RectangleShape cg_object::load_shape()
{
    return shape;
}

void cg_object::update(int x, int y)
{

    this->shape.move(x-shape.getPosition().x, y - shape.getPosition().y);

}
