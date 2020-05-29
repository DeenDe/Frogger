#include "cgame.h"


cgame::cgame(int difficult)
{

}

void cgame::add_object(int difficult)
{

}

void cgame::load_lanes(int difficult, int height)
{
    int cars_per_lane = (MIN_NUM_OF_CARS*difficult)/MIN_NUM_OF_LANES;
    int logs_per_lane = MIN_NUM_OF_LOGS/MIN_NUM_OF_WATER;
    int height_per_lane = height/(MIN_NUM_OF_LANES+MIN_NUM_OF_WATER+2);

    cfrog *frog = new cfrog(100, height - height_per_lane + ((height_per_lane - FROG_TEXTURE_Y)/2), height_per_lane);
    mov_list.push_back(frog); //frog always have index "0"
    cg_frog *gfrog = new cg_frog(frog);
    gmov_list.push_back(gfrog);

    for(int i=0; i<(MIN_NUM_OF_LANES+MIN_NUM_OF_WATER)*difficult+2; i++)
    {        
        clane *lane = new clane(0, height_per_lane*i);
        cg_lane *w_glane = new cg_lane(lane);
        glane_list.push_back(w_glane);

        if(i == 0)
        {
            w_glane->shape.setFillColor(sf::Color::Blue);
            cfinish *finish1 = new cfinish(50,0);
            lane_list.push_back(finish1);
            cg_finish *gfinish1 = new cg_finish(finish1);
            glane_list.push_back(gfinish1);
            cfinish *finish2 = new cfinish(200,0);
            lane_list.push_back(finish2);
            cg_finish *gfinish2 = new cg_finish(finish2);
            glane_list.push_back(gfinish2);
            cfinish *finish3 = new cfinish(350,0);
            lane_list.push_back(finish3);
            cg_finish *gfinish3 = new cg_finish(finish3);
            glane_list.push_back(gfinish3);
            cfinish *finish4 = new cfinish(500,0);
            lane_list.push_back(finish4);
            cg_finish *gfinish4 = new cg_finish(finish4);
            glane_list.push_back(gfinish4);
        }

        lane_list.push_back(lane);

        if(i<MIN_NUM_OF_WATER && i != 0)
        {
            int dirrection = std::rand()%2;
            std::string dir;
            if(dirrection == 0) dir = "left";
            if(dirrection == 1) dir = "right";
            int speed = std::rand()%15+5;
            w_glane->shape.setFillColor(sf::Color::Blue);
            int dist = std::rand()%250;

            for(int j = 0; j<= logs_per_lane; j++)
            {                
                clog *log = new clog(j*90 + dist, height_per_lane*i+((height_per_lane-LOG_TEXTURE_Y)/2), speed, dir);
                mov_list.push_back(log);
                dist = std::rand()%200 + log->x;
                if(dist > height) dist = 0;
                cg_log *glog = new cg_log(log);
                gmov_list.push_back(glog);
            }
        }

        if(i == MIN_NUM_OF_WATER)
        {
            w_glane->shape.setFillColor(sf::Color::Green);
        }

        if(i>(MIN_NUM_OF_WATER)&&i!=(MIN_NUM_OF_LANES+MIN_NUM_OF_WATER)*difficult+1)
        {
            int dirrection = std::rand()%2;
            std::string dir;
            if(dirrection == 0) dir = "left";
            if(dirrection == 1) dir = "right";
            int speed = std::rand()%15+5;
            w_glane->shape.setFillColor(sf::Color::Black);
            int dist = std::rand()%250;

            for(int j = 0; j<= cars_per_lane; j++)
            {

                ccar *car = new ccar(50*j + dist, height_per_lane*i+((height_per_lane-CAR_TEXTURE_Y)/2), speed, dir);
                mov_list.push_back(car);
                dist = std::rand()%300 + car->x;
                if(dist > height) dist = 0;
                cg_car *gcar = new cg_car(car);
                gmov_list.push_back(gcar);

            }
        }

        if(i==(MIN_NUM_OF_LANES+MIN_NUM_OF_WATER)*difficult+1)
        {
            w_glane->shape.setFillColor(sf::Color::Green);
        }

    }

}

bool cgame::check_collision(cmoving_object * obj1, cobject *obj2, int width)
{

    int frog_left = obj1->x;
    int frog_right = obj1->x + 30;
    int frog_up = obj1->y;
    int frog_down = obj1->y + 30;


    int obj_left = obj2->x;
    int obj_right = obj2->x + width;
    int obj_up = obj2->y;
    int obj_down = obj2->y + 30;

    if (frog_left < obj_right && frog_right > obj_left && frog_up < obj_down && frog_down > obj_up) return true;

    else return false;
}


void cgame::loop(sf::RenderWindow &window)
{

    int height = window.getSize().y;
    int height_per_lane = height/(MIN_NUM_OF_LANES+MIN_NUM_OF_WATER+2);
    window.setFramerateLimit(60);

    while(window.isOpen())
    {
        sf::Event event;
        std::string dir= "null";        
        while(window.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::KeyReleased:
                switch (event.key.code)
                {
                    case sf::Keyboard::Up:
                        dir = "up";
                        break;

                    case sf::Keyboard::Down:
                        dir = "down";
                        break;

                    case sf::Keyboard::Left:
                        dir = "left";
                        break;

                    case sf::Keyboard::Right:
                        dir = "right";
                        break;
                    case sf::Keyboard::Escape:
                        window.close();
                        break;
                }

            default:
                break;
            }
            }

            window.clear();

            int i = 0;
            bool frog_on_log = 0;
            for (const auto p : mov_list)
            {
                if(check_collision(mov_list[0], p, CAR_TEXTURE_X) && p->direction!= "null" && mov_list[0]->y > height_per_lane*MIN_NUM_OF_WATER)
                {
                    mov_list[0]->x = window.getSize().x/2;
                    mov_list[0]->y = height - height_per_lane + ((height_per_lane - FROG_TEXTURE_Y)/2);
                    mov_list[0]->move(mov_list[0], window.getSize().x/2, height - height_per_lane + ((height_per_lane - FROG_TEXTURE_Y)/2));
                    gmov_list[0]->update(gmov_list[0], p->x, p->y);

                }

                if(check_collision(mov_list[0], p, LOG_TEXTURE_X) && p->direction!= "null" && mov_list[0]->y <= height_per_lane*MIN_NUM_OF_WATER)
                {
                    if(p->direction == "left") mov_list[0]->x -= p->speed;
                    else mov_list[0]->x += p->speed;
                    gmov_list[0]->update(gmov_list[0], p->x, p->y);
                    frog_on_log = 1;
                }


                i++;
            }
            for(int i = 0; i<4; i++)
            {
                if(check_collision(mov_list[0], lane_list[i], FINISH_TEXTURE_X))
                {
                   this->score += 50;
                   mov_list[0]->x = window.getSize().x/2;
                   mov_list[0]->y = height - height_per_lane + ((height_per_lane - FROG_TEXTURE_Y)/2);
                   mov_list[0]->move(mov_list[0], window.getSize().x/2, height - height_per_lane + ((height_per_lane - FROG_TEXTURE_Y)/2));
                   gmov_list[0]->update(gmov_list[0], mov_list[0]->x, mov_list[0]->y);
                }
            }

            if(frog_on_log == 0 && mov_list[0]->y <= height_per_lane*MIN_NUM_OF_WATER)
           {
                mov_list[0]->x = window.getSize().x/2;
                mov_list[0]->y = height - height_per_lane + ((height_per_lane - FROG_TEXTURE_Y)/2);
                gmov_list[0]->update(gmov_list[0], mov_list[0]->x, mov_list[0]->y);
            }

            i = 0;

            for(const auto p : mov_list)
            {
                p->move(p, window.getSize().y, window.getSize().x);
                if(dir!="null" && p->direction=="null")
                {
                    p->direction = dir;
                    p->move(p, window.getSize().y, window.getSize().x);
                    p->direction = "null";
                    dir = "null";
                }
                gmov_list[i]->update(gmov_list[i], p->x, p->y);
                i++;
            }

            for(int j = 0; j < int(glane_list.size()) ; j++)
            {
                glane_list[j]->draw(window);
            }

            for(int j = int(gmov_list.size()) - 1; j >= 0 ; j--)
            {
                gmov_list[j]->draw(window);
            }            
            window.display();
            sf::sleep(sf::milliseconds(100));

    }
}
