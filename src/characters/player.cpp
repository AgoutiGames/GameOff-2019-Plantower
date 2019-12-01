#include "characters/player.hpp"

#include <iostream>

#include "core/game_scene.hpp"

#include "text_ref.hpp"
#include "characters/tower.hpp"

#include "characters/small_enemy_alt.hpp"

const char* Player::type = "Player";
const bool Player::good = GameCharacter::register_class<Player>(Player::type);

Player::Player(salmon::ActorRef actor, GameScene* scene) : GameCharacter(actor, scene) {}

void Player::init() {
    put(m_base_speed, "m_base_speed");
    //register_collisions(false);
    m_scene->get_camera().bind_actor(*this);
    if(!init_shadow("SHA_Deer", "Shadows",-64,64)) {
        std::cerr << "Initializing shadow failed\n";
    }
}

void Player::update() {
    const salmon::InputCacheRef input = m_scene->get_input_cache();

    bool moved = true;
    bool collided = false;

    if(!m_attack) {
        if(input.is_down(m_up_key) || input.is_down(m_up_key_alt)) {
            if(input.is_down(m_down_key) || input.is_down(m_down_key_alt)) {
                moved = false;
            }
            else if(input.is_down(m_left_key) || input.is_down(m_left_key_alt)) {
                collided = !walk(salmon::Direction::up_left,m_base_speed);
            }
            else if(input.is_down(m_right_key) || input.is_down(m_right_key_alt)) {
                collided = !walk(salmon::Direction::up_right,m_base_speed);
            }
            else {
                collided = !walk(salmon::Direction::up,m_base_speed);
            }
        }
        else if(input.is_down(m_down_key) || input.is_down(m_down_key_alt)) {
            if(input.is_down(m_up_key) || input.is_down(m_up_key_alt)) {
                moved = false;
            }
            else if(input.is_down(m_left_key) || input.is_down(m_left_key_alt)) {
                collided = !walk(salmon::Direction::down_left,m_base_speed);
            }
            else if(input.is_down(m_right_key) || input.is_down(m_right_key_alt)) {
                collided = !walk(salmon::Direction::down_right,m_base_speed);
            }
            else {
                collided = !walk(salmon::Direction::down,m_base_speed);
            }
        }
        else if(input.is_down(m_left_key) || input.is_down(m_left_key_alt)) {
            collided = !walk(salmon::Direction::left,m_base_speed);
        }
        else if(input.is_down(m_right_key) || input.is_down(m_right_key_alt)) {
            collided = !walk(salmon::Direction::right,m_base_speed);
        }
        else {moved = false;}

        if(!moved) {animate(salmon::AnimationType::idle);}
        (void) collided;

        if(input.just_pressed("Space")) {
            m_attack = true;
        }

        for(salmon::CollisionRef c : get_collisions()) {
            //std::cout << "Me: " << c.my_hitbox() << " You: " << c.other_hitbox() << "\n";
            if(c.my_hitbox() == "ActivateRange" && c.other_hitbox() == "ActivateRange") {
                if(input.just_pressed("e")) {
                    GameCharacter* character = m_scene->get_character_by_id(c.get_actor_id());
                    Tower* tower = static_cast<Tower*>(character);
                    tower->power_up();
                }
            }
        }
    }
    else {
        salmon::AnimSignal sig = animate_trigger(salmon::AnimationType::custom1);
        if(sig == salmon::AnimSignal::wrap || sig == salmon::AnimSignal::missing) {
            m_attack = false;
            animate(salmon::AnimationType::idle);
        }
        for(salmon::CollisionRef c : get_collisions()) {
            //std::cout << "Me: " << c.my_hitbox() << " You: " << c.other_hitbox() << "\n";
            if(c.my_hitbox() == "ActivateRange" && c.actor()) {
                GameCharacter* character = m_scene->get_character_by_id(c.get_actor_id());
                if(character == nullptr || (character->type() != "SmallEnemy" && character->type() != "SmallEnemyAlt")) {continue;}
                m_scene->remove_character(character);
            }
        }
    }
    clear_collisions();

    update_shadow();
}
