#include "cgame.h"


cgame::cgame(int difficult)
{
    this->difficult = difficult;
}

void cgame::add_score(int dod)
{
    if(dod > 0) this->score += dod;
}

int cgame::get_score()
{
    return  this->score;
}

void cgame::del_mov_list()
{
    for (int i = this->mov_list.size() - 1; i>=0 ;i--)
    {
        delete mov_list[i];
        mov_list.pop_back();
    }
}

void cgame::del_gmov_list()
{
    for (int i = this->gmov_list.size() - 1; i>=0 ;i--)
    {
        delete gmov_list[i];
        gmov_list.pop_back();
    }
}

void cgame::del_lane_list()
{
    for (int i = this->lane_list.size() - 1; i>=0 ;i--)
    {
        delete lane_list[i];
        lane_list.pop_back();
    }
}

void cgame::del_glane_list()
{
    for (int i = this->glane_list.size() - 1; i>=0 ;i--)
    {
        delete glane_list[i];
        glane_list.pop_back();
    }
}

void cgame::load_lanes()
{
    int cars_per_lane = (MIN_NUM_OF_CARS*difficult)/MIN_NUM_OF_LANES;
    int logs_per_lane = MIN_NUM_OF_LOGS/MIN_NUM_OF_WATER;
    int height_per_lane = WINDOW_HEIGHT/(MIN_NUM_OF_LANES+MIN_NUM_OF_WATER+2);

    cfrog *frog = new cfrog(100, WINDOW_HEIGHT - height_per_lane + ((height_per_lane - FROG_TEXTURE_Y)/2), height_per_lane);
    mov_list.push_back(frog); //frog always have index "0"
    cg_frog *gfrog = new cg_frog(frog);
    gmov_list.push_back(gfrog);

    for(int i=0; i<(MIN_NUM_OF_LANES+MIN_NUM_OF_WATER)+2; i++)
    {        


        if(i == 0)
        {
            clane *lane = new clane(0, height_per_lane*i, 1);
            cg_lane *w_glane = new cg_lane(lane);
            glane_list.push_back(w_glane);
            cfinish *finish1 = new cfinish(WINDOW_WIDTH/12, FINISH_TEXTURE_Y/2);
            lane_list.push_back(finish1);
            cg_finish *gfinish1 = new cg_finish(finish1);
            glane_list.push_back(gfinish1);
            cfinish *finish2 = new cfinish((WINDOW_WIDTH/12)*4, FINISH_TEXTURE_Y/2);
            lane_list.push_back(finish2);
            cg_finish *gfinish2 = new cg_finish(finish2);
            glane_list.push_back(gfinish2);
            cfinish *finish3 = new cfinish((WINDOW_WIDTH/12)*7, FINISH_TEXTURE_Y/2);
            lane_list.push_back(finish3);
            cg_finish *gfinish3 = new cg_finish(finish3);
            glane_list.push_back(gfinish3);
            cfinish *finish4 = new cfinish((WINDOW_WIDTH/12)*10, FINISH_TEXTURE_Y/2);
            lane_list.push_back(finish4);
            cg_finish *gfinish4 = new cg_finish(finish4);
            glane_list.push_back(gfinish4);
            lane_list.push_back(lane);
        }



        if(i<MIN_NUM_OF_WATER && i != 0)
        {
            clane *lane = new clane(0, height_per_lane*i, 1);
            cg_lane *w_glane = new cg_lane(lane);
            glane_list.push_back(w_glane);
            int dirrection = std::rand()%2;
            std::string dir;
            if(dirrection == 0) dir = "left";
            if(dirrection == 1) dir = "right";
            int speed = std::rand()%15+5;            
            int dist = std::rand()%250;
            lane_list.push_back(lane);

            for(int j = 0; j<= logs_per_lane; j++)
            {                
                clog *log = new clog(j*90 + dist, height_per_lane*i+((height_per_lane-LOG_TEXTURE_Y)/2), speed, dir);
                mov_list.push_back(log);
                dist = std::rand()%200 + log->get_x();
                if(dist > WINDOW_HEIGHT) dist = 0;
                cg_log *glog = new cg_log(log);
                gmov_list.push_back(glog);
            }
        }

        if(i == MIN_NUM_OF_WATER)
        {
            clane *lane = new clane(0, height_per_lane*i, 0);
            cg_lane *w_glane = new cg_lane(lane);
            glane_list.push_back(w_glane);
        }

        if(i>(MIN_NUM_OF_WATER)&&i!=(MIN_NUM_OF_LANES+MIN_NUM_OF_WATER)+1)
        {
            clane *lane = new clane(0, height_per_lane*i, 2);
            cg_lane *w_glane = new cg_lane(lane);
            glane_list.push_back(w_glane);
            int dirrection = std::rand()%2;
            std::string dir;
            if(dirrection == 0) dir = "left";
            if(dirrection == 1) dir = "right";
            int speed = std::rand()%15+5;
            int dist = std::rand()%250;
            lane_list.push_back(lane);

            for(int j = 0; j<= cars_per_lane; j++)
            {

                ccar *car = new ccar(50*j + dist, height_per_lane*i+((height_per_lane-CAR_TEXTURE_Y)/2), speed, dir);
                mov_list.push_back(car);
                dist = std::rand()%300 + car->get_x();
                if(dist > WINDOW_HEIGHT) dist = 0;
                cg_car *gcar = new cg_car(car);
                gmov_list.push_back(gcar);

            }
        }

        if(i==(MIN_NUM_OF_LANES+MIN_NUM_OF_WATER)+1)
        {
            clane *lane = new clane(0, height_per_lane*i, 0);
            cg_lane *w_glane = new cg_lane(lane);
            glane_list.push_back(w_glane);
            lane_list.push_back(lane);
        }

    }

}

bool cgame::check_collision(cmoving_object * obj1, cobject *obj2, int width)
{

    int frog_left = obj1->get_x();
    int frog_right = obj1->get_x() + FROG_TEXTURE_X;
    int frog_up = obj1->get_y();
    int frog_down = obj1->get_y() + FROG_TEXTURE_Y;

    int obj_left = obj2->get_x();
    int obj_right = obj2->get_x() + width;
    int obj_up = obj2->get_y();
    int obj_down = obj2->get_y() + CAR_TEXTURE_Y;

    if (frog_left < obj_right && frog_right > obj_left && frog_up < obj_down && frog_down > obj_up) return true;

    else return false;
}


void cgame::loop(sf::RenderWindow &window)
{
    int height = window.getSize().y;
    int height_per_lane = height/(MIN_NUM_OF_LANES+MIN_NUM_OF_WATER+2);
    window.setFramerateLimit(60);
    int lives = 3;

    sf::Text tekst, score;
    sf::Font font;
    font.loadFromFile("arial.ttf");
    tekst.setFont(font);
    score.setFont(font);
    tekst.setColor(sf::Color::Red);
    score.setColor(sf::Color::Red);
    tekst.setPosition(sf::Vector2f(0,0));
    score.setPosition(sf::Vector2f(WINDOW_WIDTH-50,0));

    while(window.isOpen() && lives !=0)
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
                if(check_collision(mov_list[0], p, CAR_TEXTURE_X) && p->get_direction()!= "null" && mov_list[0]->get_y() > height_per_lane*MIN_NUM_OF_WATER)
                {
                    mov_list[0]->set_x(window.getSize().x/2);
                    mov_list[0]->set_y(height - height_per_lane + ((height_per_lane - FROG_TEXTURE_Y)/2));
                    mov_list[0]->move();
                    gmov_list[0]->update(p->get_x(), p->get_y());
                    lives -= 1;

                }

                if(check_collision(mov_list[0], p, LOG_TEXTURE_X) && p->get_direction()!= "null" && mov_list[0]->get_y() <= height_per_lane*MIN_NUM_OF_WATER)
                {
                    if(p->get_direction() == "left") mov_list[0]->set_x(mov_list[0]->get_x() - p->get_speed());
                    else mov_list[0]->set_x(mov_list[0]->get_x() + p->get_speed());
                    gmov_list[0]->update(p->get_x(), p->get_y());
                    frog_on_log = 1;
                }
                i++;
            }
            for(int i = 0; i<4; i++)
            {
                if(check_collision(mov_list[0], lane_list[i], FINISH_TEXTURE_X))
                {
                   this->score += 5*difficult;
                   mov_list[0]->set_x(window.getSize().x/2);
                   mov_list[0]->set_y(height - height_per_lane + ((height_per_lane - FROG_TEXTURE_Y)/2));
                   mov_list[0]->move();
                   gmov_list[0]->update(mov_list[0]->get_x(), mov_list[0]->get_y());                 
                }
            }

            if(frog_on_log == 0 && mov_list[0]->get_y() <= height_per_lane*MIN_NUM_OF_WATER)
           {
                mov_list[0]->set_x(window.getSize().x/2);
                mov_list[0]->set_y(height - height_per_lane + ((height_per_lane - FROG_TEXTURE_Y)/2));
                gmov_list[0]->update(mov_list[0]->get_x(), mov_list[0]->get_y());
                lives -= 1;
            }

            i = 0;

            for(const auto p : mov_list)
            {
                p->move();
                if(dir!="null" && p->get_direction()=="null")
                {
                    p->set_direction(dir);
                    p->move();
                    p->set_direction("null");
                    dir = "null";
                }
                gmov_list[i]->update(p->get_x(), p->get_y());
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
            tekst.setString(std::to_string(lives));
            score.setString(std::to_string(get_score()));
            window.draw(tekst);
            window.draw(score);
            window.display();
            sf::sleep(sf::milliseconds(100));
    }
    del_gmov_list();
    del_glane_list();
    del_mov_list();
    del_lane_list();

}
