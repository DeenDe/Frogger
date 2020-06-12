#include "clane.h"

clane::clane(int x, int y, int type)
{
    this->set_x(x);
    this->set_y(y);
    set_type(type);
}

int clane::get_type()
{
    return this->type;
}

void clane::set_type(int t)
{
    if(t == 0 || t == 1 || t == 2)
        this->type = t;
}


