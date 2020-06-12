#include "cg_lane.h"

cg_lane::cg_lane(clane *lane)
{
    sf::RectangleShape shape;
    shape.setSize(sf::Vector2f(600, 600));
    if(lane->get_type()==0)
        shape.setFillColor(sf::Color::Green);
    if(lane->get_type()==1)
        shape.setFillColor(sf::Color::Blue);
    if(lane->get_type()==2)
        shape.setFillColor(sf::Color::Black);
    shape.setPosition(sf::Vector2f(lane->get_x(), lane->get_y()));
    this->shape = shape;
    this->lane = lane;
}



