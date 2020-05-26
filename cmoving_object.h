#ifndef CMOVING_OBJECT_H
#define CMOVING_OBJECT_H
#include "cobject.h"
#include <iostream>

class cmoving_object : public cobject
{
public:
    cmoving_object();
    virtual void move(cmoving_object *mov, int length, int height) = 0;
    int speed;
    std::string direction;
};

#endif // CMOVING_OBJECT_H
