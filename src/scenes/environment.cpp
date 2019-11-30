#include "scenes/environment.hpp"

#include "core/scene_manager.hpp"

#include "characters/player.hpp"

const char* Environment::type = "Environment";
const bool Environment::good = GameScene::register_class<Environment>(Environment::type);

Environment::Environment(salmon::MapRef map, SceneManager* scene_manager) :
    GameScene(map,scene_manager) {}

void Environment::init() {
    // Tested some stuff
    //m_scene_manager->set_fullscreen(true);
    //m_scene_manager->set_game_resolution(1920,1080);
    GameScene::init();
}

void Environment::update() {
    salmon::InputCacheRef input = get_input_cache();
    if(input.just_pressed("Escape")) {
        m_scene_manager->next_scene("menu.tmx");
    }
/*
    salmon::CameraRef cam = get_camera();
    if(input.is_down("d")) {
        cam.set_x(cam.get_x()+10);
    }
    if(input.is_down("s")) {
        cam.set_y(cam.get_y()+10);
    }
    if(input.is_down("a")) {
        cam.set_x(cam.get_x()-10);
    }
    if(input.is_down("w")) {
        cam.set_y(cam.get_y()-10);
    }
    cam.update();
*/
    /*
    Player* p = get_character<Player>();
    if(p) {p->move(1,0);}

    if(input.just_pressed("p"))  {
        GameCharacter* p = get_character_by_name("Player");
        remove_character(p);
    }*/

    GameScene::update();
}
