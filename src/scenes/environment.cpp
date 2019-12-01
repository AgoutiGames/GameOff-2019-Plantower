#include "scenes/environment.hpp"

#include <string>
#include <sstream>
#include <cstdlib>
#include <time.h>

#include "core/scene_manager.hpp"
#include "characters/player.hpp"

const char* Environment::type = "Environment";
const bool Environment::good = GameScene::register_class<Environment>(Environment::type);

float Environment::enemy_cooldown = 1;

Environment::Environment(salmon::MapRef map, SceneManager* scene_manager) :
    GameScene(map,scene_manager) {}

void Environment::init() {
    m_scene_manager->set_window_size(960,540);
    m_scene_manager->set_game_resolution(1920 * 1.2, 1080 * 1.2);
    m_scene_manager->set_fullscreen(m_fullscreen);

    GameScene::init();
    std::string enemy_name = "SmallEnemy";
    for(int i = 1; i <= 9; i++) {
        std::stringstream name;
        name << enemy_name << i;
        GameCharacter* e = get_character_by_name(name.str());
        e->suspend();
        e->set_hidden(true);
        m_small_enemies.push_back(e);
    }
    srand(time(NULL));
}

void Environment::update() {
    salmon::InputCacheRef input = get_input_cache();
    if(input.just_pressed("Escape")) {
        m_scene_manager->next_scene("menu.tmx");
    }
    if(input.just_pressed("f")) {
        if(m_fullscreen) {
            m_fullscreen = false;
        }
        else {m_fullscreen = true;}
        m_scene_manager->set_fullscreen(m_fullscreen);
    }
    if(m_current_enemy_cooldown <= 0) {
        int chosen_enemy = rand() % m_small_enemies.size();
        GameCharacter* c = m_small_enemies.at(chosen_enemy);
        c = add_character(c, c->get_layer(),c->get_name() + "Generated");
        c->set_hidden(false);
        m_current_enemy_cooldown = enemy_cooldown;
    }
    else {
        m_current_enemy_cooldown -= get_delta_time();
    }
    GameScene::update();
}
