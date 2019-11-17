#include "characters/template.hpp"

const bool Template::good = GameCharacter::register_class<Template>("Template");

Template::Template(salmon::ActorRef actor, GameScene* scene) : GameCharacter(actor, scene) {}

void Template::init() {
    // Setup member vars here | example: put(m_speed, "m_speed");
    
}

void Template::update() {
    // Add character logic here
    
}
