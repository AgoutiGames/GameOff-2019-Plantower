#include "characters/player.hpp"

#include "core/game_scene.hpp"

const char* Player::type = "Player";
const bool Player::good = GameCharacter::register_class<Player>(Player::type);

Player::Player(salmon::ActorRef actor, GameScene* scene) : GameCharacter(actor, scene) {}

void Player::init() {
    put(m_base_speed, "m_base_speed");
}

void Player::update() {
    const salmon::InputCacheRef input = m_scene->get_input_cache();
    float x_dir = 0;
    float y_dir = 0;
    if(input.is_down(m_up_key) || input.is_down(m_up_key_alt)) {
        y_dir -= 1;
    }
    if(input.is_down(m_down_key) || input.is_down(m_down_key_alt)) {
        y_dir += 1;
    }
    if(input.is_down(m_left_key) || input.is_down(m_left_key_alt)) {
        x_dir -= 1;
    }
    if(input.is_down(m_right_key) || input.is_down(m_right_key_alt)) {
        x_dir += 1;
    }

    // Diagonal walk check
    if(x_dir && y_dir) {x_dir /= 2; y_dir /= 2;}

    float delta = m_scene->get_delta_time();

    move(x_dir * m_base_speed * delta, y_dir * m_base_speed * delta);
}
