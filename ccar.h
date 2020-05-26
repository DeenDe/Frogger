#ifndef CCAR_H
#define CCAR_H
#include "cmoving_object.h"
#include <iostream>

class ccar : public cmoving_object
{
public:
    ccar(int x, int y, int speed, std::string dir);
    virtual void move(cmoving_object *mov, int length, int height);
private:
    int size;
};


#endif // CCAR_H
