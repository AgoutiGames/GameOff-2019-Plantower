#include "character_components/can_walk.hpp"

#include "core/game_scene.hpp"

bool CanWalk::walk(salmon::Direction dir, float walk_speed, float animation_speed) {
    if(dir == salmon::Direction::none || dir == salmon::Direction::invalid) {return false;}
    animate(salmon::AnimationType::walk, dir, animation_speed);
    if(dir == salmon::Direction::current) {dir = get_direction();}
    float s = walk_speed * m_scene->get_delta_time();
    switch(dir) {
        case salmon::Direction::up : {
            return move(0,-1*s);
        }
        case salmon::Direction::up_left : {
            return move(-0.7*s,-0.7*s);
        }
        case salmon::Direction::up_right : {
            return move(0.7*s,-0.7*s);
        }
        case salmon::Direction::left : {
            return move(-1*s,0);
        }
        case salmon::Direction::right : {
            return move(1*s,0);
        }
        case salmon::Direction::down : {
            return move(0,1*s);
        }
        case salmon::Direction::down_left : {
            return move(-0.7*s,0.7*s);
        }
        case salmon::Direction::down_right : {
            return move(0.7*s,0.7*s);
        }
        default : {
            return false;
        }
    }
}
