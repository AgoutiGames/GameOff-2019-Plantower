#include "game_character.hpp"

#include <iostream>

#include "player.hpp"
#include "game_scene.hpp"

GameCharacter::GameCharacter(salmon::ActorRef actor, GameScene* scene) : salmon::ActorRef(actor), m_scene{scene} {}

bool GameCharacter::put(bool& var, std::string name) {
    salmon::DataBlockRef data = get_data();
    if(data.check_val_bool(name)) {var = data.get_val_bool(name);}
    else {return false;}
    return true;
}
bool GameCharacter::put(int& var, std::string name) {
    salmon::DataBlockRef data = get_data();
    if(data.check_val_int(name)) {var = data.get_val_int(name);}
    else {return false;}
    return true;
}
bool GameCharacter::put(float& var, std::string name) {
    salmon::DataBlockRef data = get_data();
    if(data.check_val_float(name)) {var = data.get_val_float(name);}
    else {return false;}
    return true;
}
bool GameCharacter::put(std::string& var, std::string name) {
    salmon::DataBlockRef data = get_data();
    if(data.check_val_string(name)) {var = data.get_val_string(name);}
    else {return false;}
    return true;
}

GameCharacter* GameCharacter::parse_character(salmon::ActorRef actor, GameScene* scene) {
    std::string type = actor.get_data().get_val_string("type");
    if(type == "Player") {
        return new Player(actor, scene);
    }
    else if(type == "SmallEnemy") {
        return nullptr;
    }
    else {
        std::cerr << "Unknown Game Character type: " << type << " supplied!\n";
        return nullptr;
    }
}
