#ifndef CG_LOG_H
#define CG_LOG_H
#include "cg_object.h"
#include "clog.h"

class cg_log : public cg_object
{
public:
    cg_log(clog* log);
    clog* log;
};


#endif // CG_LOG_H
