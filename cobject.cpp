#include "cobject.h"

cobject::cobject()
{

}

void cobject::set_x(int x)
{
    if(x<=WINDOW_WIDTH && x>=0)
        this->x = x;
}

void cobject::set_y(int y)
{
    if(y<=WINDOW_HEIGHT && y>=0)
    this->y = y;
}

int cobject::get_x()
{
    return this->x;
}

int cobject::get_y()
{
    return this->y;
}

