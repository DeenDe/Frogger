#ifndef CG_FINISH_H
#define CG_FINISH_H
#include "cg_object.h"
#include "cfinish.h"

class cg_finish : public cg_object
{
public:
    cg_finish(cfinish * finish);
    cfinish* finish;
};

#endif // CG_FINISH_H
