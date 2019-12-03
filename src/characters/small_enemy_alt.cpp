#include "characters/small_enemy_alt.hpp"

#include <string>
#include <sstream>
#include <iostream>
#include <cmath>

#include "core/game_scene.hpp"

const char* SmallEnemyAlt::type = "SmallEnemyAlt";
const bool SmallEnemyAlt::good = GameCharacter::register_class<SmallEnemyAlt>(SmallEnemyAlt::type);

SmallEnemyAlt::SmallEnemyAlt(salmon::ActorRef actor, GameScene* scene) :GameCharacter(actor,scene), SmallEnemy(actor, scene) {}

void SmallEnemyAlt::init() {
    // Setup member vars here | example: put(m_speed, "m_speed");
    SmallEnemy::init();
    if(!init_shadow("SHA_Goat", "Shadows",-64,64)) {
        std::cerr << "Initializing shadow failed\n";
    }
}

void SmallEnemyAlt::update() {
    // Add character logic here
    SmallEnemy::update();
    update_shadow();
}
