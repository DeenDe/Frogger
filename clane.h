#ifndef CLANE_H
#define CLANE_H
#include "cobject.h"

class clane : public cobject
{
public:
    clane(int x, int y);
    int id;
    bool spawn_crocodyle(int time);
};

#endif // CLANE_H
