#include "characters/tower.hpp"

const char* Tower::type = "Tower";
const bool Tower::good = GameCharacter::register_class<Tower>(Tower::type);

Tower::Tower(salmon::ActorRef actor, GameScene* scene) : GameCharacter(actor, scene) {}

void Tower::init() {
    // Setup member vars here | example: put(m_speed, "m_speed");

}

void Tower::power_up() {
    if(m_state == inactive) {m_state = powering_up;}
}

void Tower::update() {
    // Add character logic here
    switch(m_state) {
        case inactive : {

            break;
        }
        case powering_up : {
            if(animate_trigger(salmon::AnimationType::walk, salmon::Direction::none) == salmon::AnimSignal::wrap) {
                set_animation(salmon::AnimationType::idle, salmon::Direction::none, 1);
                m_state = active;
            }
            break;
        }
        case active : {

            break;
        }
    }
}
