#ifndef CFINISH_H
#define CFINISH_H
#include "cobject.h"

class cfinish : public cobject
{
public:
    cfinish();
    bool check;
    void add_extra_points();
};

#endif // CFINISH_H
