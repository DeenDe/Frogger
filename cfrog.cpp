#include "cfrog.h"

cfrog::cfrog(int x, int y, int speed)
{
    this->x = x;
    this->y = y;
    this->speed = speed;
    this->direction = "null";
}

void cfrog::move(cmoving_object *mov, int length, int height)
{
    if(mov->direction == "up")
    {
        mov->y -= mov->speed;
        if(mov->y <= 0) mov->y = 0;
    }
    if(mov->direction == "down")
    {
        mov->y += mov->speed;
        if(mov->y >= height) mov->y = height;
    }
    if(mov->direction == "left")
    {
        mov->x -= mov->speed;
        if(mov->x <= 0) mov->x = 0;
    }
    if(mov->direction == "right")
    {
        mov->x += mov->speed;
        if(mov->x >= length) mov->x = length;
    }
}
