#ifndef CLOG_H
#define CLOG_H
#include "cmoving_object.h"

class clog : public cmoving_object
{
public:
    clog(int x, int y, int speed, std::string dir);
    virtual void move(cmoving_object *mov, int length, int height);
};

#endif // CLOG_H
