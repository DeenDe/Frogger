#ifndef CG_LANE_H
#define CG_LANE_H
#include "cg_object.h"
#include "clane.h"

class cg_lane : public cg_object
{
public:
    /**
     * @brief Konstruktor klasy cg_lane
     * @param lane Wskaznik na obiekt, ktorego dotyczy grafika
     */
    cg_lane(clane *lane);
    /**
     * @brief Wskaznik na obiekt, ktorego dotyczy grafika
     */
    clane *lane;
};

#endif // CG_LANE_H
