#include "characters/slave.hpp"

const char* Slave::type = "Slave";
const bool Slave::good = GameCharacter::register_class<Slave>(Slave::type);

Slave::Slave(salmon::ActorRef actor, GameScene* scene) : GameCharacter(actor, scene) {}

void Slave::init() {
    // Setup member vars here | example: put(m_speed, "m_speed");
    
}

void Slave::update() {
    // Add character logic here
    
}
