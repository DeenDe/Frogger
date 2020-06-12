#ifndef CG_FINISH_H
#define CG_FINISH_H
#include "cg_object.h"
#include "cfinish.h"

class cg_finish : public cg_object
{
public:
    /**
     * @brief Konstruktor klasy cg_finish
     * @param finish Wskaznik na obiekt, ktorego dotyczy grafika
     */
    cg_finish(cfinish * finish);
    /**
     * @brief Wskaznik na obiekt, ktorego dotyczy grafika
     */
    cfinish* finish;
};

#endif // CG_FINISH_H
