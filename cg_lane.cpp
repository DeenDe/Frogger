#include "cg_lane.h"

cg_lane::cg_lane(clane *lane)
{
    sf::RectangleShape shape;
    shape.setSize(sf::Vector2f(600, 600));
    shape.setFillColor(sf::Color::Red);
    shape.setPosition(sf::Vector2f(lane->x,lane->y));
    this->shape = shape;
    this->lane = lane;
}



