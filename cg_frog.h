#ifndef CG_FROG_H
#define CG_FROG_H
#include "cg_object.h"
#include "cfrog.h"

class cg_frog : public cg_object
{
public:
    cg_frog(cfrog *frog);
    cfrog *frog;
};

#endif // CG_FROG_H
