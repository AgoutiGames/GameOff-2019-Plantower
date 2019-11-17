#include "game_scene.hpp"

#include <iostream>

#include "gameinfo.hpp"
#include "data_block_ref.hpp"
#include "core/scene_manager.hpp"

#include "scenes/environment.hpp"

GameScene::GameScene(salmon::MapRef map, SceneManager* scene_manager)
: salmon::MapRef(map), m_scene_manager{scene_manager} {}

void GameScene::init() {
    std::vector<salmon::ActorRef> actors = get_actors();
    for(salmon::ActorRef a : actors) {
        m_characters.emplace_back(GameCharacter::parse_character(a, this));
        if(m_characters.back() == nullptr) {
            m_characters.pop_back();
        }
        else {
            m_characters.back()->init();
        }
    }
}

void GameScene::update() {
    if(!m_kill_characters.empty()) {
        for(GameCharacter* to_kill : m_kill_characters) {
            for(auto it = m_characters.begin(); it != m_characters.end(); it++) {
                if((*it).get() == to_kill) {
                    // Maybe hide the Actor or some other stuff
                    m_characters.erase(it);
                    break;
                }
            }
        }
    }
    m_kill_characters.clear();
    for(auto& c : m_characters) {c->update();}
}

bool GameScene::put(bool& var, std::string name) {
    salmon::DataBlockRef data = get_data();
    if(data.check_val_bool(name)) {var = data.get_val_bool(name);}
    else {return false;}
    return true;
}
bool GameScene::put(int& var, std::string name) {
    salmon::DataBlockRef data = get_data();
    if(data.check_val_int(name)) {var = data.get_val_int(name);}
    else {return false;}
    return true;
}
bool GameScene::put(float& var, std::string name) {
    salmon::DataBlockRef data = get_data();
    if(data.check_val_float(name)) {var = data.get_val_float(name);}
    else {return false;}
    return true;
}
bool GameScene::put(std::string& var, std::string name) {
    salmon::DataBlockRef data = get_data();
    if(data.check_val_string(name)) {var = data.get_val_string(name);}
    else {return false;}
    return true;
}

GameScene* GameScene::parse_scene(salmon::MapRef map, SceneManager* scene_manager) {
    std::string type = map.get_data().get_val_string("type");
    if(get_dict().find(type) == get_dict().end()) {
        std::cerr << "Unknown Game Scene type: " << type << " supplied!\n";
        return nullptr;
    }
    else {
        return get_dict().at(type)->create(map, scene_manager);
    }
}

salmon::InputCacheRef GameScene::get_input_cache() {
    return m_scene_manager->get_game().get_input_cache();
}

std::map<std::string, GameScene*>& GameScene::get_dict() {
    static std::map<std::string, GameScene*> scene_dict;
    return scene_dict;
}

GameCharacter& GameScene::get_character_by_name(std::string name) {}
GameCharacter& GameScene::get_character_by_template_type(std::string template_type) {}
GameCharacter& GameScene::get_character_by_attribute(std::string name, bool attribute) {}
GameCharacter& GameScene::get_character_by_attribute(std::string name, int attribute) {}
GameCharacter& GameScene::get_character_by_attribute(std::string name, float attribute) {}
GameCharacter& GameScene::get_character_by_attribute(std::string name, std::string attribute) {}

std::vector<GameCharacter*> GameScene::get_characters_by_name(std::string name) {
    std::vector<GameCharacter*> characters;
}
std::vector<GameCharacter*> GameScene::get_characters_by_template_type(std::string template_type) {}
std::vector<GameCharacter*> GameScene::get_characters_by_attribute(std::string name, bool attribute) {}
std::vector<GameCharacter*> GameScene::get_characters_by_attribute(std::string name, int attribute) {}
std::vector<GameCharacter*> GameScene::get_characters_by_attribute(std::string name, float attribute) {}
std::vector<GameCharacter*> GameScene::get_characters_by_attribute(std::string name, std::string attribute) {}
