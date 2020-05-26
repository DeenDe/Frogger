#ifndef CG_CAR_H
#define CG_CAR_H
#include "cg_object.h"
#include "ccar.h"

class cg_car : public cg_object
{
public:
    cg_car(ccar *car);
    ccar *car;
};

#endif // CG_CAR_H
