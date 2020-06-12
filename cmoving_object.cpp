#include "cmoving_object.h"

cmoving_object::cmoving_object()
{

}

void cmoving_object::set_speed(int speed)
{
    if(speed>0 && speed <100)
        this->speed = speed;
}

void cmoving_object::set_direction(std::string dir)
{
    if(dir=="null"||dir=="left"||dir=="right"||dir=="up"||dir=="down")
        this->direction = dir;
}

int cmoving_object::get_speed()
{
    return  this->speed;
}

std::string cmoving_object::get_direction()
{
    return this->direction;
}
