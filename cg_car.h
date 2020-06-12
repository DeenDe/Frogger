#ifndef CG_CAR_H
#define CG_CAR_H
#include "cg_object.h"
#include "ccar.h"

class cg_car : public cg_object
{
public:
    /**
     * @brief Konstruktor klasy cg_car
     * @param car Wskaznik na obiekt, ktorego dotyczy grafika
     */
    cg_car(ccar *car);
    /**
     * @brief Wskaznik na obiekt, ktorego dotyczy grafika
     */
    ccar *car;
};

#endif // CG_CAR_H
