#ifndef CG_LOG_H
#define CG_LOG_H
#include "cg_object.h"
#include "clog.h"

class cg_log : public cg_object
{
public:
    /**
     * @brief Konstruktor klasy cg_log
     * @param Wskaznik na obiekt, ktorego dotyczy grafika
     */
    cg_log(clog* log);
    /**
     * @brief Wskaznik na obiekt, ktorego dotyczy grafika
     */
    clog* log;
};


#endif // CG_LOG_H
