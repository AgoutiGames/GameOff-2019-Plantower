#include "characters/projectile.hpp"

#include <cmath>

#include "core/game_scene.hpp"

const char* Projectile::type = "Projectile";
const bool Projectile::good = GameCharacter::register_class<Projectile>(Projectile::type);

Projectile::Projectile(salmon::ActorRef actor, GameScene* scene) : GameCharacter(actor, scene) {}

void Projectile::init() {
    // Setup member vars here | example: put(m_speed, "m_speed");

}

void Projectile::update() {
    // Add character logic here
    animate();
    if(m_target != nullptr && m_scene->is_valid(m_target)) {
        float x_delta = m_target->get_x_center() - get_x_center();
        float y_delta = m_target->get_y_center() - get_y_center();
        float magnitude = std::sqrt(x_delta * x_delta + y_delta * y_delta);
        x_delta /= magnitude;
        y_delta /= magnitude;
        float delta = m_scene->get_delta_time();
        move(x_delta * m_speed * delta,y_delta * m_speed * delta);
    }
    else {
        m_scene->remove_character(this);
    }
    for(salmon::CollisionRef c : get_collisions()) {
        GameCharacter* other = nullptr;
        if(c.actor()) {
            other = m_scene->get_character_by_id(c.get_actor_id());
            if(other == nullptr) {continue;}
            if(other->type() != "SmallEnemy") {continue;}
            m_scene->remove_character(other);
            m_scene->remove_character(this);
            break;
        }
    }
    clear_collisions();
}

void Projectile::set_target(GameCharacter* character) {
    m_target = character;
}
