#ifndef CSNAKE_H
#define CSNAKE_H
#include "cobject.h"

class csnake : public cobject
{
public:
    csnake();
    void dissapear();
private:
    int time;
};

#endif // CSNAKE_H
