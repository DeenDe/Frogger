#ifndef CLOG_H
#define CLOG_H
#include "cmoving_object.h"

class clog : public cmoving_object
{
public:
    clog(int x, int y, int speed, std::string dir);
    virtual void move();
};

#endif // CLOG_H
