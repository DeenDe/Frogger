#include "cg_log.h"

cg_log::cg_log(clog* log)
{
    sf::RectangleShape shape;
    shape.setSize(sf::Vector2f(80, 30));
    shape.setFillColor(sf::Color::Yellow);
    shape.setPosition(sf::Vector2f(log->get_x(), log->get_y()));
    this->shape = shape;
    this->log = log;
}
