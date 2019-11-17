#include "scenes/template.hpp"

const bool Template::good = GameScene::register_class<Template>("Template");

Template::Template(salmon::MapRef map, SceneManager* scene_manager) :
    GameScene(map,scene_manager) {}

void Template::init() {
    // Initializes all characters in scene
    GameScene::init();
    // Setup member vars here | example: put(m_speed, "m_speed");

}

void Template::update() {
    // Add scene logic here
    
    // Calls update on all characters in scene
    GameScene::update();
}
