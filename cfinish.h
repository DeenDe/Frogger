#ifndef CFINISH_H
#define CFINISH_H
#include "cobject.h"

class cfinish : public cobject
{
public:
    cfinish(int x, int y);
    bool check = 0;
    void add_extra_points();
};

#endif // CFINISH_H
