#ifndef CLANE_H
#define CLANE_H
#include "cobject.h"

class clane : public cobject
{
public:
    clane(int x, int y, int type);
    bool spawn_crocodyle(int time);
    int get_type();
private:
    int type; // Define type of lane: grass, water or street
};

#endif // CLANE_H
