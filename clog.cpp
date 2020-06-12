#include "clog.h"

clog::clog(int x, int y, int speed, std::string dir)
{
    cobject::set_x(x);
    cobject::set_y(y);
    cmoving_object::set_speed(speed);
    cmoving_object::set_direction(dir);
}

void clog::move()
{
    int pom;
    if( cmoving_object::get_direction()=="left")
    {
        pom = cobject::get_x() - cmoving_object::get_speed();
        if(pom<0) pom = WINDOW_WIDTH;
        cobject::set_x(pom);
    }
    else
    {

        pom = cobject::get_x() + cmoving_object::get_speed();
        if(pom>WINDOW_WIDTH) pom = 0;
        cobject::set_x(pom);
    }
}
