#include "clog.h"

clog::clog(int x, int y, int speed, std::string dir)
{
    this->x = x;
    this->y = y;
    this->speed = speed;
    this->direction = dir;
}

void clog::move(cmoving_object *mov, int length, int height)
{
    if( mov->direction=="left")
    {
        mov->x -= mov->speed;
        if(mov->x<0) mov->x = length;
    }
    else
    {
        mov->x += mov->speed;
        if(mov->x>length) mov->x=0;
    }
}
