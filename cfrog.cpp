#include "cfrog.h"

cfrog::cfrog(int x, int y, int speed)
{
    cobject::set_x(x);
    cobject::set_y(y);
    cmoving_object::set_speed(speed);
    cmoving_object::set_direction("null");
}

void cfrog::move()
{
    int pom;
    if(cmoving_object::get_direction() == "up")
    {
        pom = cobject::get_y() - cmoving_object::get_speed();
        if(pom <= 0) pom = 0;
            cobject::set_y(pom);
    }
    if(cmoving_object::get_direction() == "down")
    {
        pom = cobject::get_y() + cmoving_object::get_speed();
        if(pom >= WINDOW_HEIGHT) pom = WINDOW_HEIGHT - FROG_TEXTURE_Y;
            cobject::set_y(pom);
    }
    if(cmoving_object::get_direction() == "left")
    {
        pom = cobject::get_x() - cmoving_object::get_speed();
        if(pom <= 0) pom = 0;
            cobject::set_x(pom);
    }
    if(cmoving_object::get_direction() == "right")
    {
        pom = cobject::get_x() + cmoving_object::get_speed();
        if(pom >= WINDOW_WIDTH) pom = WINDOW_WIDTH - FROG_TEXTURE_X;
            cobject::set_x(pom);
    }
}
