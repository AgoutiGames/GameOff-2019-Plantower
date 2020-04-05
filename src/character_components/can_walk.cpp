#include "character_components/can_walk.hpp"

#include "core/game_scene.hpp"

bool CanWalk::walk(salmon::Direction dir, float walk_speed, float animation_speed) {
    if(dir == salmon::Direction::none || dir == salmon::Direction::invalid) {return false;}
    animate(salmon::AnimationType::walk, dir, animation_speed);
    if(dir == salmon::Direction::current) {dir = get_direction();}
    float s = walk_speed * m_scene->get_delta_time();
    switch(dir) {
        case salmon::Direction::up : {
            return move_relative(0,-1*s,salmon::Collidees::tile, {salmon::DEFAULT_HITBOX},{salmon::DEFAULT_HITBOX}, false);
        }
        case salmon::Direction::up_left : {
            return move_relative(-0.7*s,-0.7*s,salmon::Collidees::tile, {salmon::DEFAULT_HITBOX},{salmon::DEFAULT_HITBOX}, false);
        }
        case salmon::Direction::up_right : {
            return move_relative(0.7*s,-0.7*s,salmon::Collidees::tile, {salmon::DEFAULT_HITBOX},{salmon::DEFAULT_HITBOX}, false);
        }
        case salmon::Direction::left : {
            return move_relative(-1*s,0,salmon::Collidees::tile, {salmon::DEFAULT_HITBOX},{salmon::DEFAULT_HITBOX}, false);
        }
        case salmon::Direction::right : {
            return move_relative(1*s,0,salmon::Collidees::tile, {salmon::DEFAULT_HITBOX},{salmon::DEFAULT_HITBOX}, false);
        }
        case salmon::Direction::down : {
            return move_relative(0,1*s,salmon::Collidees::tile, {salmon::DEFAULT_HITBOX},{salmon::DEFAULT_HITBOX}, false);
        }
        case salmon::Direction::down_left : {
            return move_relative(-0.7*s,0.7*s,salmon::Collidees::tile, {salmon::DEFAULT_HITBOX},{salmon::DEFAULT_HITBOX}, false);
        }
        case salmon::Direction::down_right : {
            return move_relative(0.7*s,0.7*s,salmon::Collidees::tile, {salmon::DEFAULT_HITBOX},{salmon::DEFAULT_HITBOX}, false);
        }
        default : {
            return false;
        }
    }
}
