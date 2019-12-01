#include "characters/tower.hpp"

#include <cmath>
#include "core/game_scene.hpp"
#include "characters/projectile.hpp"

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
            std::vector<GameCharacter*> enemies = m_scene->get_characters_by_type("SmallEnemy");
            if(m_current_cooldown <= 0.001) {
                for(GameCharacter* c : enemies) {
                    float x_delta = c->get_x_center() - get_x_center();
                    float y_delta = c->get_y_center() - get_y_center();
                    float magnitude = std::sqrt(x_delta * x_delta + y_delta * y_delta);
                    if(magnitude < firing_distance) {
                        Projectile* p = static_cast<Projectile*>(m_scene->add_character("Projectile","Characters","GeneratedProjectile"));
                        p->set_target(c);
                        p->move(get_x_center(), get_y_center(),true);
                        m_current_cooldown = cooldown;
                        break;
                    }
                }
            }
            else {m_current_cooldown -= m_scene->get_delta_time();}

            break;
        }
    }
}
