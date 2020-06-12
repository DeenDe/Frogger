#ifndef CG_LANE_H
#define CG_LANE_H
#include "cg_object.h"
#include "clane.h"

class cg_lane : public cg_object
{
public:
    cg_lane(clane *lane);
    clane *lane;
};

#endif // CG_LANE_H
