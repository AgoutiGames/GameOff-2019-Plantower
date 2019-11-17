#include "scenes/environment.hpp"

#include "core/scene_manager.hpp"

Environment::Environment(salmon::MapRef map, SceneManager* scene_manager) :
    GameScene(map,scene_manager) {}

void Environment::init() {GameScene::init();}
void Environment::update() {
    salmon::InputCacheRef input = get_input_cache();
    if(input.just_pressed("Escape")) {
        m_scene_manager->shutdown();
    }
    GameScene::update();
}
