#ifndef CFROG_H
#define CFROG_H
#include "cmoving_object.h"
#include <iostream>

class cfrog : public cmoving_object
{
public:
    cfrog(int x, int y, int speed);
    virtual void move(cmoving_object *mov, int length, int height);
};

#endif // CFROG_H
