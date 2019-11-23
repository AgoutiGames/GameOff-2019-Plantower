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
        add_character(a);
    }
    trigger_add();
}

GameCharacter* GameScene::add_character(std::string actor_template_name, std::string layer_name, std::string actor_name) {
    salmon::ActorRef actor = add_actor(actor_template_name, layer_name, actor_name);
    if(!actor.good()) {return nullptr;}
    else {
        return add_character(actor);
    }
}
GameCharacter* GameScene::add_character(salmon::ActorRef actor) {
    if(!actor.good()) {return nullptr;}
    GameCharacter* character = GameCharacter::parse_character(actor, this);
    if(character == nullptr) {return nullptr;}
    else {
        m_add_characters.push_back(character);
        return character;
    }
}
GameCharacter* GameScene::add_character(GameCharacter* character, std::string layer_name, std::string actor_name) {
    // First duplicate the actor which is wrapped in the Character
    salmon::ActorRef actor = add_actor(*static_cast<salmon::ActorRef*>(character),layer_name,actor_name);
    if(!actor.good()) {return nullptr;}
    return add_character(actor);
}

bool GameScene::remove_character_internal(GameCharacter* game_character) {
    for(auto it = m_characters.begin(); it != m_characters.end(); it++) {
        if((*it).get() == game_character) {
            // Cast child GameCharacter to parent ActorRef
            salmon::ActorRef* to_kill_actor = static_cast<salmon::ActorRef*>(game_character);
            // After this call the pointer to the actor inside the GameCharacter is invalidated
            remove_actor(*to_kill_actor);
            // Therefore we also have to erase it here
            m_characters.erase(it);
            return true;
        }
    }
    return false;
}

void GameScene::update() {
    trigger_add();
    trigger_kill();
    for(auto& c : m_characters) {c->update();}
}

void GameScene::remove_character(GameCharacter* game_character) {
    if(game_character == nullptr) {
        std::cerr << "Character to remove is a null pointer!\n";
    }
    else {
        m_kill_characters.push_back(game_character);
    }
}

void GameScene::trigger_kill() {
    if(!m_kill_characters.empty()) {
        for(GameCharacter* to_kill : m_kill_characters) {
            if(!remove_character_internal(to_kill)) {
                std::cerr << "Failed to remove character: \"" << to_kill->get_name() << "\"\n";
            }
        }
        m_kill_characters.clear();
    }
}

void GameScene::trigger_add() {
    if(!m_add_characters.empty()) {
        for(GameCharacter* to_add : m_add_characters) {
            m_characters.emplace_back(to_add);
            to_add->init();
        }
        m_add_characters.clear();
    }
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

salmon::AudioManagerRef GameScene::get_audio_manager() {
    return m_scene_manager->get_game().get_audio_manager();
}

std::map<std::string, GameScene*>& GameScene::get_dict() {
    static std::map<std::string, GameScene*> scene_dict;
    return scene_dict;
}

GameCharacter* GameScene::get_character_by_name(std::string name) {
    std::vector<GameCharacter*> characters = get_characters_by_name(name);
    if(characters.empty()) {return nullptr;}
    else {return characters.front();}
}
GameCharacter* GameScene::get_character_by_id(unsigned id) {
    for(auto& c : m_characters) {
        if(c->get_id() == id) {return c.get();}
    }
    return nullptr;
}
GameCharacter* GameScene::get_character_by_template_type(std::string template_type) {
    std::vector<GameCharacter*> characters = get_characters_by_template_type(template_type);
    if(characters.empty()) {return nullptr;}
    else {return characters.front();}
}
GameCharacter* GameScene::get_character_by_attribute(std::string name, bool attribute) {
    std::vector<GameCharacter*> characters = get_characters_by_attribute(name,attribute);
    if(characters.empty()) {return nullptr;}
    else {return characters.front();}
}
GameCharacter* GameScene::get_character_by_attribute(std::string name, int attribute) {
    std::vector<GameCharacter*> characters = get_characters_by_attribute(name,attribute);
    if(characters.empty()) {return nullptr;}
    else {return characters.front();}
}
GameCharacter* GameScene::get_character_by_attribute(std::string name, float attribute) {
    std::vector<GameCharacter*> characters = get_characters_by_attribute(name,attribute);
    if(characters.empty()) {return nullptr;}
    else {return characters.front();}
}
GameCharacter* GameScene::get_character_by_attribute(std::string name, const char* attribute) {
    std::vector<GameCharacter*> characters = get_characters_by_attribute(name,attribute);
    if(characters.empty()) {return nullptr;}
    else {return characters.front();}
}
GameCharacter* GameScene::get_character_by_attribute(std::string name, std::string attribute) {
    std::vector<GameCharacter*> characters = get_characters_by_attribute(name,attribute);
    if(characters.empty()) {return nullptr;}
    else {return characters.front();}
}

std::vector<GameCharacter*> GameScene::get_characters() {
    std::vector<GameCharacter*> characters;
    for(auto& c : m_characters) {
        characters.push_back(c.get());
    }
    return characters;
}

std::vector<GameCharacter*> GameScene::get_characters_by_name(std::string name) {
    std::vector<GameCharacter*> characters;
    for(auto& c : m_characters) {
        if(c->get_name() == name) {characters.push_back(c.get());}
    }
    return characters;
}
std::vector<GameCharacter*> GameScene::get_characters_by_layer(std::string name) {
    std::vector<GameCharacter*> characters;
    for(auto& c : m_characters) {
        if(c->get_layer() == name) {characters.push_back(c.get());}
    }
    return characters;
}
std::vector<GameCharacter*> GameScene::get_characters_by_template_type(std::string template_type) {
    std::vector<GameCharacter*> characters;
    for(auto& c : m_characters) {
        if(c->get_type() == template_type) {characters.push_back(c.get());}
    }
    return characters;
}
std::vector<GameCharacter*> GameScene::get_characters_by_attribute(std::string name, bool attribute) {
    std::vector<GameCharacter*> characters;
    for(auto& c : m_characters) {
        salmon::DataBlockRef data = c->get_data();
        if(data.check_val_bool(name) && data.get_val_bool(name) == attribute) {characters.push_back(c.get());}
    }
    return characters;
}
std::vector<GameCharacter*> GameScene::get_characters_by_attribute(std::string name, int attribute) {
    std::vector<GameCharacter*> characters;
    for(auto& c : m_characters) {
        salmon::DataBlockRef data = c->get_data();
        if(data.check_val_int(name) && data.get_val_int(name) == attribute) {characters.push_back(c.get());}
    }
    return characters;
}
std::vector<GameCharacter*> GameScene::get_characters_by_attribute(std::string name, float attribute) {
    std::vector<GameCharacter*> characters;
    for(auto& c : m_characters) {
        salmon::DataBlockRef data = c->get_data();
        if(data.check_val_float(name) && data.get_val_float(name) == attribute) {characters.push_back(c.get());}
    }
    return characters;
}
std::vector<GameCharacter*> GameScene::get_characters_by_attribute(std::string name, const char* attribute) {
    std::vector<GameCharacter*> characters;
    for(auto& c : m_characters) {
        salmon::DataBlockRef data = c->get_data();
        if(data.check_val_string(name) && data.get_val_string(name) == attribute) {characters.push_back(c.get());}
    }
    return characters;
}
std::vector<GameCharacter*> GameScene::get_characters_by_attribute(std::string name, std::string attribute) {
    std::vector<GameCharacter*> characters;
    for(auto& c : m_characters) {
        salmon::DataBlockRef data = c->get_data();
        if(data.check_val_string(name) && data.get_val_string(name) == attribute) {characters.push_back(c.get());}
    }
    return characters;
}

std::vector<GameCharacter*> GameScene::filter_characters_by_name(std::vector<GameCharacter*> characters, std::string name) {
    std::vector<GameCharacter*> ncharacters;
    for(auto c : characters) {
        if(c->get_name() == name) {characters.push_back(c);}
    }
    return ncharacters;
}
std::vector<GameCharacter*> GameScene::filter_characters_by_layer(std::vector<GameCharacter*> characters, std::string name) {
    std::vector<GameCharacter*> ncharacters;
    for(auto c : characters) {
        if(c->get_layer() == name) {characters.push_back(c);}
    }
    return ncharacters;
}
std::vector<GameCharacter*> GameScene::filter_characters_by_template_type(std::vector<GameCharacter*> characters, std::string template_type) {
    std::vector<GameCharacter*> ncharacters;
    for(auto c : characters) {
        if(c->get_type() == template_type) {characters.push_back(c);}
    }
    return ncharacters;
}
std::vector<GameCharacter*> GameScene::filter_characters_by_attribute(std::vector<GameCharacter*> characters, std::string name, bool attribute) {
    std::vector<GameCharacter*> ncharacters;
    for(auto c : characters) {
        salmon::DataBlockRef data = c->get_data();
        if(data.check_val_bool(name) && data.get_val_bool(name) == attribute) {characters.push_back(c);}
    }
    return ncharacters;
}
std::vector<GameCharacter*> GameScene::filter_characters_by_attribute(std::vector<GameCharacter*> characters, std::string name, int attribute) {
    std::vector<GameCharacter*> ncharacters;
    for(auto c : characters) {
        salmon::DataBlockRef data = c->get_data();
        if(data.check_val_int(name) && data.get_val_int(name) == attribute) {characters.push_back(c);}
    }
    return ncharacters;
}
std::vector<GameCharacter*> GameScene::filter_characters_by_attribute(std::vector<GameCharacter*> characters, std::string name, float attribute) {
    std::vector<GameCharacter*> ncharacters;
    for(auto c : characters) {
        salmon::DataBlockRef data = c->get_data();
        if(data.check_val_float(name) && data.get_val_float(name) == attribute) {characters.push_back(c);}
    }
    return ncharacters;
}
std::vector<GameCharacter*> GameScene::filter_characters_by_attribute(std::vector<GameCharacter*> characters, std::string name, const char* attribute) {
    std::vector<GameCharacter*> ncharacters;
    for(auto c : characters) {
        salmon::DataBlockRef data = c->get_data();
        if(data.check_val_string(name) && data.get_val_string(name) == attribute) {characters.push_back(c);}
    }
    return ncharacters;
}
std::vector<GameCharacter*> GameScene::filter_characters_by_attribute(std::vector<GameCharacter*> characters, std::string name, std::string attribute) {
    std::vector<GameCharacter*> ncharacters;
    for(auto c : characters) {
        salmon::DataBlockRef data = c->get_data();
        if(data.check_val_string(name) && data.get_val_string(name) == attribute) {characters.push_back(c);}
    }
    return ncharacters;
}
