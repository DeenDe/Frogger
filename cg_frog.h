#ifndef CG_FROG_H
#define CG_FROG_H
#include "cg_object.h"
#include "cfrog.h"

class cg_frog : public cg_object
{
public:
    /**
     * @brief Konstruktor klasy cg_frog
     * @param frog Wskaznik na obiekt, ktorego dotyczy grafika
     */
    cg_frog(cfrog *frog);
    /**
     * @brief Wskaznik na obiekt, ktorego dotyczy grafika
     */
    cfrog *frog;
};

#endif // CG_FROG_H
