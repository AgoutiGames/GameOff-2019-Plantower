#include "game_scene.hpp"

#include <iostream>

#include "data_block_ref.hpp"

GameScene::GameScene(salmon::MapRef map, salmon::GameInfo* game) : salmon::MapRef(map), m_game{game} {}

void GameScene::init() {
    std::vector<salmon::ActorRef> actors = get_actors();
    for(salmon::ActorRef a : actors) {
        m_characters.emplace_back(GameCharacter::parse_character(a, this));
        m_characters.back()->init();
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

GameScene* GameScene::parse_scene(salmon::MapRef map, salmon::GameInfo* game) {
    std::string type = map.get_data().get_val_string("type");
    if(type == "Menu") {
        return nullptr;
    }
    else if(type == "BattleStage") {
        return nullptr;
    }
    else {
        std::cerr << "Unknown Game Scene type: " << type << " supplied!\n";
        return nullptr;
    }
}
