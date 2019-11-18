#include "scenes/environment.hpp"

#include "core/scene_manager.hpp"

#include "characters/player.hpp"

const char* Environment::type = "Environment";
const bool Environment::good = GameScene::register_class<Environment>(Environment::type);

Environment::Environment(salmon::MapRef map, SceneManager* scene_manager) :
    GameScene(map,scene_manager) {}

void Environment::init() {GameScene::init();}

void Environment::update() {
    salmon::InputCacheRef input = get_input_cache();
    if(input.just_pressed("Escape")) {
        m_scene_manager->shutdown();
    }

    Player* p = get_character<Player>();
    p->move(1,0);

    GameScene::update();
}
