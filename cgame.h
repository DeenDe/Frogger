#ifndef CGAME_H
#define CGAME_H
#include <SFML/Graphics.hpp>
#include "cmenu.h"
#include "cobject.h"
#include "clog.h"
#include "clane.h"
#include "cmoving_object.h"
#include "ccar.h"
#include "cfrog.h"
#include "cg_lane.h"
#include "cg_car.h"
#include "cg_log.h"
#include "cg_frog.h"
#include<iostream>

#define MIN_NUM_OF_CARS 10
#define MIN_NUM_OF_LOGS 10
#define MIN_NUM_OF_LANES 5
#define MIN_NUM_OF_WATER 5

#define FROG_TEXTURE_Y 30
#define FROG_TEXTURE_X 30
#define CAR_TEXTURE_Y 30
#define CAR_TEXTURE_X 30
#define LOG_TEXTURE_Y 30
#define LOG_TEXTURE_X 80

class cgame //manage all objects and keeps going all game
{
public:
    cgame(int difficult);
    void loop(sf::RenderWindow &window); //function that's keeping game going
    void load_lanes(int difficult, int length); //initialise all lanes and starting objects
    void game_over(); //end player attempt
    bool check_collision(cmoving_object *obj1, cmoving_object *obj2, int width); //detecting collision between two objects
    void add_object(int difficult);


private:
    int number_of_water;
    int number_of_streets;
    std::vector <clane*> lane_list; //list of all lines
    std::vector <cg_object*> glane_list; //list of graphics for lines
    std::vector <cmoving_object*> mov_list; //list of all moving objects
    std::vector <cg_object*> gmov_list; //list of graphics for all objects
};

#endif // CGAME_H
