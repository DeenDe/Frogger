#include "clane.h"

clane::clane(int x, int y, int type)
{
    this->set_x(x);
    this->set_y(y);
    this->type = type;
}

int clane::get_type()
{
    return this->type;
}


