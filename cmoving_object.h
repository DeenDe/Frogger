#ifndef CMOVING_OBJECT_H
#define CMOVING_OBJECT_H
#include "cobject.h"
#include <iostream>

class cmoving_object : public cobject //base class for moving objects
{
public:
    cmoving_object();
    virtual void move(cmoving_object *mov, int length, int height) = 0; //use of polymorphizm
    int speed;
    std::string direction;
};

#endif // CMOVING_OBJECT_H
